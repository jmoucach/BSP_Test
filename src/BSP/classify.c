/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:44:48 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/03 16:28:18 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../hdr/doom.h"

int classifypoint(t_vertex pt, t_wall wall)
{
	t_vertex dir;
	double result;

	dir = substract_vertex(pt, wall.start);
	result = dotproduct(dir, wall.normal);
	if (result > 0.001) 
		return C_FRONT;
	else if (result < -0.001)
		return C_BACK;
	else
		return C_SPANNING;
	
}

int classifywall(t_wall w1, t_wall w2)
{
	t_vertex dir1;
	t_vertex dir2;
	double result1;
	double result2;

	dir1 = substract_vertex(w1.start, w2.start);
	result1 = dotproduct(dir1, w2.normal);
	dir2 = substract_vertex(w1.end, w2.start);
	result2 = dotproduct(dir2, w2.normal);
	if (result1 > 0.001 && result2 > 0.001)
		return C_FRONT;
	else if (result1 < -0.001 && result2 < -0.001)
		return C_BACK;
	else if (result1 < -0.001 && result2 < 0.001 && result2 > -0.001)
		return C_BACK;
	else if (result1 > 0.001 && result2 < 0.001 && result2 > -0.001)
		return C_FRONT;
	else if (result2 < -0.001 && result1 < 0.001 && result1 > -0.001)
		return C_BACK;
	else if (result2 > 0.001 && result1 < 0.001 && result1 > -0.001)
		return C_FRONT;
	else if ((result1 < -0.001 && result2 > 0.001) || (result1 > 0.001
		&& result2 < -0.001))
		return C_SPANNING;
	else
		return C_ALIGN;
}