/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_wlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:55:21 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/12 18:09:35 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void add_wlist(t_wlist **list, t_wlist *new)
{
	new->next = *list;
	(*list) = new;
}
/*
void addback_wlist(t_wlist **list, t_wlist *new)
{
	t_wlist *head;

	while (list)
	{
		list = list->next;
	}
}*/

void remove_wlist(t_wlist **list, int id)
{
	t_wlist *tmp;
	t_wlist *prev;

	tmp = *list;
	if (tmp->id == id)
	{
		*list = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp != NULL && tmp->id != id)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	prev->next = tmp->next;
	free(tmp);
}