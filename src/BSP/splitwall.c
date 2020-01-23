/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitwall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:12:50 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/22 15:55:50 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

t_vertex wall_wall_intersection(t_wall w1, t_wall w2)
{
	double t;
	double u;
	double denom;
	t_vertex intersection;

	intersection.x = -1;
	intersection.y = -1;
	denom = (w1.start.x - w1.end.x) * (w2.start.y - w2.end.y)
		- (w1.start.y - w1.end.y) * (w2.start.x - w2.end.x);
	if (denom != 0)
	{
		t = ((w1.start.x - w2.start.x) * (w2.start.y - w2.end.y)
			- (w1.start.y - w2.start.y) * (w2.start.x - w2.end.x)) / denom;
		u = ((w1.start.x - w1.end.x) * (w1.start.y - w2.start.y)
			- (w1.start.y - w1.end.y) * (w1.start.x - w2.start.x)) / denom;
		if (t <= 1 && t >= 0 && u >= 0)
		{
			intersection.x = w1.start.x + t * (w1.end.x - w1.start.x);
			intersection.y = w1.start.y + t * (w1.end.y - w1.start.y);
		}
	}
	return (intersection);
}

void splitwall(t_wlist *list, t_wall splitter, t_wlist **frontsplit,
				t_wlist **backsplit)
{
	t_vertex point;
	int result;

	printf("split :%d\n", list->id);
	point = wall_wall_intersection(list->wall, splitter);
	if (point.x == -1 && point.y == -1)
		point = wall_wall_intersection(list->wall, (t_wall){splitter.end, splitter.start, splitter.normal});
	result = classifypoint(list->wall.start, splitter);
	(*frontsplit)->id = list->id;
	(*frontsplit)->isUsed = list->isUsed;
	(*backsplit)->id = list->id;
	(*backsplit)->isUsed = list->isUsed;
	if (result == C_FRONT)
	{
		(*frontsplit)->wall = create_wall(list->wall.start, point, list->wall.normal);
		(*backsplit)->wall = create_wall(point, list->wall.end, list->wall.normal);
	}
	else
	{
		(*backsplit)->wall = create_wall(list->wall.start, point, list->wall.normal);
		(*frontsplit)->wall = create_wall(point, list->wall.end, list->wall.normal);
	}
}
