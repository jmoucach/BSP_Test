/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp_compiler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:12:12 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/03 17:54:06 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

t_BSPNode *bspcompiler(t_wlist *walls)
{
	t_wlist *splitter;
	t_wlist *head;
	t_wlist *front;
	t_wlist *back;
	t_wlist *next;
	int id;
	int classified;
	t_BSPNode *node;
	t_wlist *front_split;
	t_wlist *back_split;

	if (!(node = (t_BSPNode*)malloc(sizeof(t_BSPNode))))
		return (NULL);

	front_split = new_wlist(create_emptywall(),0);
	back_split = new_wlist(create_emptywall(),0);
		front = NULL;
		back = NULL;
		splitter = NULL;
	head = walls;
	id = choose_best_splitter(walls);
	while (walls)
	{
		if (walls->id == id)
		{
			splitter = walls;
			break ;
		}
		walls = walls->next;
	}
	node->wall = create_wall(walls->wall.start, walls->wall.end, walls->wall.normal);
	walls = head;
	while (walls)
	{
		next = walls->next;
		if (walls->id != splitter->id)
		{
			classified = classifywall(walls->wall, splitter->wall);
			if (classified == C_FRONT || classified == C_ALIGN)
				add_wlist(&front, dup_wlist(walls));
			else if (classified == C_BACK)
				add_wlist(&back, dup_wlist(walls));
			else
			{
				splitwall(walls->wall, splitter->wall, &front_split, &back_split);
				add_wlist(&front, dup_wlist(front_split));
				add_wlist(&back, dup_wlist(back_split));
			}
		}
		walls = next;
	}
	if (front != NULL)
	{
		printf("down front\n");
		node->front = bspcompiler(front);
	}
	else
	{
		printf("up front\n");
		node->front = NULL;
	}
	if (back != NULL)
	{
		printf("down back\n");
		node->back = bspcompiler(back);
	}
	else
	{
		printf("up back\n");
		node->back = NULL;
	}
	return (node);
}