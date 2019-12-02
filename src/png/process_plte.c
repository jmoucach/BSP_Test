/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_plte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:03:43 by sjulliot          #+#    #+#             */
/*   Updated: 2019/09/30 16:16:32 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/inc/libft.h"
#include "../../hdr/png.h"

int			process_plte(char *data, unsigned int len, t_png *img)
{
	t_plte			plte;

	if (len % 3 != 0 || len > 256 * 3)
		return (PB);
	plte.len = (char)len;
	if (!(plte.values = ft_strndup(data, len)))
		return (PB);
	img->plte = plte;
	return (OK);
}
