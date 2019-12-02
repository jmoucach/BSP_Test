/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ihdr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:00:24 by sjulliot          #+#    #+#             */
/*   Updated: 2019/09/30 16:16:03 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/inc/libft.h"
#include "../../libft/inc/ft_printf.h"
#include "../../hdr/png.h"

static int	check_bit_depth(char color_type, char depth)
{
	if (color_type == TRUE_WITH_ALPHA && (depth == 8 || depth == 16))
		return (OK);
	ft_printf("Invalid color type\n");
	return (PB);
}

int			process_ihdr(char *data, unsigned int len, t_png *img)
{
	if (len != 13)
		return (PB);
	ft_bzero(img, sizeof(t_png));
	ft_memcpy(img, data, len);
	reverse_int(&(img->width));
	reverse_int(&(img->height));
	if (img->width == 0 || img->height == 0
			|| img->width > MAX_WIDTH || img->height > MAX_HEIGHT
			|| check_bit_depth(img->color_type, img->depth)
			|| img->compression_method != 0
			|| img->filter_method != NO_FILTER
			|| (img->interlace_method != 0 && img->interlace_method != 1))
		return (PB);
	return (OK);
}
