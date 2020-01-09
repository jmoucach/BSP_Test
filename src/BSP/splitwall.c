/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitwall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:12:50 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/09 13:24:32 by jmoucach         ###   ########.fr       */
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

void splitwall(t_wlist *list, t_wall splitter, t_wlist **frontsplit,
	t_wlist **backsplit)
{
	t_vertex point;
	int result;

	printf("splitted id :%d\n", list->id);
	point = wall_wall_intersection(list->wall, splitter);
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
	// ft_putendl("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	// 	print_wall((*frontsplit)->wall);
	// 	print_wall((*backsplit)->wall);
	// ft_putendl("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
}
