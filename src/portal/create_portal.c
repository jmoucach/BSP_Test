/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_portal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:32:01 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/21 13:33:40 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void create_portals(t_data *data)
{
	int i;
	t_portal *initial_portal;
	t_portal *list;
	t_portal *iterator;
	
	i = -1;
	while (++i < data->NumberOfNodes)
	{
		initial_portal = find_initial_portal(data, i);
		list = clip_portal(initial_portal, data, 0);
		iterator = list;
		while (iterator)
		{
			if (iterator->NumberOfLeaves != 2)
			{
				remove_portal(iterator, &list);
			}
			if (check_dup_portal(data,list) == 1)

		}
	}
}