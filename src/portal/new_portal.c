/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_portal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:46:08 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/23 14:51:23 by jmoucach         ###   ########.fr       */
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