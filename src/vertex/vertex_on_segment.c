/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_on_segment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:50:56 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/29 15:31:06 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

short vertex_on_segment(t_vertex pt, t_vertex start, t_vertex end)
{
	t_vertex k;
	t_vertex diff_point;
	t_vertex diff_end;
	
	diff_point = (t_vertex){start.x - pt.x, start.y - pt.y};
	diff_end = (t_vertex){start.x - end.x, start.y - end.y};
	k.x = (start.x - end.x) / (start.x - pt.x);
	k.y = (start.y - end.y) / (start.y - pt.y);
	if (diff_point.x == 0 && diff_end.x == 0 && k.y >= 1)
		return (1);
	else if (diff_point.y == 0 && diff_end.y == 0 && k.x >= 1)
		return (1);
	else if (k.x >= 1 && k.y == k.x)
		return (1);
	else
		return (0);
}