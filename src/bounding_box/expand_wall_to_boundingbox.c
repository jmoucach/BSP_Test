/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wall_to_boundingbox.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:52:58 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/16 13:47:27 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

t_wall expand_wall_to_boundingbox(t_box box, t_wall wall)
{
	t_wall expanded;
	t_wall inverted;
	t_wall box_wall[4];
	int i;

	expanded.start.x = -1;
	expanded.start.y = -1;
	expanded.end.x = -1;
	expanded.end.y = -1;
	inverted.start = wall.end;
	inverted.end = wall.start;
	i = -1;
	box_wall[0] = (t_wall){box.Min,(t_vertex){box.Min.x, box.Max.y}, (t_vertex){0,0}};
	box_wall[1] = (t_wall){box.Min,(t_vertex){box.Max.x, box.Min.y}, (t_vertex){0,0}};
	box_wall[2] = (t_wall){box.Max,(t_vertex){box.Max.x, box.Min.y}, (t_vertex){0,0}};
	box_wall[3] = (t_wall){box.Max,(t_vertex){box.Min.x, box.Max.y}, (t_vertex){0,0}};
	while (++i < 4)
		if (expanded.start.x == -1 && expanded.start.y == -1)
			expanded.start = wall_wall_intersection(box_wall[i], wall);
	i = -1;
	while (++i < 4)
		if (expanded.end.x == -1 && expanded.end.y == -1)
			expanded.end = wall_wall_intersection(box_wall[i], inverted);
	expanded.normal = (t_vertex){0,0};
	return (expanded);
}