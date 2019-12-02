/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfiltering_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:56:59 by sjulliot          #+#    #+#             */
/*   Updated: 2019/09/30 15:03:59 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			paeth(int a, int b, int c)
{
	int		p;
	int		pa;
	int		pb;
	int		pc;

	p = a + b - c;
	pa = (p > a) ? p - a : a - p;
	pb = (p > b) ? p - b : b - p;
	pc = (p > c) ? p - c : c - p;
	if (pa <= pb && pa <= pc)
		return (a);
	if (pb <= pc)
		return (b);
	return (c);
}
