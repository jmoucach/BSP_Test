/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:57:11 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/11 17:46:01 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/wolf3d.h"

void			nullify_surfaces(t_data *data)
{
	int			i;

	i = -1;
	while (++i < 6)
		data->surface[i] = NULL;
}

short			create_renderer_texture_and_pixels(t_data *data)
{
	if (!(data->renderer = SDL_CreateRenderer(data->window, -1, 0)))
	{
		ft_putstr_fd("Failed to create renderer! Error:", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (0);
	}
	else if (!(data->texture = SDL_CreateTexture(data->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH,
		SCREEN_HEIGHT)))
	{
		ft_putstr_fd("Failed to create texture! Error:", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (0);
	}
	else if (!(data->pixels = (Uint32 *)malloc(sizeof(Uint32) * SCREEN_WIDTH
		* SCREEN_HEIGHT + 1)))
	{
		ft_putendl_fd("Failed to allocate pixels", 2);
		return (0);
	}
	return (1);
}

void			set_raycast_values(t_raycast *values, t_player player, int x)
{
	values->camera = 2 * x / (double)SCREEN_WIDTH - 1;
	values->ray.pos.x = player.pos.x;
	values->ray.pos.y = player.pos.y;
	values->ray.dir.x = player.dir.x + player.plane.x * values->camera;
	values->ray.dir.y = player.dir.y + player.plane.y * values->camera;
	values->m_pos.x = (int)values->ray.pos.x;
	values->m_pos.y = (int)values->ray.pos.y;
	values->deltadist.x = sqrt(1 + (values->ray.dir.y * values->ray.dir.y)
		/ (values->ray.dir.x * values->ray.dir.x));
	values->deltadist.y = sqrt(1 + (values->ray.dir.x * values->ray.dir.x)
		/ (values->ray.dir.y * values->ray.dir.y));
	values->hit = 0;
	values->side = 0;
}

void			set_values(t_data *data)
{
	data->p.angle = 0 * M_PI / 180;
	data->p.dir.x = 1;
	data->p.dir.y = 0;
	data->toggle_minimap = 0;
	data->p.plane.x = 0;
	data->p.plane.y = -0.66;
	data->p.rspeed = 2;
	data->p.sprintspeed = 6;
	data->p.walkspeed = 3;
	data->texture = NULL;
	data->renderer = NULL;
	data->window = NULL;
	data->msize.x = 0;
	data->msize.y = 0;
	data->quit = 0;
	data->sensitivity = 0.5;
	data->yaw = 0;
	if (!(data->surface = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 6)))
		exit(EXIT_FAILURE);
	nullify_surfaces(data);
}

short			init(t_data *data)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putstr_fd("Failed to initialize! Error:", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (0);
	}
	else
	{
		data->window = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
		if (data->window)
		{
			if (!create_renderer_texture_and_pixels(data))
				return (0);
		}
		else
		{
			ft_putstr_fd("Failed to create window! Error:", 2);
			ft_putendl_fd(SDL_GetError(), 2);
			return (0);
		}
	}
	return (1);
}
