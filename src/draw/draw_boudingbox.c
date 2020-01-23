/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_boudingbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:34:01 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/09 15:36:22 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void draw_boudingbox(t_data *data, t_box box, int colour)
{
	drawline((t_point){box.Min.x, box.Min.y}, (t_point){box.Max.x, box.Min.y}, data, colour);
	drawline((t_point){box.Min.x, box.Min.y}, (t_point){box.Min.x, box.Max.y}, data, colour);
	drawline((t_point){box.Max.x, box.Max.y}, (t_point){box.Max.x, box.Min.y}, data, colour);
	drawline((t_point){box.Max.x, box.Max.y}, (t_point){box.Min.x, box.Max.y}, data, colour);
}