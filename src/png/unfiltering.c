/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfiltering.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:53:03 by sjulliot          #+#    #+#             */
/*   Updated: 2019/09/30 15:10:49 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/png.h"
#include "../../libft/inc/libft.h"
#include "../../libft/inc/ft_printf.h"

static void	unfilter_sub(unsigned char *row,
							int len,
							unsigned char *to)
{
	int		i;

	ft_memcpy(to, row, BPP);
	i = 3;
	while (++i < len)
		to[i] = row[i] + to[i - BPP];
}

static void	unfilter_up(unsigned char *row,
						int len,
						unsigned char *to,
						unsigned char *up)
{
	int		i;

	if (!up)
		ft_memcpy(to, row, len);
	else
	{
		i = -1;
		while (++i < len)
			to[i] = (unsigned char)row[i] + (unsigned char)up[i];
	}
}

static void	unfilter_avg(unsigned char *row, int len, unsigned char *to,
															unsigned char *up)
{
	int		i;

	if (!up)
	{
		ft_memcpy(to, row, BPP);
		i = 3;
		while (++i < len)
			to[i] = row[i] + to[i - BPP] / 2;
	}
	else
	{
		i = -1;
		while (++i < BPP)
			to[i] = row[i] + up[i] / 2;
		i--;
		while (++i < len)
			to[i] = row[i] + (to[i - BPP] + up[i]) / 2;
	}
}

static void	unfilter_paeth(unsigned char *row, int len, unsigned char *to,
															unsigned char *up)
{
	int		i;

	if (up)
	{
		i = -1;
		while (++i < BPP)
			to[i] = (unsigned char)(row[i] + paeth(0, (int)up[i], 0));
		i--;
		while (++i < len)
			to[i] = (unsigned char)(row[i] + paeth(to[i - BPP],
															up[i],
															up[i - BPP]));
	}
	else
	{
		i = -1;
		while (++i < BPP)
			to[i] = row[i];
		i--;
		while (++i < len)
			to[i] = (unsigned char)(row[i] + paeth(to[i - BPP], 0, 0));
	}
}

int			unfilter_line(unsigned char *filtered_row,
							int len,
							unsigned char *to,
							unsigned char *last_unfiltered_row)
{
	char filtertype;

	filtertype = filtered_row[0];
	if (filtertype == NO_FILTER)
		ft_memcpy(to, filtered_row + 1, len);
	else if (filtertype == FILTER_SUB)
		unfilter_sub(filtered_row + 1, len, to);
	else if (filtertype == FILTER_UP)
		unfilter_up(filtered_row + 1, len, to, last_unfiltered_row);
	else if (filtertype == FILTER_AVG)
		unfilter_avg(filtered_row + 1, len, to, last_unfiltered_row);
	else if (filtertype == FILTER_PAETH)
		unfilter_paeth(filtered_row + 1, len, to, last_unfiltered_row);
	else
		return (PB);
	return (OK);
}
