/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_some_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:41:57 by acostaz           #+#    #+#             */
/*   Updated: 2020/01/06 12:33:44 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void	make_some_walls(t_wlist **walls)
{
	t_wlist *tmp;
	t_vertex unit;
	t_wall	wall;

	// wall.start = create_vertex(200.0, 100.0);
	// wall.end = create_vertex(300.0, 100.0);
 	// unit = unit_vertex(substract_vertex(wall.end, wall.start));
	// wall.normal = perp_vertex(unit);
	// tmp  = new_wlist(wall, 0);
	// addback_wlist(walls, tmp);
	wall.start = create_vertex(300.0, 100.0);
	wall.end = create_vertex(400.0, 200.0);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 1);
	addback_wlist(walls, tmp);
	wall.start = create_vertex(400.0, 200.0);
	wall.end = create_vertex(400.0, 300.0);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 2);
	addback_wlist(walls, tmp);
	// wall.start = create_vertex(400.0, 300.0);
	// wall.end = create_vertex(300.0, 400.0);
 	// unit = unit_vertex(substract_vertex(wall.end, wall.start));
	// wall.normal = perp_vertex(unit);
	// tmp  = new_wlist(wall, 3);
	// addback_wlist(walls, tmp);
	wall.start = create_vertex(300.0, 400.0);
	wall.end = create_vertex(200.0, 400.0);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 4);
	addback_wlist(walls, tmp);
	wall.start = create_vertex(200.0, 400.0);
	wall.end = create_vertex(100.0, 300.0);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 5);
	addback_wlist(walls, tmp);
	wall.start = create_vertex(100.0, 300.0);
	wall.end = create_vertex(100.0, 200.0);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 6);
	addback_wlist(walls, tmp);
	wall.start = create_vertex(100.0, 200.0);
	wall.end = create_vertex(200.0, 100.0);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 7);
	addback_wlist(walls, tmp);
	wall.start = create_vertex(200.0, 100.0);
	wall.end = create_vertex(250.0, 200.0);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 8);
	addback_wlist(walls, tmp);
	wall.start = create_vertex(250.0, 200.0);
	wall.end = create_vertex(300.0, 100.0);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 9);
	addback_wlist(walls, tmp);
	wall.start = create_vertex(400.0, 300.0);
	wall.end = create_vertex(290.0, 200.0);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 10);
	addback_wlist(walls, tmp);
	wall.start = create_vertex(290.0, 200.0);
	wall.end = create_vertex(300.0, 400.0);
 	unit = unit_vertex(substract_vertex(wall.end, wall.start));
	wall.normal = perp_vertex(unit);
	tmp  = new_wlist(wall, 11);
	addback_wlist(walls, tmp);
}
