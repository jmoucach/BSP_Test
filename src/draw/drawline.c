/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:27:49 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/09 15:50:33 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void				setup_param(t_point pt_one, t_point pt_two,
	t_line_param *line_param)
{
	line_param->diff.x = ft_abs(pt_two.x - pt_one.x);
	line_param->diff.y = ft_abs(pt_two.y - pt_one.y);
	line_param->off = line_param->diff.x - line_param->diff.y;
	line_param->inc.x = (pt_one.x < pt_two.x ? 1 : -1);
	line_param->inc.y = (pt_one.y < pt_two.y ? 1 : -1);
}

void				drawline(t_point pt_one, t_point pt_two,
	t_data *data, int colour)
{
	t_point			pt;
	t_line_param	line_param;
	Uint32			*pix;

	pix = data->pixels;
	setup_param(pt_one, pt_two, &line_param);
	pt = pt_one;
	while (pt.x != pt_two.x || pt.y != pt_two.y)
	{
		if (pt.x >= 0 && pt.x <= SCREEN_WIDTH && pt.y >=0 && pt.y <= SCREEN_HEIGHT)
			pix[pt.x + pt.y * SCREEN_WIDTH] = colour;
		if ((line_param.error = line_param.off * 2) > -line_param.diff.y)
		{
			line_param.off -= line_param.diff.y;
			pt.x += line_param.inc.x;
		}
		if (line_param.error <= line_param.diff.x)
		{
			line_param.off += line_param.diff.x;
			pt.y += line_param.inc.y;
		}
	}
	if (pt.x >= 0 && pt.x <= SCREEN_WIDTH && pt.y >=0 && pt.y <= SCREEN_HEIGHT)
		pix[pt.x + pt.y * SCREEN_WIDTH] = colour;
}
