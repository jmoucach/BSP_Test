/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:07:10 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/02 10:51:19 by jmoucach         ###   ########.fr       */
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
	t_wall		*walls;
	t_vertex	unit;
	int i=0;

	walls = (t_wall*)malloc(sizeof(t_wall) * 10);
	while (i < 10)
	{
		walls[i] = (t_wall){(t_vertex){50 * (i+1), 50}, (t_vertex){50 * (i+1), 300}, (t_vertex){0, 0}};
		unit = unit_vertex(substract_vertex(walls[i].end, walls[i].start));
		walls[i].normal = perp_vertex(unit);
		printf("unit:x:%f, y:%f\n normal:x:%f, y:%f\n",unit.x, unit.y, walls[i].normal.x, walls[i].normal.y);
		printf("%d\n", classifywall((t_wall){(t_vertex){(220), 50}, (t_vertex){270, 300}, (t_vertex){0, 0}}, walls[i]));
		i++;
	}
	width = SCREEN_WIDTH;
	while (!data->quit)
	{
		i = 0;
	while (i < 10)
	{	
		draw_2dwall(data, walls[i]);
		i++;
	}
	draw_2dwall(data, (t_wall){(t_vertex){(220), 50}, (t_vertex){270, 300}, (t_vertex){0, 0}});
	data->pixels[45 + 45 * SCREEN_WIDTH] = 0xff;
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
	}
}
