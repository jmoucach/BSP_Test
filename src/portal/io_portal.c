/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_portal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:42:12 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/29 17:26:29 by jmoucach         ###   ########.fr       */
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

void remove_portal(t_portal **head, t_portal *removed)
{
	t_portal *iterator;
	t_portal *next;


	if (!removed || !head || !(*head))
		return ;
		printf("\033[0;33mremoved portal: (%f %f) (%f %f)\n\033[0m", removed->start.x, removed->start.y, removed->end.x, removed->end.y);
		
	if (compare_portal(*head, removed) == 1)
	{
		printf("\033[0;33mtwas the head\033[0m\n");
		*head = (*head)->next;
	}
	else
	{
		iterator = *head;
		while (iterator->next)
		{

			next = iterator->next;
			if (compare_portal(next, removed) == 1)
			{
																printf("\033[0;33mtwas inside\033[0m\n");
				// free(iterator->next);
				iterator->next = next->next;
				break ;
			}
			iterator = next;
		}
	}
}