/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_some_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:41:57 by acostaz           #+#    #+#             */
/*   Updated: 2019/12/04 16:50:52 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void	make_some_walls(t_wlist **walls)
{
	t_wlist *tmp;
	t_vertex unit;
	t_wall	wall;

	wall.start = create_vertex(200, 100);
	wall.end = create_vertex(300, 100);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 0);
	add_wlist(walls, tmp);
	wall.start = create_vertex(300, 100);
	wall.end = create_vertex(400, 200);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 1);
	add_wlist(walls, tmp);
	wall.start = create_vertex(400, 200);
	wall.end = create_vertex(400, 300);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 2);
	add_wlist(walls, tmp);
	wall.start = create_vertex(400, 300);
	wall.end = create_vertex(300, 400);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 3);
	add_wlist(walls, tmp);
	wall.start = create_vertex(300, 400);
	wall.end = create_vertex(200, 400);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 4);
	add_wlist(walls, tmp);
	wall.start = create_vertex(200, 400);
	wall.end = create_vertex(100, 300);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 5);
	add_wlist(walls, tmp);
	wall.start = create_vertex(100, 300);
	wall.end = create_vertex(100, 200);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 6);
	add_wlist(walls, tmp);
	wall.start = create_vertex(100, 200);
	wall.end = create_vertex(200, 100);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 7);
	add_wlist(walls, tmp);
	wall.start = create_vertex(200, 100);
	wall.end = create_vertex(250, 200);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 8);
	add_wlist(walls, tmp);
	wall.start = create_vertex(250, 200);
	wall.end = create_vertex(300, 100);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 9);
	add_wlist(walls, tmp);
	wall.start = create_vertex(400, 300);
	wall.end = create_vertex(290, 200);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 10);
	add_wlist(walls, tmp);
	wall.start = create_vertex(290, 200);
	wall.end = create_vertex(300, 400);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 11);
	add_wlist(walls, tmp);
}
