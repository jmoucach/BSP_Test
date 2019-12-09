/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_wlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:55:21 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/09 18:01:35 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void add_wlist(t_wlist **list, t_wlist *new)
{
	new->next = *list;
	(*list) = new;
}

void remove_wlist(t_wlist **list, int id)
{
	t_wlist *tmp;
	t_wlist *next;
	
	tmp = *list;
	while (tmp)
	{
		if (tmp->id == id)
		{
			next = tmp->next;
			printf("remove id:%d\n", tmp->id);
			free(tmp);
			tmp = next;
			break ;
		}
		tmp = tmp->next;
	}
}
