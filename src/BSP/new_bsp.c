/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bsp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:04:33 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/09 13:21:51 by jmoucach         ###   ########.fr       */
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
		while (*list != NULL)
		{
			printf("id : %d to index :%d\n", (*list)->id, data->NumberOfWalls);
			data->Walls[data->NumberOfWalls] = create_wall((*list)->wall.start,
				(*list)->wall.end, (*list)->wall.normal);
			increment_walls(data);
			remove_wlist(list, (*list)->id);
		}
		data->Leaves[data->NumberOfLeaves].end = data->NumberOfWalls;
		data->Nodes[NodeId].isleaf = 1;
		data->Nodes[NodeId].front = data->NumberOfLeaves;
		increment_leaves(data);
}


void nextStepFront(t_wlist **front,int NodeId, t_data *data)
{
	int count = count_unused(*front);
	if (count == 0)
		fillNodeArray(front, NodeId, data);
	else
	{
		data->Nodes[NodeId].isleaf = 0;
		data->Nodes[NodeId].front = data->NumberOfNodes + 1;
		increment_nodes(data);
		new_bspcompiler(front, data->NumberOfNodes, data);
	}
}

void nextStepBack(t_wlist **back, int NodeId, t_data *data)
{
	if (*back == NULL)
		data->Nodes[NodeId].back = -1;
	else
	{
		data->Nodes[NodeId].back = data->NumberOfNodes + 1;
		increment_nodes(data);
		new_bspcompiler(back, data->NumberOfNodes, data);
	}
}

void printlistid(t_wlist *list)
{
	while (list)
	{
		printf("list id:%d | ", list->id);
		list = list->next;
	}
	printf("\n");
}

void CompareWalls(t_wlist **walls, t_wlist *splitter, t_bsputil *utils)
{
	int classified;
	t_wlist *ptr;
	t_wlist *next;

	ptr = *walls;
	while (ptr)
	{
		next = ptr->next;
		if (ptr->isUsed == 1)
			addback_wlist(&(utils->front), dup_wlist(ptr));
		else
		{		
		classified = classifywall(ptr->wall, splitter->wall);
		if (classified == C_FRONT || classified == C_ALIGN)
			addback_wlist(&(utils->front), dup_wlist(ptr));
		else if (classified == C_BACK)
			addback_wlist(&(utils->back), dup_wlist(ptr));
		else
		{
			utils->front_split = new_wlist(create_emptywall(), 0);
			utils->back_split = new_wlist(create_emptywall(), 0);
			splitwall(ptr, splitter->wall, &(utils->front_split), &(utils->back_split));
			addback_wlist(&(utils->front), dup_wlist(utils->front_split));
			addback_wlist(&(utils->back), dup_wlist(utils->back_split));
			remove_wlist(&ptr, ptr->id);
		}
		}
		ptr = next;
	}
}

void new_bspcompiler(t_wlist **walls, int NodeId, t_data *data)
{
	t_wlist *splitter;
	t_bsputil utils;

	utils.front_split = NULL;
	utils.back_split = NULL;
	utils.front = NULL;
	utils.back = NULL;
	if (!(splitter = find_splitter(*walls)))
		return ;
	data->Nodes[NodeId].wall = create_wall(splitter->wall.start, splitter->wall.end, splitter->wall.normal);
	CompareWalls(walls, splitter, &utils);
	nextStepFront(&(utils.front), NodeId, data);
	nextStepBack(&(utils.back), NodeId, data);
}

void printtree(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->NumberOfLeaves)
	{
		j = 0;
		while (data->Leaves[i].start + j < data->Leaves[i].end)
		{
			printf("index: %d\n", data->Leaves[i].start + j);
			print_wall(data->Walls[data->Leaves[i].start + j]);
			j++;
		}
		i++;
	}
}
