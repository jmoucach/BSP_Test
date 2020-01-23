/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_portal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:42:12 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/23 14:45:49 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void add_portal(t_portal **head, t_portal *new)
{
	new->next = *head;
	*head = new;
}

void addback_portal(t_portal **head, t_portal *new)
{
	t_portal *last;

	last = *head;
	new->next = NULL;
	if (!(*head))
	{
		*head = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}