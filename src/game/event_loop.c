/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:07:10 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/12 14:51:41 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void			handle_input2(t_data *data, const Uint8 *state)
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

void			handle_input(t_data *data, const Uint8 *state)
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

void			game_loop(t_data *data)
{
	const Uint8	*state;
	int			width;
	double		time;
	t_wlist		*walls;

	walls = NULL;
	make_some_walls(&walls);
	data->Nodes = (t_BSPNode*)malloc(sizeof(t_BSPNode) * data->MaxNodes);
	data->Walls = (t_wall*)malloc(sizeof(t_wall) * data->MaxWalls);
	data->Leaves = (t_leaf*)malloc(sizeof(t_leaf) * data->MaxLeaves);
	ft_bzero(data->Walls, sizeof(t_wall) * data->MaxWalls);
	ft_bzero(data->Leaves, sizeof(t_leaf) * data->MaxLeaves);
	ft_bzero(data->Nodes, sizeof(t_BSPNode) * data->MaxNodes);
	// bspcompiler(walls);
	print_wlist(walls);
	// remove_wlist(&walls, 11);
	// print_wlist(walls);
			printf("start:|%d| end:|%d|\n", data->Leaves[0].start,data->Leaves[0].end);
	new_bspcompiler(walls, data->NumberOfNodes, data);

	printf("############################\n");
			// printf("start:|X:%f, Y:%f| end:|X:%f, Y:%f|\n", data->Walls[1].start.x,data->Walls[1].start.y, data->Walls[1].end.x, data->Walls[1].end.y);
			printf("start:|%d| end:|%d|\n", data->Leaves[0].start,data->Leaves[0].end);
	printf("############################\n");
	width = SCREEN_WIDTH;
	while (!data->quit)
	{
	draw_walls_from_bsp(data);
	data->pixels[(int)data->p.pos.x + (int)data->p.pos.y * SCREEN_WIDTH] = 0xffffff;
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
