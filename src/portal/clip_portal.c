/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_portal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:32:19 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/30 14:18:17 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void clip_portal_align(t_portal **portal, t_wall wall)
{
	if (vertex_on_segment(wall.start, (*portal)->start, (*portal)->end))
	{
		if (vertex_on_segment(wall.end, (*portal)->start, (*portal)->end))
			splitportal_wall_inside(portal, wall);
		else
		{
			if (vertex_on_segment((*portal)->start, wall.start, wall.end))
				(*portal)->start = create_vertex(wall.start.x, wall.start.y);
			else
				(*portal)->end = create_vertex(wall.start.x, wall.start.y);
		}
	}
	else if (vertex_on_segment(wall.end, (*portal)->start, (*portal)->end))
	{
		if (vertex_on_segment((*portal)->start, wall.start, wall.end))
			(*portal)->start = create_vertex(wall.end.x, wall.end.y);
		else
			(*portal)->end = create_vertex(wall.end.x, wall.end.y);
	}
}

void clip_portal_front(t_portal **portal, t_wall wall, t_portalutil utils)
{
	t_vertex pVertex;
	t_vertex wVertex;
	t_vertex point;
	t_portal *new;
	(void)utils;

	pVertex = substract_vertex((*portal)->start, (*portal)->end);
	wVertex = substract_vertex(wall.start, wall.end);
	if (vertex_are_colinear(wVertex, pVertex) == 1)
		return;
	else
	{
		point = wall_wall_intersection((t_wall){(*portal)->start, (*portal)->end, (t_vertex){0, 0}}, wall);
		if (point.x == -1 && point.y == -1)
			point = wall_wall_intersection((t_wall){(*portal)->start, (*portal)->end, (t_vertex){0, 0}},
				(t_wall){wall.end, wall.start, (t_vertex){0, 0}});
		if (point.x != -1 && point.y != -1)
		{
			t_vertex save;

			save = (*portal)->end;
			(*portal)->end = create_vertex(point.x, point.y);
			new = new_portal(point, save);
			addback_portal(portal, new);
		}
	}
}

void front_case_clip_portal(t_portal *portal, t_data *data, int NodeId,
	t_portalutil utils)
{
	if (data->Nodes[NodeId].isleaf == 0)
	{
		clip_portal_front(&portal, data->Nodes[NodeId].wall, utils);
		clip_portal(&portal, data, data->Nodes[NodeId].front);
	}
	else
	{
		if (portal->NumberOfLeaves < 2)
			portal->LeafOwners[portal->NumberOfLeaves] = data->Nodes[NodeId].front;
		portal->NumberOfLeaves++;
	}
}

void clip_portal(t_portal **portal, t_data *data, int NodeId)
{
	int classified;
	t_portal *head;
	t_portalutil utils;

	utils.front = NULL;
	utils.back = NULL;
	utils.front_split = NULL;
	utils.back_split = NULL;
	head = *portal;
	while (*portal)
	{
		classified = classifywall((t_wall){(*portal)->start, (*portal)->end, (t_vertex){0, 0}},
			data->Nodes[NodeId].wall);
		if (classified == C_FRONT)
			front_case_clip_portal(*portal, data, NodeId, utils);
		else if (classified == C_BACK)
		{
			if (data->Nodes[NodeId].back != -1)
				clip_portal(portal, data, data->Nodes[NodeId].back);
			else
				remove_portal(&head, *portal);
		}
		else if (classified == C_ALIGN)
		{
			clip_portal_align(portal, data->Nodes[NodeId].wall);
			if (data->Nodes[NodeId].isleaf == 0)
			{
				clip_portal(portal, data, data->Nodes[NodeId].front);
				if (data->Nodes[NodeId].back != -1)
					clip_portal(portal, data, data->Nodes[NodeId].back);
			}
			else
			{
				if ((*portal)->NumberOfLeaves < 2)
					(*portal)->LeafOwners[(*portal)->NumberOfLeaves] = data->Nodes[NodeId].front;
				(*portal)->NumberOfLeaves++;
			}
		}
		else
		{
			splitportal(portal, data->Nodes[NodeId].wall);
			if (data->Nodes[NodeId].isleaf == 0)
				clip_portal(portal, data, data->Nodes[NodeId].front);
			else
			{
				if ((*portal)->NumberOfLeaves < 2)
					(*portal)->LeafOwners[(*portal)->NumberOfLeaves] = data->Nodes[NodeId].front;
				(*portal)->NumberOfLeaves++;
			}
		}
		if (*portal)
			*portal = (*portal)->next;
	}
	*portal = head;
}