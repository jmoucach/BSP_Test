/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlist_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:50:14 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/06 12:51:53 by jmoucach         ###   ########.fr       */
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