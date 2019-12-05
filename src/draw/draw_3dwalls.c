
#include "../../hdr/doom.h"

double		two_pi_mod(double angle)
{
	while (angle >= M_PI * 2)
		angle -= M_PI * 2;
	while (angle < 0)
		angle += M_PI * 2;
	return (angle);
}

int			is_wall_in_fov(t_data *data, t_wall wall)
{
	double	angle1;
	double	angle2;
	double	pithree;

	pithree = M_PI / 3;
	angle1 = atan2((wall.start.y - data->p.pos.y),
					(wall.start.x - data->p.pos.x));
	angle2 = atan2((wall.end.y - data->p.pos.y),
					(wall.end.x - data->p.pos.x));
	angle1 = two_pi_mod(angle1 + data->p.angle);
	angle2 = two_pi_mod(angle2 + data->p.angle);
	if (angle1 < pithree || angle2 < pithree
			|| angle1 > 5 * pithree || angle2 > 5 * pithree)
		return (1);
	return (0);
}

t_BSPNode	*get_player_pos(t_data *data, t_BSPNode *bsp)
{
	int		rpos;

	if (bsp->front == NULL && bsp->back == NULL)
		return (bsp);
	rpos = classifypoint(data->p.pos, bsp->wall);
	if (rpos == C_FRONT)
		return (get_player_pos(data, bsp->front));
	else
		return (get_player_pos(data, bsp->back));
}

int		found_a_zero(char *str)
{
	int	i;

	i = -1;
	while (++i < SCREEN_WIDTH)
		if (str[i] != 1)
			return (1);
	return (0);
}

int		player_dist_to_wall(t_wall wall, t_data *data)
{
	int	d1;
	int	d2;

	d1 = (wall.start.x - data->p.pos.x) * (wall.start.x - data->p.pos.x)
		+ (wall.start.y - data->p.pos.y) * (wall.start.y - data->p.pos.y);
	d2 = (wall.end.x - data->p.pos.x) * (wall.end.x - data->p.pos.x)
		+ (wall.end.y - data->p.pos.y) * (wall.end.y - data->p.pos.y);
	return (d1 < d2 ? d1 : d2);
}

void	draw_one_wall(t_data *data, t_wall wall)
{
	int	d1;
	int	d2;
	double	h1;
	double	h2;
	double	h_step;
	double	angle1;
	double	angle2;
	double	pithree;
	int		begin;
	int		end;
	int		i;
	int		col_end;

	pithree = M_PI / 3;
	angle1 = atan2((wall.start.y - data->p.pos.y),
					(wall.start.x - data->p.pos.x));
	angle2 = atan2((wall.end.y - data->p.pos.y),
					(wall.end.x - data->p.pos.x));
	angle1 = two_pi_mod(angle1 + data->p.angle);
	angle2 = two_pi_mod(angle2 + data->p.angle);
	if (!(angle1 < pithree || angle2 < pithree
			|| angle1 > 5 * pithree || angle2 > 5 * pithree))
		return ; // OUT OF FOV
	draw_2dwall(data, wall, 0x999999);
	d1 = (wall.start.x - data->p.pos.x) * (wall.start.x - data->p.pos.x)
		+ (wall.start.y - data->p.pos.y) * (wall.start.y - data->p.pos.y);
	d2 = (wall.end.x - data->p.pos.x) * (wall.end.x - data->p.pos.x)
		+ (wall.end.y - data->p.pos.y) * (wall.end.y - data->p.pos.y);
	h1 = 277 * 64 / sqrt(d1);
	h2 = 277 * 64 / sqrt(d2);
	//h2 = SCREEN_HEIGHT * SCREEN_HEIGHT * 5 / d2;		
	begin = SCREEN_WIDTH / 2 - angle1 * SCREEN_WIDTH / (2 * M_PI / 3) - 1;
	end = SCREEN_WIDTH / 2 + angle2 * SCREEN_WIDTH / (2 * M_PI / 3);
	h_step = ((double)h2 - (double)h1) / ((double)end - (double)begin);
	if (begin > end)
	{
	   i = end;
	   end = begin;
	   begin = i;
	   h_step = -h_step;
	}
	ft_printf("%d, %d\n", begin, end);
	while (++begin < end)
	{
		if (begin >= SCREEN_WIDTH)
			break ;
		if (begin >= 0)
		{
			i = SCREEN_HEIGHT / 2 - (int)h1 / 2 - 1;
			col_end = i + h1 + 1;
			if (i < -1)
			{
				i = -1;
				col_end = SCREEN_HEIGHT;
			}
			while (++i < col_end)
			{
				data->pixels[begin + i * SCREEN_WIDTH] = 0xff0000;
			}
		}
		h1 += h_step;
	}
}

/*
** TODO explore_walls, needs to explore EVERY wall ONCE + IN RIGHT ORDER
*/

void	explore_walls(t_BSPNode *explorer, t_data* data)
{
	if (!found_a_zero(data->filled))
		return ;
	if (explorer->front != NULL && explorer->back != NULL)
	{
		if (player_dist_to_wall(explorer->front->wall, data) <
				player_dist_to_wall(explorer->back->wall, data))
		{
			explore_walls(explorer->front, data);
			explore_walls(explorer->back, data);
		}
		else
		{
			explore_walls(explorer->back, data);
			explore_walls(explorer->front, data);
		}
	}
	else if (explorer->front != NULL && explorer->back == NULL)
		explore_walls(explorer->front, data);
	else if (explorer->front == NULL && explorer->back != NULL)
		explore_walls(explorer->back, data);
	draw_one_wall(data, explorer->wall);
}

void	draw_3d_walls(t_data *data, t_BSPNode *bsp)
{
	t_BSPNode	*explorer;

	explorer = get_player_pos(data, bsp);	
	if (explorer->parent == NULL)
	{
		ft_putendl("no first parent");
		return ;
	}
	explorer = bsp;//explorer->parent;
//	draw_one_wall(data, explorer->wall);
	explore_walls(explorer, data);
}
