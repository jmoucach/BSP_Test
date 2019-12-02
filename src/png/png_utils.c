/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:02:05 by sjulliot          #+#    #+#             */
/*   Updated: 2019/10/01 14:10:05 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../hdr/png.h"
#include "../../libft/inc/ft_printf.h"

int					print_error(char *msg)
{
	ft_putendl(msg);
	return (PB);
}

void				reverse_int(unsigned int *val)
{
	*val = ((*val >> 24) & 0xff) |
		((*val << 8) & 0xff0000) |
		((*val >> 8) & 0xff00) |
		((*val << 24) & 0xff000000);
}

int					alloc_img_tab(t_img *img)
{
	unsigned int	y;

	if (!(img->pixels = (t_color**)ft_memalloc(sizeof(t_color*) * img->height)))
		return (PB);
	y = 0;
	while (y < img->height)
	{
		if (!(img->pixels[y] =
					(t_color*)ft_memalloc(sizeof(t_color) * img->width)))
			return (PB);
		y++;
	}
	return (OK);
}

int					alloc_pixels(t_png *img, size_t len)
{
	if (!(img->pixels = (t_color*)malloc(len)))
		return (PB);
	return (OK);
}

void				free_png(t_png *png)
{
	free(png->pixels);
	ft_lstdel(&png->data_blocks, free_block);
	free(png);
}
