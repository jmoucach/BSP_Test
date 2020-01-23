/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitportal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:04:20 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/23 13:59:35 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void splitportal(t_portal *portal, t_portal **front, t_portal **back, t_data *data, int NodeId)
{
	t_vertex point;
	int result;

	point = wall_wall_intersection((t_wall){portal->start, portal->end}, data->Nodes[NodeId].wall);
	result = classifypoint(portal->start, data->Nodes[NodeId].wall);
	*front = dup_portal(portal);
	*back = dup_portal(portal);

	if (result == C_FRONT)
	{
		(*front)->start = point;
		(*front)->end = portal->start;
		(*back)->start = portal->end;
		(*back)->end = point;
	}
	else
	{
		(*back)->start = point;
		(*back)->end = portal->start;
		(*front)->start = portal->end;
		(*front)->end = point;
	}
}