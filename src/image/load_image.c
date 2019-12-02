/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:42:14 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/11 17:48:40 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/wolf3d.h"

Uint32			get_pixel(SDL_Surface *s, int x, int y)
{
	int		bpp;
	Uint8	*p;

	bpp = s->format->BytesPerPixel;
	p = s->pixels + y * s->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	else if (bpp == 2)
		return (*(Uint16*)p);
	else if (bpp == 3)
		return ((p[0]) | (p[1] << 8) | (p[2] << 16));
	else
		return (*(Uint32*)p);
}

SDL_Surface		*loadimage(char *path)
{
	SDL_Surface *loadedsurface;

	loadedsurface = SDL_LoadBMP(path);
	if (!loadedsurface)
	{
		ft_putstr_fd("Couldn't load image:", 2);
		ft_putendl_fd(path, 2);
		ft_putstr_fd("Error: ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (NULL);
	}
	return (loadedsurface);
}

short			loadmedia(t_data *data)
{
	data->surface[0] = loadimage("pics/redbrick.bmp");
	if (!data->surface[0])
		return (0);
	data->surface[1] = loadimage("pics/bluestone.bmp");
	if (!data->surface[1])
		return (0);
	data->surface[2] = loadimage("pics/greystone.bmp");
	if (!data->surface[2])
		return (0);
	data->surface[3] = loadimage("pics/mossy.bmp");
	if (!data->surface[3])
		return (0);
	data->surface[4] = loadimage("pics/tile2.bmp");
	if (!data->surface[4])
		return (0);
	data->surface[5] = loadimage("pics/wood.bmp");
	if (!data->surface[5])
		return (0);
	return (1);
}
