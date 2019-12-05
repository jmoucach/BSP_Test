/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_basics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:51:08 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/04 16:42:19 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../hdr/doom.h"

t_vertex substract_vertex(t_vertex v1, t_vertex v2)
{
	t_vertex out;

	out.x = v1.x - v2.x;
	out.y = v1.y - v2.y;
	return out;
}

t_vertex add_vertex(t_vertex v1, t_vertex v2)
{
	t_vertex out;

	out.x = v1.x + v2.x;
	out.y = v1.y + v2.y;
	return out;
}

t_vertex unit_vertex(t_vertex v)
{
	t_vertex unit;
	double mag;

	mag = sqrt(v.x * v.x + v.y * v.y);
	if (mag == 0)
	{
		unit.x = 0;
		unit.y = 0;
	}
	else
	{
		unit.x = v.x / mag;
		unit.y = v.y / mag;
	}
	return unit;
}

t_vertex perp_vertex(t_vertex v)
{
	t_vertex perp;

	perp.x = -v.y;
	perp.y = v.x;
	return perp;
}

t_vertex create_vertex(double x, double y)
{
	t_vertex new;

	new.x = x;
	new.y = y;
	return (new);
}
