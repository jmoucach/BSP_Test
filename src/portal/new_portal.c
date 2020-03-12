/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_portal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:46:08 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/23 15:03:21 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

t_portal *new_portal(t_vertex start, t_vertex end)
{
	t_portal *new;

	if (!(new = (t_portal*)malloc(sizeof(t_portal))))
		return (NULL);
	new->NumberOfLeaves = 0;
	new->start = create_vertex(start.x ,start.y);
	new->end = create_vertex(end.x ,end.y);
	new->next = NULL;
	return (new);
}

t_portal *dup_portal(t_portal *portal)
{
	t_portal *new;

	if (!(new = (t_portal*)malloc(sizeof(t_portal))))
		return (NULL);
	new->NumberOfLeaves = portal->NumberOfLeaves;
	new->next = NULL;
	new->start = portal->start;
	new->end = portal->end;
	new->LeafOwners[0] = portal->LeafOwners[0];
	new->LeafOwners[1] = portal->LeafOwners[1];
	return (new);
}

void dup_portal_data(t_portal *portal, t_portal**dup)
{
	(*dup)->NumberOfLeaves = portal->NumberOfLeaves;
	(*dup)->start = portal->start;
	(*dup)->end = portal->end;
	(*dup)->LeafOwners[0] = portal->LeafOwners[0];
	(*dup)->LeafOwners[1] = portal->LeafOwners[1];
	(*dup)->next = NULL;
}