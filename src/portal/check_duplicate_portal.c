/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_portal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:55:00 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/21 13:27:57 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

short check_dup_portal(t_data *data, t_portal *portal)
{
	int i;
	int owner1;
	int owner2;

	i = -1;
	owner1 = portal->LeafOwners[0];
	owner2 = portal->LeafOwners[1];
	while (++i < data->NumberOfPortals)
	{
		int array_owner1;
		int array_owner2;

		array_owner1 = data->Portals[i]->LeafOwners[0];
		array_owner2 = data->Portals[i]->LeafOwners[1];
		if ((array_owner1 == owner1 && array_owner2 == owner2)
			|| (array_owner1 == owner2 && array_owner2 == owner1))
		{
			double length_p;
			double length_a;
			t_portal *a_portal;

			length_p = sqrt((portal->start.x - portal->end.x) * (portal->start.x - portal->end.x)
				+ (portal->start.y - portal->end.y) * (portal->start.y - portal->end.y));
			length_a = sqrt((a_portal->start.x - a_portal->end.x) * (a_portal->start.x - a_portal->end.x)
				+ (a_portal->start.y - a_portal->end.y) * (a_portal->start.y - a_portal->end.y));
			if (length_p > length_p)
				return (1);
			else
			{
				t_portal *temp;
				temp = data->Portals[i];
				free(temp);
				return (0);
			}
		}
		return (0);
	}
}