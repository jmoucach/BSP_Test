/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:20:06 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/12 15:13:12 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void increment_nodes(t_data *data)
{
	data->NumberOfNodes++;
	if (data->NumberOfNodes > data->MaxNodes)
	{
		printf("realloc nodes\n");
		data->MaxNodes += 10;
		data->Nodes = ft_realloc(data->Nodes, data->MaxNodes * sizeof(t_BSPNode));
	}
}

void increment_walls(t_data *data)
{
	data->NumberOfWalls++;
	if (data->NumberOfWalls > data->MaxWalls)
	{
		printf("realloc walls\n");
		data->MaxWalls += 10;
		data->Walls = ft_realloc(data->Walls, data->MaxWalls * sizeof(t_wall));
	}
}

void increment_leaves(t_data *data)
{
	data->NumberOfLeaves++;
	if (data->NumberOfLeaves > data->MaxLeaves)
	{
		printf("realloc leaves\n");
		data->MaxLeaves += 10;
		data->Leaves = ft_realloc(data->Leaves, data->MaxLeaves * sizeof(t_wall));
	}
}