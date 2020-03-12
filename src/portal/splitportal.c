/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitportal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:04:20 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/29 17:05:18 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void splitportal(t_portal **portal, t_wall wall)
{
	t_vertex point;
	t_vertex save;
	t_portal *new;
	int result;

	printf("\033[0;33m######################\n");
	printf("WALL split (%f %f) (%f %f)\n", wall.start.x, wall.start.y, wall.end.x, wall.end.y);
	printf("portal (%f %f) (%f %f)\n", (*portal)->start.x, (*portal)->start.y, (*portal)->end.x, (*portal)->end.y);
	point = wall_wall_intersection((t_wall){(*portal)->start, (*portal)->end, (t_vertex){0,0}}, wall);
	if (point.x == -1 && point.y == -1)
		point = wall_wall_intersection((t_wall){(*portal)->start, (*portal)->end, (t_vertex){0,0}},
			(t_wall){wall.end, wall.start, wall.normal});
	printf("=====splitportal point : X:%f Y:%f=====\n", point.x, point.y);
	result = classifypoint((*portal)->start, wall);
	if (result == C_FRONT)
	{
		save = (*portal)->end;
		(*portal)->end = point;
		new = new_portal(point, save);
	}
	else
	{
		save = (*portal)->start;
		(*portal)->start = point;
		new = new_portal(save, point);
	}
	addback_portal(portal, new);
	printf("in the end portal (%f %f) (%f %f) && (%f %f) (%f %f)\n$$$$$$$$$$$$$$$$$$$$$$$\n\033[0m", (*portal)->start.x, (*portal)->start.y, (*portal)->end.x, (*portal)->end.y, new->start.x, new->start.y, new->end.x, new->end.y);
}

void splitportal_wall_inside(t_portal **portal, t_wall wall)
{
	t_portal *new;
	t_vertex save;
	double dist_startstart;
	double dist_startend;

	dist_startstart = vertex_distance((*portal)->start, wall.start);
	dist_startend = vertex_distance((*portal)->start, wall.end);
	printf("\033[0;33m######################\n");
	printf("WALL inside (%f %f) (%f %f)\n", wall.start.x, wall.start.y, wall.end.x, wall.end.y);
	printf("portal (%f %f) (%f %f)\n", (*portal)->start.x, (*portal)->start.y, (*portal)->end.x, (*portal)->end.y);

	if (dist_startstart < dist_startend)
	{
		save = (*portal)->end;
		(*portal)->end = create_vertex(wall.start.x, wall.start.y);
		new = new_portal(wall.end, save);
	}
	else
	{
		save = (*portal)->end;
		(*portal)->end = create_vertex(wall.end.x, wall.end.y);
		new = new_portal(wall.start, save);
	}
	addback_portal(portal, new);
	printf("in the end portal (%f %f) (%f %f) && (%f %f) (%f %f)\n$$$$$$$$$$$$$$$$$$$$$$$\n\033[0m", (*portal)->start.x, (*portal)->start.y, (*portal)->end.x, (*portal)->end.y, new->start.x, new->start.y, new->end.x, new->end.y);
}