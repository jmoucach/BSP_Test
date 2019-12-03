/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:11:34 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/03 15:24:16 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

t_wall create_wall(t_vertex start, t_vertex end, t_vertex normal)
{
	t_wall new;

	new.start = create_vertex(start.x, start.y);
	new.end = create_vertex(end.x, end.y);
	new.normal = create_vertex(normal.x, normal.y);
	return (new);
}

t_wall create_emptywall(void)
{
	t_wall new;
	
	new.start = create_vertex(0,0);
	new.end = create_vertex(0,0);
	new.normal = create_vertex(0,0);
	return (new);
}