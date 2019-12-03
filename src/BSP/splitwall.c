/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitwall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:12:50 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/03 16:56:15 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

t_vertex wall_wall_intersection(t_wall w1, t_wall w2)
{
	double t;
	double denom;
	t_vertex intersection;

	denom = (w1.start.x - w1.end.x) * (w2.start.y - w2.end.y)
		- (w1.start.y - w1.end.y) * (w2.start.x - w2.end.x);
	t = ((w1.start.x - w2.start.x) * (w2.start.y - w2.end.y)
		- (w1.start.y - w2.start.y) * (w2.start.x - w2.end.x)) / denom;
	intersection.x = w1.start.x + t * (w1.end.x - w1.start.x);
	intersection.y = w1.start.y + t * (w1.end.y - w1.start.y);
	return (intersection);
}

void splitwall(t_wall wall, t_wall splitter, t_wlist **frontsplit,
	t_wlist **backsplit)
{
	t_vertex point;
	int result;

	point = wall_wall_intersection(wall, splitter);
	result = classifypoint(wall.start, splitter);
	if (result == C_FRONT)
	{
		(*frontsplit)->wall = create_wall(wall.start, point, wall.normal);
		(*backsplit)->wall = create_wall(point, wall.end, wall.normal);
	}
	else
	{
		(*backsplit)->wall = create_wall(wall.start, point, wall.normal);
		(*frontsplit)->wall = create_wall(point, wall.end, wall.normal);
	}
}