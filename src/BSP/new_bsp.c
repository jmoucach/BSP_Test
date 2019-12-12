/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bsp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:04:33 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/12 16:43:43 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

t_wlist *find_splitter(t_wlist *walls)
{
	int id;
	t_wlist *splitter;

	splitter = NULL;
	id = choose_best_splitter(walls);
	// printf("========best id:%d\n", id);
	if (id == -1)
		return splitter;
	while (walls)
	{
		if (walls->id == id)
		{
			splitter = walls;
			break;
		}
		walls = walls->next;
	}
	splitter->isUsed = 1;
	return (splitter);
}

void fillNodeArray(t_wlist **list, int NodeId, t_data *data)
{
		data->Leaves[data->NumberOfLeaves].start = data->NumberOfWalls;
		printf("~~~~~~~~~~~~~~~~~~leaf[%d] start:%d\n", data->NumberOfLeaves, data->Leaves[data->NumberOfLeaves].start);
		while (*list != NULL)
		{
			printf("wall id:%d wall index:%d, start:|X:%f, Y:%f| end:|X:%f, Y:%f|\n", (*list)->id,data->NumberOfWalls, (*list)->wall.start.x,(*list)->wall.start.y, (*list)->wall.end.x, (*list)->wall.end.y);
			data->Walls[data->NumberOfWalls] = create_wall((*list)->wall.start, (*list)->wall.end, (*list)->wall.normal);
			increment_walls(data);
			printf("Number of walls:%d\n", data->NumberOfWalls);
			remove_wlist(list, (*list)->id);
		}
		data->Leaves[data->NumberOfLeaves].end = data->NumberOfWalls;
		printf("~~~~~~~~~~~~~~~~~~leaf[%d] end:%d\n", data->NumberOfLeaves, data->Leaves[data->NumberOfLeaves].end);
		data->Nodes[NodeId].isleaf = 1;
		data->Nodes[NodeId].front = data->NumberOfLeaves;
		increment_leaves(data);
}

void new_bspcompiler(t_wlist *walls, int NodeId, t_data *data)
{
	t_wlist *splitter;
	t_wlist *head;
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
	if (!(splitter = find_splitter(walls)))
		return ;
	data->Nodes[NodeId].wall = create_wall(splitter->wall.start, splitter->wall.end, splitter->wall.normal);
	head = walls;
	while (walls)
	{
		next = walls->next;
		// // printf("wall[%d]\n", walls->id);
		classified = classifywall(walls->wall, splitter->wall);
		if (classified == C_FRONT || classified == C_ALIGN)
			add_wlist(&front, dup_wlist(walls));
		else if (classified == C_BACK)
			add_wlist(&back, dup_wlist(walls));
		else
		{
			front_split = new_wlist(create_emptywall(), 0);
			back_split = new_wlist(create_emptywall(), 0);
			splitwall(walls, splitter->wall, &front_split, &back_split);
			add_wlist(&front, dup_wlist(front_split));
			add_wlist(&back, dup_wlist(back_split));
			// printf("split\n");
			remove_wlist(&walls, walls->id);
		}
		walls = next;
	}
	walls = head;
	int count = count_unused(front);
	if (count == 0)
	{
		fillNodeArray(&front, NodeId, data);
		printf("outside\n");
		printf("~~~~~~~~~~~~~~~~~~leaf[%d] start:%d\n", data->NumberOfLeaves - 1, data->Leaves[data->NumberOfLeaves - 1].start);
		printf("~~~~~~~~~~~~~~~~~~leaf[%d] end:%d\n", data->NumberOfLeaves -1, data->Leaves[data->NumberOfLeaves -1 ].end);
	}
	else
	{
		data->Nodes[NodeId].isleaf = 0;
		data->Nodes[NodeId].front = data->NumberOfNodes + 1;
		increment_nodes(data);
		// printf("front:%ld\n", data->Nodes[NodeId].front);
		new_bspcompiler(front, data->NumberOfNodes, data);
	}

	if (back == NULL)
		data->Nodes[NodeId].back = -1;
	else
	{
		data->Nodes[NodeId].back = data->NumberOfNodes + 1;
		increment_nodes(data);
		// printf("back:%ld\n", data->Nodes[NodeId].back);
		new_bspcompiler(back, data->NumberOfNodes, data);
	}
}