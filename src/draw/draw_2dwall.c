/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2dwall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:25:28 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/04 14:03:54 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../hdr/doom.h"

void	draw_tree_line(t_data *data, int dir, int level, int width)
{
	Uint32	*pix;
	t_point	point;
	t_point	point2;

	pix = data->pixels;
	point.x = SCREEN_WIDTH / 2 + width * 20 * (7 - level) + 5;
	point.y = 50 + level * 20 + 5;
	point2.x = point.x + dir * 20 * (7 - level - 1);
	point2.y = point.y + 20;
	if (dir == 1)
		drawline(point, point2, data, 0x00ff00);
	else
		drawline(point, point2, data, 0xff0000);
}

void	draw_node(t_data *data, int level, int width)
{
	Uint32	*pix;
	t_point	point;
	t_point	point2;

	pix = data->pixels;
	point.x = SCREEN_WIDTH / 2 + width * 20 * (7 - level);
	point.y = 50 + level * 20;
	point2.x = point.x + 10;
	point2.y = point.y + 10;
	draw_rect_to_sdl(point, point2, data, 0xffffff);
}

void	draw_bin_tree(t_data *data, t_BSPNode *node, int level, int width)
{
	draw_node(data, level, width);
	if (node->front == NULL && node->back == NULL)
		return ;
	if (node->front != NULL)
	{
		draw_tree_line(data, 1, level, width);
		draw_bin_tree(data, node->front, level + 1, width + 1);
	}
	if (node->back != NULL)
	{
		draw_tree_line(data, -1, level, width);
		draw_bin_tree(data, node->back, level + 1, width - 1);
	}
}

void draw_2dwall(t_data *data, t_wall wall, int color)
{
	t_point p1;
	t_point p2;

	p1.x = wall.start.x;
	p1.y = wall.start.y;
	p2.x = wall.end.x;
	p2.y = wall.end.y;
	drawline(p1, p2, data, color);
}
