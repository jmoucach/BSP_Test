/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:14:06 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/30 14:27:58 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

int		name_parser(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (!ft_strequ((file_name + i - 5), ".wolf"))
	{
		ft_putendl("Invalid map_name");
		return (0);
	}
	return (1);
}

void	free_map(t_data *data)
{
	int i;

	i = data->msize.y - 1;
	while (i >= 0)
	{
		free(data->map[i]);
		i--;
	}
	free(data->map);
}

void	close_all(t_data *data)
{
	int i;

	i = 0;
	if (data->pixels)
		free(data->pixels);
	if (data->texture)
		SDL_DestroyTexture(data->texture);
	if (data->renderer)
		SDL_DestroyRenderer(data->renderer);
	if (data->window)
		SDL_DestroyWindow(data->window);
	SDL_Quit();
}

int		main(int ac, char **av)
{
	t_data data;
	t_wlist *walls;

	walls = NULL;
	(void)av;
	if (ac == 2)
	{
		set_values(&data);
		if (init(&data))
		{
				
					make_some_walls(&walls);
					game_loop(&data, walls);
					close_all(&data);
		}
		else
		{
			ft_putstr_fd("Error in initialization!", 2);
		}
	}
	return (0);
}
