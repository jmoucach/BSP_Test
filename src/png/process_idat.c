/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_idat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:08:53 by sjulliot          #+#    #+#             */
/*   Updated: 2019/10/01 11:26:34 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/inc/libft.h"
#include "../../libft/inc/ft_printf.h"

#include "../../hdr/png.h"

static int			extract_uncompressed_data(char *data, unsigned int len,
																	t_png *img)
{
	unsigned int	content_len;
	unsigned int	total_read_len;
	int				ret;
	t_buffer		buffer;

	content_len = 0;
	total_read_len = 0;
	buffer = buffer_init(len, data);
	ret = OK;
	while (0 < len && ret == OK)
	{
		ret = extract_one_block(&buffer, &content_len, &total_read_len, img);
		if (ret == PB)
			return (print_error("Could not extract a block"));
	}
	if (len < 4)
		return (print_error("Incomplete file, missing ADLER32\n"));
	return (OK);
}

static int			compactify(t_list *data_blocks, char **data, size_t *len)
{
	char			*data_pos;

	*len = compute_total_length(data_blocks);
	if (!(*data = (char*)malloc(sizeof(char) * (*len))))
		return (PB);
	data_pos = *data;
	while (data_blocks)
	{
		if (!ft_memcpy(data_pos,
					data_blocks->content,
					data_blocks->content_size))
			return (PB);
		data_pos += data_blocks->content_size;
		data_blocks = data_blocks->next;
	}
	return (OK);
}

static int			uncompress_data(t_png *img, char *data, size_t len)
{
	if (process_zlib_headers(&data, &len) == PB)
		return (print_error("Error processing zlib headers"));
	if (alloc_pixels(img, len) == PB)
		return (print_error("Error allocating pixels"));
	if (extract_uncompressed_data(data, len, img) == PB)
		return (print_error("Error extracting uncompressed data"));
	return (OK);
}

int					uncompress_data_blocks(t_png *img)
{
	char			*data;
	size_t			len;
	int				ret;

	if (compactify(img->data_blocks, &data, &len) == PB)
		return (PB);
	ret = uncompress_data(img, data, len);
	free(data);
	return (ret);
}

int					process_idat(char *data, unsigned int len, t_png *img)
{
	ft_lstapp(&(img->data_blocks), ft_lstnew((void*)data, len));
	return (OK);
}
