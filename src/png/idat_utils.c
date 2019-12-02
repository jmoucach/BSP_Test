/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idat_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:20:39 by sjulliot          #+#    #+#             */
/*   Updated: 2019/10/01 14:06:20 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libft/inc/libft.h"
#include "../../hdr/png.h"

void				free_block(void *data, size_t len)
{
	free(data);
	len++;
}

size_t				compute_total_length(t_list *data_blocks)
{
	size_t			total_length;

	total_length = 0;
	while (data_blocks)
	{
		total_length += data_blocks->content_size;
		data_blocks = data_blocks->next;
	}
	return (total_length);
}

t_buffer			buffer_init(unsigned int len, char *data)
{
	t_buffer		res;

	res.len = len;
	res.data = data;
	return (res);
}

void				move_buffer(t_buffer *buffer, int offset)
{
	buffer->len -= offset;
	buffer->data += offset;
}
