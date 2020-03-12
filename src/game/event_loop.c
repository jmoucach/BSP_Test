/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:07:10 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/30 16:20:34 by jmoucach         ###   ########.fr       */
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
}

void handle_input(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_ESCAPE])
		data->quit = 1;
	handle_input2(data, state);
}

void game_loop(t_data *data, t_wlist *walls)
{
	const Uint8 *state;
	int width;
	double time;
	// t_portal *head;
	// t_portal *list;
	new_bspcompiler(&walls, data->NumberOfNodes, data);
	printf("Number of Nodes :%d\n", data->NumberOfNodes);
	printf("Number of Leaves :%d\n", data->NumberOfLeaves);
	printf("Number of Walls :%d\n", data->NumberOfWalls);
	// printf("Number of Leaves :%d\n", data->NumberOfLeaves);
	data->Walls = ft_realloc(data->Walls, data->NumberOfWalls * sizeof(t_wall));
	width = SCREEN_WIDTH;
	// head= find_initial_portal(data, 0);
	// clip_portal(&head, data, 0);
	while (!data->quit)
	{
		// list = head;
		// int i = -1;
		// while (++i < data->NumberOfNodes)
		// {
		draw_walls_from_bsp(data);
			// while (list)
			// {
			// 	draw_2dwall(data, (t_wall){list->start, list->end, (t_vertex){0,0}}, 0xff0000);
				// printf("(X:%f, Y:%f),(X:%f, Y:%f)\n", list->start.x, list->start.y, list->end.x, list->end.y);
				// printf("owners :%d %d\n", list->LeafOwners[0], list->LeafOwners[1]);
			// 	list = list->next;
			// }
			// free(portal);
		// }
		// draw_2dwall(data, expand_wall_to_boundingbox(data->Leaves[0].boundingbox, data->Walls[1]), 0xffffff);
		// int i = -1;
		// while (++i < data->NumberOfNodes)
		// 	draw_boudingbox(data, data->Nodes[i].boundingbox, 0x00ff00);
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
