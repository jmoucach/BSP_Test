/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:07:10 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/04 16:16:03 by acostaz          ###   ########.fr       */
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
//	t_wlist *head;
//	t_wlist *tmp;
//	t_vertex	unit;
	t_BSPNode	*bsp;
	int i=0;

	walls = NULL;

	make_some_walls(&walls);
/*	while (i < 10)
	{
		tmp  = new_wlist((t_wall){(t_vertex){(i+1)*50, 50}, (t_vertex){(i+1)*50, 500}, (t_vertex){0, 0}}, i);
		unit = unit_vertex(substract_vertex(tmp->wall.end, tmp->wall.start));
		tmp->wall.normal = perp_vertex(unit);
		add_wlist(&walls, tmp);
		i++;
	}
	tmp = new_wlist((t_wall){(t_vertex){(220), 50}, (t_vertex){50, 300}, (t_vertex){0, 0}}, i);
	unit = unit_vertex(substract_vertex(tmp->wall.end, tmp->wall.start));
		tmp->wall.normal = perp_vertex(unit);
		add_wlist(&walls, tmp);*/
	bsp = bspcompiler(walls);
//	head = walls;
	width = SCREEN_WIDTH;
//	int best = choose_best_splitter(walls);
	while (!data->quit)
	{
		i = 0;
/*	while (walls)
	{
		if (walls->id == best)
			draw_2dwall(data, walls->wall, 0xff0000);
		else
			draw_2dwall(data, walls->wall, 0xffffff);
		walls = walls->next;
	}*/

	t_point	point;
	point.x = 3 * SCREEN_WIDTH / 4;
	point.y = 50;
	draw_walls_from_bsp(bsp, data, 0);
	draw_bin_tree(data, bsp, 0, point);
	data->pixels[350 + 300 * SCREEN_WIDTH] = 0xffffff;
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
//		walls = head;
	}
}
