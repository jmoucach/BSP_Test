/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_wlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:51:48 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/02 14:23:01 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../hdr/doom.h"

t_wlist *new_wlist(t_wall wall, int id)
{
	t_wlist *new;

	if (!(new = (t_wlist*)malloc(sizeof(t_wlist))))
		return (NULL);
	new->id = id;
	new->wall.start = create_vertex(wall.start.x, wall.start.y);
	new->wall.end = create_vertex(wall.end.x, wall.end.y);
	new->wall.normal = create_vertex(wall.normal.x, wall.normal.y);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}