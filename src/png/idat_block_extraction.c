/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idat_block_extraction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:21:30 by sjulliot          #+#    #+#             */
/*   Updated: 2019/09/30 17:30:50 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/png.h"

static int			read_block_header(char *data, t_block_header *header)
{
	header->bfinal = data[0] & FIRST_BIT_MASK;
	header->btype = data[0] & (SECOND_BIT_MASK | THIRD_BIT_MASK);
	if (header->btype != NO_COMPRESSION)
		return (print_error(("Compressed image, I'm lost (the game).")));
	header->len = ((unsigned short)(data)[1] & 0x00FF)
								| (((unsigned short)(data)[2] * 256) & 0xFF00);
	header->nlen = ((unsigned short)(data)[3] & 0x00FF)
								| (((unsigned short)(data)[4] * 256) & 0xFF00);
	if (header->len + header->nlen != 65535)
		return (print_error("INVALID LENGTH"));
	return (OK);
}

int					extract_one_block(t_buffer *buffer,
										unsigned int *content_len,
										unsigned int *total_read_len,
										t_png *img)
{
	t_block_header	header;

	if (buffer->len <= 5 || read_block_header(buffer->data, &header) == PB)
		return (PB);
	*total_read_len += 5;
	move_buffer(buffer, 5);
	if (buffer->len < header.len)
		return (print_error("Block len is too ambitious.\n"));
	ft_memcpy((void*)(img->pixels) + *content_len, buffer->data, header.len);
	*content_len += header.len;
	*total_read_len += header.len;
	move_buffer(buffer, header.len);
	return (header.bfinal ? OVER : OK);
}
