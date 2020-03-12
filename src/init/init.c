/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:57:11 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/30 14:27:50 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

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

void			set_values(t_data *data)
{
	data->texture = NULL;
	data->renderer = NULL;
	data->window = NULL;
	data->msize.x = 0;
	data->msize.y = 0;
	data->quit = 0;
	data->MaxNodes = 10;
	data->MaxLeaves = 10;
	data->MaxWalls = 10;
	data->NumberOfWalls = 0;
	data->NumberOfLeaves = 0;
	data->NumberOfNodes = 0;
	if (!(data->Nodes = (t_BSPNode*)malloc(sizeof(t_BSPNode) * data->MaxNodes)))
		exit(EXIT_FAILURE);
	if (!(data->Walls = (t_wall*)malloc(sizeof(t_wall) * data->MaxWalls)))
		exit(EXIT_FAILURE);
	if (!(data->Leaves = (t_leaf*)malloc(sizeof(t_leaf) * data->MaxLeaves)))
		exit(EXIT_FAILURE);
	if (!(data->Portals = (t_portal**)malloc(sizeof(t_portal) * data->MaxPortals)))
		exit(EXIT_FAILURE);
	ft_bzero(data->Walls, sizeof(t_wall) * data->MaxWalls);
	ft_bzero(data->Leaves, sizeof(t_leaf) * data->MaxLeaves);
	ft_bzero(data->Nodes, sizeof(t_BSPNode) * data->MaxNodes);
	ft_bzero(data->Portals, sizeof(t_portal*) * data->MaxPortals);
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
