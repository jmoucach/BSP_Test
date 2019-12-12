/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlist_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:50:14 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/11 15:25:15 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

int get_wlist_length(t_wlist *list)
{
	int i = 0;

	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int count_unused(t_wlist *list)
{
	int count;

	count = 0;
	while (list)
	{
		if (list->isUsed == 0)
			count++;
		list = list->next;
	}
	return (count);
}

void print_wlist(t_wlist *list)
{
	printf("=====================\n");
	while (list)
	{
		printf("Wall id:%d, wall |start: X:%f, Y:%f| |end: X:%f, Y:%f| |normal: X:%f, Y:%f|\n", list->id, list->wall.start.x, list->wall.start.y, list->wall.end.x, list->wall.end.y, list->wall.normal.x, list->wall.normal.y);
		list = list->next;
	}
	printf("=====================\n");
}