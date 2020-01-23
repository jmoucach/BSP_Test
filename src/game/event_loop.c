/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:07:10 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/23 14:02:20 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void handle_input2(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_M])
	{
		data->toggle_minimap = !data->toggle_minimap;
		SDL_Delay(50);
	}
	if (state[SDL_SCANCODE_UP] && data->yaw < SCREEN_HEIGHT)
		data->yaw += 40;
	if (state[SDL_SCANCODE_DOWN] && data->yaw > -SCREEN_HEIGHT)
		data->yaw -= 40;
}

void handle_input(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_ESCAPE])
		data->quit = 1;
	if (state[SDL_SCANCODE_W])
	{
		if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
			sprint(data, 1);
		else
			walk(data, 1);
	}
	if (state[SDL_SCANCODE_S])
	{
		if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
			sprint(data, -1);
		else
			walk(data, -1);
	}
	if (state[SDL_SCANCODE_D])
		strafe(data, 1);
	if (state[SDL_SCANCODE_A])
		strafe(data, -1);
	if (state[SDL_SCANCODE_LEFT])
		rotate(data, 1);
	if (state[SDL_SCANCODE_RIGHT])
		rotate(data, -1);
	handle_input2(data, state);
}

void game_loop(t_data *data, t_wlist *walls)
{
	const Uint8 *state;
	int width;
	double time;
	t_portal *portal;

	print_wlist(walls);
	new_bspcompiler(&walls, data->NumberOfNodes, data);
	printf("Number of Nodes :%d\n", data->NumberOfNodes);
	printf("Number of Leaves :%d\n", data->NumberOfLeaves);
	data->Walls = ft_realloc(data->Walls, data->NumberOfWalls * sizeof(t_wall));
	width = SCREEN_WIDTH;
	// head = clip_portal(portal, data, 0);
	while (!data->quit)
	{
		int i = -1;
		while (++i < data->NumberOfNodes)
		{
			portal = find_initial_portal(data, i);
			draw_2dwall(data, (t_wall){portal->start, portal->end, (t_vertex){0,0}}, 0xff0000);
			free(portal);
			// printf("owners :%d %d\n", list->LeafOwners[0], list->LeafOwners[1]);
		}
		// draw_2dwall(data, expand_wall_to_boundingbox(data->Leaves[0].boundingbox, data->Walls[1]), 0xffffff);
		// int i = -1;
		// while (++i < data->NumberOfNodes)
		// 	draw_boudingbox(data, data->Nodes[i].boundingbox, 0x00ff00);
		draw_walls_from_bsp(data);
		// int i = -1;
		// while (++i < data->NumberOfLeaves)
		// 	draw_boudingbox(data, data->Leaves[i].boundingbox, 0xff00);
		data->ftime = (SDL_GetTicks() - time) / 1000;
		time = SDL_GetTicks();
		SDL_PumpEvents();
		state = SDL_GetKeyboardState(NULL);
		handle_input(data, state);
		SDL_UpdateTexture(data->texture, NULL, data->pixels,
						  width * 4);
		SDL_RenderClear(data->renderer);
		SDL_RenderCopy(data->renderer, data->texture, NULL, NULL);
		SDL_RenderPresent(data->renderer);
		ft_bzero(data->pixels, (SCREEN_WIDTH * SCREEN_HEIGHT + 1) * 4);
		// SDL_Delay(10000);
	}
}
