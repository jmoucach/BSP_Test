/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2dwall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:25:28 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/09 16:22:36 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../hdr/doom.h"
/*
t_point	draw_node(t_data *data, int level, int width, t_point p)
{
	t_point	point;
	t_point	point2;
	int		color;

	if (level == 0)
		color = 0xffffff;
	if (level == 1)
		color = 0xff0000;
	if (level == 2)
		color = 0x00ff00;
	if (level == 3)
		color = 0x0000ff;
	if (level == 4)
		color = 0xff00ff;
	if (level == 5)
		color = 0xffff00;
	if (level == 6)
		color = 0x00ffff;
	if (level == 7)
		color = 0xAAAAAA;
	point.x = p.x - width * 15 * (7 - level);
	point.y = p.y + 30;
	point2.x = p.x + 5;
	point2.y = p.y + 5;
	p.x -= 5;
	p.y -= 5;
	draw_rect_to_sdl(p, point2, data, color);
	return (point);
}

void	draw_bin_tree(t_data *data, t_BSPNode *node, int level, t_point point)
{
	t_point	p;

	if (node->front == NULL && node->back == NULL)
	{
		p = draw_node(data, level, 1, point);
		return ;
	}
	if (node->front != NULL)
	{
		p = draw_node(data, level, 1, point);
		drawline(p, point, data, 0x00ff00);
		draw_bin_tree(data, node->front, level + 1, p);
	}
	if (node->back != NULL)
	{
		p = draw_node(data, level, -1, point);
		drawline(p, point, data, 0xff0000);
		draw_bin_tree(data, node->back, level + 1, p);
	}
}*/

void	draw_walls_from_bsp(t_data *data)
{
	int	color;
	int i;
	int j;

	color = 0xffffff;
	i = 0;
	while (i < data->NumberOfLeaves)
	{
		j = 0;
		printf("leaf:%d\n", i);
		while (data->Leaves[i].start + j < data->Leaves[i].end)
		{
			printf("wall index:%ld\n",data->Leaves[i].start + j);
			draw_2dwall(data, data->Walls[data->Leaves[i].start + j], color);
			j++;
		}
		i++;
	}
}

void draw_2dwall(t_data *data, t_wall wall, int color)
{
	t_point p1;
	t_point p2;
	t_point mid;
	p1.x = wall.start.x;
	p1.y = wall.start.y;
	p2.x = wall.end.x;
	p2.y = wall.end.y;
	mid.x = (p1.x + p2.x) / 2;
	mid.y = (p1.y + p2.y) / 2;
	drawline(p1, p2, data, color);
	drawline(mid, (t_point){mid.x + wall.normal.x *20, mid.y + wall.normal.y * 20}, data, 0xff);
}
