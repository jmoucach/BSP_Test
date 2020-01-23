/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_portal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:32:19 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/23 14:37:48 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void clip_portal(t_portal **portal, t_data *data, int NodeId)
{
	// (void)portal;
	// (void)data;
	// (void)NodeId;
	// return NULL;
	int classified;
	t_portal *head;

	head = *portal;
	while (*portal)
	{
		classified = classifywall((t_wall){(*portal)->start, (*portal)->end, (t_vertex){0, 0}}, data->Nodes[NodeId].wall);
		if (classified == C_FRONT)
		{
			if (data->Nodes[NodeId].isleaf == 0)
			{
				clip_portal_front(portal, data, NodeId);
				clip_portal(portal, data, data->Nodes[NodeId].front);
			}
			else
			{
				if ((*portal)->NumberOfLeaves < 2)
					(*portal)->LeafOwners[(*portal)->NumberOfLeaves] = data->Nodes[NodeId].front;
				(*portal)->NumberOfLeaves++;
			}
		}
		else if (classified == C_BACK)
		{
			if (data->Nodes[NodeId].back != -1)
			{
				clip_portal_back(portal, data, NodeId);
				clip_portal(portal, data, data->Nodes[NodeId].front);
			}
			else
				remove_portal(&head, *portal);
		}
		else if (classified == C_ALIGN)
		{
			clip_portal_align(portal, data, NodeId);
			clip_portal(portal, data, data->Nodes[NodeId].front);
			clip_portal(portal, data, data->Nodes[NodeId].back);
		}
		else
		{
		}
	}
	/* 	int classified;
	t_portal *list;
	t_portal *iterator;
	t_portal *front;
	t_portal *back;
	t_portal *frontsplit;
	t_portal *backsplit;

	classified = classifywall((t_wall){portal->start, portal->end, (t_vertex){0,0}}, data->Nodes[NodeId].wall);
	if (C_FRONT)
	{
		if (data->Nodes[NodeId].isleaf == 0)
		{
			list = clip_portal(portal, data, data->Nodes[NodeId].front);
			return list;
		}
		else
		{
			if (portal->NumberOfLeaves < 2)
				portal->LeafOwners[portal->NumberOfLeaves] = data->Nodes[NodeId].front;
			portal->NumberOfLeaves++;
			portal->next = NULL;
			return portal;
		}
	}
	else if (C_BACK)
	{
		if (data->Nodes[NodeId].back != -1)
		{
			list = clip_portal(portal, data, data->Nodes[NodeId].back);
			return list;
		}
		else
		{
			free(portal);
			return NULL;
		}
	}
	else
	{
		if (!(frontsplit = (t_portal*)malloc(sizeof(t_portal)))
			|| !(backsplit = (t_portal*)malloc(sizeof(t_portal))))
			return (NULL);
		ft_bzero(frontsplit, sizeof(t_portal));
		ft_bzero(backsplit, sizeof(t_portal));
		splitportal(portal, &frontsplit, &backsplit, data, NodeId);
		if (data->Nodes[NodeId].isleaf == 0)
			front = clip_portal(frontsplit, data, NodeId);
		else
		{
			if (portal->NumberOfLeaves < 2)
				frontsplit->LeafOwners[frontsplit->NumberOfLeaves] = data->Nodes[NodeId].front;
			frontsplit->NumberOfLeaves++;
			frontsplit->next = NULL;
			front = frontsplit;
		}
		if (data->Nodes[NodeId].back != -1)
			back = clip_portal(backsplit, data, data->Nodes[NodeId].back);
		else
			free(backsplit);
		
		if (front != NULL)
		{
			iterator = front;
			while (iterator->next)
				iterator = iterator->next;
			if (back != NULL)
			iterator->next = back;
			return (front);
		}
		else
		{
			if (back != NULL)
				return (back);
			return (NULL);
		}
	} */
}