/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bsp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:04:33 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/09 18:16:36 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

int count_unused(t_wlist *list)
{
	int count;

	count = 0;
	while (list)
	{
		if (list->isUsed == 0)
			count++;
		list = list->next;
	}
	return (count);
}

void *ft_realloc(void *ptr, size_t size)
{
	char *new_ptr;

	if (!(new_ptr = malloc(size)))
		return (NULL);
	ft_memmove(new_ptr, ptr, size);
	return (new_ptr);
}

void new_bspcompiler(t_wlist *walls, long NodeId, t_data *data)
{
	t_wlist *splitter;
	t_wlist *head;
	int id;
	t_wlist *front;
	t_wlist *back;
	t_wlist *next;
	t_wlist *front_split;
	t_wlist *back_split;
	int classified;

	front_split = NULL;
	back_split = NULL;
	front = NULL;
	back = NULL;
	splitter = NULL;
	head = walls;
	id = choose_best_splitter(walls);
	printf("========best id:%d\n", id);
	if (id == -1)
		return;
	while (walls)
	{
		if (walls->id == id)
		{
			splitter = walls;
			break;
		}
		walls = walls->next;
	}
	walls->isUsed = 1;
	walls = head;
	data->Nodes[NodeId].wall = create_wall(splitter->wall.start, splitter->wall.end, splitter->wall.normal);
	while (walls)
	{
		next = walls->next;
		printf("wall[%d]\n", walls->id);
		classified = classifywall(walls->wall, splitter->wall);
		if (classified != -1)
		{
			if (classified == C_FRONT || classified == C_ALIGN)
			{
				walls->next = front;
				front = walls;
			}
			else if (classified == C_BACK)
			{
				walls->next = back;
				back = walls;
			}
			else
			{
				front_split = new_wlist(create_emptywall(), 0);
				back_split = new_wlist(create_emptywall(), 0);
				splitwall(walls->wall, splitter->wall, &front_split, &back_split);
				printf("split\n");
				remove_wlist(&walls, walls->id);
				front_split->id = walls->id;
				back_split->id = walls->id;
				front_split->isUsed = walls->isUsed;
				back_split->isUsed = walls->isUsed;
				back_split->next = back;
				back = back_split;
				front_split->next = front;
				front = front_split;
			}
		}
		walls = next;
	}

	int count;
	t_wlist *tmp;
	walls = head;
	count = count_unused(front);
	if (count == 0)
	{
		data->Leaves[data->NumberOfLeaves].start = data->NumberOfWalls;
		while (walls)
		{
			next = walls->next;
			data->Walls[data->NumberOfWalls] = walls->wall;
			increment_walls(data);
			tmp = walls;
			remove_wlist(&walls, tmp->id);
			walls = next;
		}
		data->Leaves[data->NumberOfLeaves].end = data->NumberOfWalls;
		printf("number of walls:%d\n", data->NumberOfWalls);
		data->Nodes[NodeId].isleaf = 1;
		data->Nodes[NodeId].front = data->NumberOfLeaves;
		increment_leaves(data);
		printf("number of leaves:%d\n", data->NumberOfLeaves);
	}
	else
	{
		data->Nodes[NodeId].isleaf = 0;
		data->Nodes[NodeId].front = data->NumberOfNodes + 1;
		printf("front:%ld\n", data->Nodes[NodeId].front);
		increment_nodes(data);
		new_bspcompiler(front, data->NumberOfNodes, data);
	}
	if (back == NULL)
		data->Nodes[NodeId].back = -1;
	else
	{
		data->Nodes[NodeId].back = data->NumberOfNodes + 1;
		printf("back:%ld\n", data->Nodes[NodeId].back);
		increment_nodes(data);
		new_bspcompiler(back, data->NumberOfNodes, data);
	}
}