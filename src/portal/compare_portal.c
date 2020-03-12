/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_portal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:07:42 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/23 15:27:22 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

short compare_portal(t_portal *p1, t_portal *p2)
{
	if (!p1 || !p2)
		return (0);
	if ((p1->LeafOwners[0] == p2->LeafOwners[0]
		&& p1->LeafOwners[1] == p2->LeafOwners[1])
		|| (p1->LeafOwners[0] == p2->LeafOwners[1]
		&& p1->LeafOwners[1] == p2->LeafOwners[0]))
		if (p1->NumberOfLeaves == p2->NumberOfLeaves)
			if ((compare_vertex(p1->start, p2->start)
				&& compare_vertex(p1->end, p2->end))
				|| (compare_vertex(p1->start, p2->end)
				&& compare_vertex(p1->end, p2->start)))
				return (1);
	return (0);
}