/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:48:21 by acostaz           #+#    #+#             */
/*   Updated: 2019/10/01 15:51:23 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../hdr/png.h"

int			read_chunk_type_and_length(int fd, char *length, char *type)
{
	if (read(fd, length, 4) < 4
			|| read(fd, type, 4) < 4)
		return (print_error("Not enough data :(\n"));
	reverse_int((unsigned int*)length);
	return (OK);
}

int			alloc_img_and_data(t_png **img, char **data, int length)
{
	if ((!*img && !(*img = (t_png*)ft_memalloc(sizeof(t_png)))))
		return (print_error("Could not alloc a t_png"));
	if (!(*data = ft_strnew(length)))
	{
		free(img);
		return (print_error("Could not alloc a data chunk"));
	}
	return (OK);
}
