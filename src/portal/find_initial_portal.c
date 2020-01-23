/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_initial_portal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:17:02 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/20 11:30:01 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

t_portal *find_initial_portal(t_data *data, int NodeId)
{
	t_portal *portal;
	t_wall wall;
	// t_box box;
	// t_vertex box_center;
	// t_vertex portal_center;
	// t_vertex vertex;
	// double distance_to_wall;

	if (!(portal = (t_portal*)malloc(sizeof(t_portal))))
		return (NULL);
	ft_bzero(portal,sizeof(t_portal));
	// box = data->Nodes[NodeId].boundingbox;
	// box_center.x = (box.Max.x + box.Min.x) / 2;
	// box_center.y = (box.Max.y + box.Min.y) / 2;
	// vertex = substract_vertex(data->Nodes[NodeId].wall.start, box_center);
	// distance_to_wall = dotproduct(vertex, data->Nodes[NodeId].wall.normal);
	// portal_center.x = box_center.x + distance_to_wall * vertex.x;
	// portal_center.y = box_center.y + distance_to_wall * vertex.y;
	wall = expand_wall_to_boundingbox(data->Nodes[NodeId].boundingbox, data->Nodes[NodeId].wall);
	portal->start = wall.start;
	portal->end = wall.end;
	portal->next = NULL;
	return (portal);
}