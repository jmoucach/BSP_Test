/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_portal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:16:05 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/20 12:29:13 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

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