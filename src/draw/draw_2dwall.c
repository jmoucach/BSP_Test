/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2dwall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:25:28 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/03 10:59:48 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../hdr/doom.h"

void draw_2dwall(t_data *data, t_wall wall, int color)
{
	t_point p1;
	t_point p2;

	p1.x = wall.start.x;
	p1.y = wall.start.y;
	p2.x = wall.end.x;
	p2.y = wall.end.y;
	drawline(p1, p2, data, color);
}