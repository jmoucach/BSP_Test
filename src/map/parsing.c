/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:15:24 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/11 10:17:59 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/wolf3d.h"

short			parse_char(char *str)
{
	int			i;
	int			p_num;

	i = 0;
	p_num = 0;
	while (str[i])
	{
		if (str[i] == 'P')
		{
			p_num++;
		}
		else if (str[i] != '0' && str[i] != '1' && str[i] != ','
			&& str[i] != '2' && str[i] != '3')
		{
			ft_putendl_fd("Invalid map data", 2);
			return (0);
		}
		i++;
	}
	if (p_num != 1)
	{
		ft_putendl_fd("Invalid number of player", 2);
		return (0);
	}
	return (1);
}

short			parse_boudaries(char *str, t_data *data)
{
	int			x;
	int			y;

	y = 0;
	while (y < data->msize.y)
	{
		if (str[2 * (y * data->msize.x)] != '1'
			|| str[2 * (y * data->msize.x + data->msize.x - 1)] != '1')
		{
			ft_putendl_fd("Incomplete Boundaries", 2);
			return (0);
		}
		y++;
	}
	x = -1;
	while (++x < data->msize.x)
	{
		if (str[2 * x] != '1'
			|| str[2 * (x + (data->msize.y - 1) * data->msize.x)] != '1')
		{
			ft_putendl_fd("Incomplete Boundaries", 2);
			return (0);
		}
	}
	return (1);
}

short			parse_map(t_data *data, char *str)
{
	if (parse_char(str) && parse_boudaries(str, data))
		return (1);
	else
		return (0);
}
