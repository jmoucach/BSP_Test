/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestsplitter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:38:35 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/22 16:10:30 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

int get_splitter_score(t_wlist *candidate, t_wlist *list)
{
	int splits;
	int frontfacing;
	int backfacing;
	int output;

	splits = 0;
	frontfacing = 0;
	backfacing = 0;
	while (list)
	{
		if (list->id != candidate->id)
		{
			output = classifywall(list->wall, candidate->wall);
			if (output == C_FRONT)
				frontfacing++;
			else if (output == C_ALIGN)
			{
				frontfacing++;
				backfacing++;
			}
			else if (output == C_BACK)
				backfacing++;
			else
				splits++;
		}
		list = list->next;
	}
	return (ft_abs(frontfacing - backfacing) + (splits * 8));
}

int choose_best_splitter(t_wlist *list)
{
	int score;
	int best_score;
	int id_of_best;
	t_wlist *head;

	best_score = -1;
	id_of_best = -1;
	head = list;
	while (list)
	{
		if (list->isUsed == 0)
		{
			score = get_splitter_score(list, head);
			// ft_printf("score = %d, id = %d\n", score, list->id);
			if (score < best_score || best_score == -1)
			{
				best_score = score;
				id_of_best = list->id;
			}
		}
		list = list->next;
	}
	return (id_of_best);
}
