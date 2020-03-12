/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colinear_vertex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:52:34 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/27 12:07:57 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

short vertex_are_colinear(t_vertex v1, t_vertex v2)
{
	double dx;
	double dy;

	dx = v1.x/v2.x;
	dy = v1.y/v2.y;
	dx = fabs(dx);
	dy = fabs(dy);
	if (dx == dy)
		return (1);
	return (0);
}