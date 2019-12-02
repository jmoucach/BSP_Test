/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:11:45 by sjulliot          #+#    #+#             */
/*   Updated: 2019/09/30 15:15:34 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/png.h"

static void			post_process_line(t_color *line, int width)
{
	int				i;
	t_color			tmp;

	i = -1;
	while (++i < width)
	{
		tmp = line[i];
		line[i].channel[0] = tmp.channel[2];
		line[i].channel[1] = tmp.channel[1];
		line[i].channel[2] = tmp.channel[0];
		line[i].channel[3] = 0;
	}
}

void				post_process_lines(t_img *img)
{
	unsigned int	y;

	y = -1;
	while (++y < img->height)
		post_process_line(img->pixels[y], img->width);
}
