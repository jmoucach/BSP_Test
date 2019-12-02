/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:42:14 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/02 13:00:49 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

Uint32				get_pixel(SDL_Surface *s, int x, int y)
{
	int				bpp;
	Uint8			*p;

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

void				free_png_img(t_img png)
{
	unsigned int	i;

	i = 0;
	while (i < png.height)
	{
		free(png.pixels[i]);
		i++;
	}
	free(png.pixels);
}

SDL_Surface			*loadimage(char *path)
{
	SDL_Surface		*loadedsurface;
	t_img			png;
	int				h;

	if (parse_png(path, &png) == PB)
		return (NULL);
	loadedsurface = SDL_CreateRGBSurface(0, png.width, png.height, 32,
			0xff000000, 0x00ff0000, 0x000000ff00, 0x000000ff);
	h = -1;
	while (++h < (int)png.height)
		ft_memcpy(loadedsurface->pixels + png.width * h * 4,
								png.pixels[h], png.width * 4);
	free_png_img(png);
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

short				loadmedia(t_data *data)
{
	data->surface[0] = loadimage("pics/2.png");
	if (!data->surface[0])
		return (0);
	data->surface[1] = loadimage("pics/3.png");
	if (!data->surface[1])
		return (0);
	data->surface[2] = loadimage("pics/5.png");
	if (!data->surface[2])
		return (0);
	data->surface[3] = loadimage("pics/6.png");
	if (!data->surface[3])
		return (0);
	data->surface[4] = loadimage("pics/floor.png");
	if (!data->surface[4])
		return (0);
	data->surface[5] = loadimage("pics/roof.png");
	if (!data->surface[5])
		return (0);
	return (1);
}
