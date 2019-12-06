
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

	d1 = sqrt((wall.start.x - data->p.pos.x) * (wall.start.x - data->p.pos.x)
		+ (wall.start.y - data->p.pos.y) * (wall.start.y - data->p.pos.y));
	d2 = sqrt((wall.end.x - data->p.pos.x) * (wall.end.x - data->p.pos.x)
		+ (wall.end.y - data->p.pos.y) * (wall.end.y - data->p.pos.y));
	return (d1 < d2 ? d1 : d2);
}

void	get_wall_border_pix(int *begin, int *end, double a1, double a2)
{
	double	pithree;

	pithree = M_PI / 3;

	if (a1 <= pithree)
		*begin = SCREEN_WIDTH / 2 - a1 * SCREEN_WIDTH / (2 * pithree) - 1;
	else
		*begin = SCREEN_WIDTH / 2 + (2 * M_PI - a1) * SCREEN_WIDTH / (2 * pithree) - 1;
	if (a2 <= pithree)
		*end = SCREEN_WIDTH / 2 - a2 * SCREEN_WIDTH / (2 * pithree);
	else
		*end = SCREEN_WIDTH / 2 + (2 * M_PI - a2) * SCREEN_WIDTH / (2 * pithree);
}

int		get_visible_wall_distance(t_data *data, t_wall wall, double angle,
																	int side)
{
	int	d1;
	int	d2;

	d1 = (wall.start.x - data->p.pos.x) * (wall.start.x - data->p.pos.x)
			+ (wall.start.y - data->p.pos.y) * (wall.start.y - data->p.pos.y);
	d2 = (wall.end.x - data->p.pos.x) * (wall.end.x - data->p.pos.x)
			+ (wall.end.y - data->p.pos.y) * (wall.end.y - data->p.pos.y);
	if (angle < M_PI / 3 || angle > 5 * M_PI / 3)
		return (side == 0 ? d1 : d2);
	if (angle < M_PI)
		return (side == 0 ? d1 * cos(angle - M_PI / 3) : d2 * cos(angle - M_PI / 3));
	else
		return (side == 0 ? d1 * cos(5 * M_PI / 3 - angle) : d2 * cos(5 * M_PI / 3 - angle));
}

void	adjust_angles(double *angle1, double *angle2)
{
	if (*angle1 > M_PI / 3 && *angle1 < M_PI)
		*angle1 = M_PI / 3;
	if (*angle1 < 5 * M_PI / 3 && *angle1 > M_PI)
		*angle1 = 5 * M_PI / 3;
	if (*angle2 > M_PI / 3 && *angle2 < M_PI)
		*angle2 = M_PI / 3;
	if (*angle2 < 5 * M_PI / 3 && *angle2 > M_PI)
		*angle2 = 5 * M_PI / 3;
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
	angle1 = two_pi_mod(data->p.angle - angle1);
	angle2 = two_pi_mod(data->p.angle - angle2);
	if ((angle1 < M_PI && angle2 < M_PI && angle1 < angle2)
			|| (angle1 > M_PI && angle2 > M_PI && angle1 < angle2)
			|| (angle1 > M_PI && angle2 < M_PI))
	{
		h_step = angle1;
		angle1 = angle2;
		angle2 = h_step;
	}
	//angle1 et angle2 sont les angles relatifs a data->p.angle
	//Si le mur prend pile tout l'ecran, on aura angle1 == pi/3 et angle2 == 5*pi/3
	if (!(angle1 <= pithree || angle2 <= pithree
			|| angle1 >= 5 * pithree || angle2 >= 5 * pithree))
		return ; // OUT OF FOV
	draw_2dwall(data, wall, 0x999999);
	d1 = get_visible_wall_distance(data, wall, angle1, 0);
	d2 = get_visible_wall_distance(data, wall, angle2, 1);
	h1 = 277 * 64 * 1 / sqrt(d1);
	h2 = 277 * 64 * 1 / sqrt(d2);
	//h2 = SCREEN_HEIGHT * SCREEN_HEIGHT * 5 / d2;		
	adjust_angles(&angle1, &angle2);
	get_wall_border_pix(&begin, &end, angle1, angle2);
	h_step = ((double)h2 - (double)h1) / ((double)end - (double)begin);
/*	if (begin > end)
	{
	   i = end;
	   end = begin;
	   begin = i;
	   pithree = h1;
	   h1 = h2;
	   h2 = pithree;	   
	   h_step = -h_step;
	}*/
	ft_printf("%d, %d\n", begin, end);
	while (++begin < end)
	{
		if (begin >= SCREEN_WIDTH)
			break ;
		if (begin >= 0)
		{
			if (data->filled[begin])
				continue;
			data->filled[begin] = 1;
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
** TODO better explore_walls, needs to explore EVERY wall ONCE + IN RIGHT ORDER
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
