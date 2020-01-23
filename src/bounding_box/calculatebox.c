/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculatebox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:10:18 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/10 11:06:51 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void Calculatebox_list(t_box *box, t_wlist *list)
{
	while (list)
	{
		Calculatebox_wall(box, list->wall);
		list =list->next;
	}
}

void Calculatebox_wall(t_box *box, t_wall wall)
{
	if (wall.start.x < box->Min.x)
		box->Min.x = wall.start.x - 2;
	if (wall.start.y < box->Min.y)
		box->Min.y = wall.start.y - 2;
	if (wall.end.x < box->Min.x)
		box->Min.x = wall.end.x - 2;
	if (wall.end.y < box->Min.y)
		box->Min.y = wall.end.y - 2;
	if (wall.start.x > box->Max.x)
		box->Max.x = wall.start.x + 2;
	if (wall.start.y > box->Max.y)
		box->Max.y = wall.start.y + 2;
	if (wall.end.x > box->Max.x)
		box->Max.x = wall.end.x + 2;
	if (wall.end.y > box->Max.y)
		box->Max.y = wall.end.y + 2;
}