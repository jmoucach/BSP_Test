/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:51:49 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/11 10:18:11 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/wolf3d.h"

void			print_map(t_data data)
{
	int			i;
	int			j;

	i = 0;
	while (i < data.msize.y)
	{
		j = 0;
		while (j < data.msize.x)
		{
			ft_putnbr(data.map[i][j]);
			ft_putstr(", ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

short			fill_map(t_data *data, char *str)
{
	int			i;

	if (!parse_map(data, str))
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
		{
			data->p.pos.x = (i / 2) / data->msize.x + 0.5;
			data->p.pos.y = (i / 2) % data->msize.x + 0.5;
			data->map[(i / 2) / data->msize.x]
				[(i / 2) % data->msize.x] = 0;
		}
		else if (str[i] == '0' || str[i] == '1'
			|| str[i] == '2' || str[i] == '3')
		{
			data->map[(i / 2) / data->msize.x]
				[(i / 2) % data->msize.x] = str[i] - '0';
		}
		i++;
	}
	return (1);
}
