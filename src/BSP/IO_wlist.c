/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_wlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:55:21 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/04 12:04:38 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void add_wlist(t_wlist **list, t_wlist *new)
{
	new->next = *list;
	if (*list)
		(*list)->prev = new;
	(*list) = new;
}

void remove_wlist(t_wlist **list, int id)
{
	t_wlist *tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->id == id)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free(tmp);
			break ;
		}
		tmp = tmp->next;
	}
}
