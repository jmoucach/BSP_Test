/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_png.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:54:05 by sjulliot          #+#    #+#             */
/*   Updated: 2019/10/01 15:51:10 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "../../libft/inc/libft.h"
#include "../../libft/inc/ft_printf.h"
#include "../../hdr/png.h"

static int			process_chunk_data(char *chunk_type, char *data,
												unsigned int len, t_png *res)
{
	if (ft_strnequ(chunk_type, "IHDR", 4))
		return (process_ihdr(data, len, res));
	else if (ft_strnequ(chunk_type, "IDAT", 4))
		return (process_idat(data, len, res));
	return (OK);
}

static int			process_chunk(int fd, t_png **img)
{
	int				length;
	char			chunk_type[4];
	char			*data;
	char			crc[4];
	int				ret;

	if (read_chunk_type_and_length(fd, (char*)(&length), chunk_type) == PB)
		return (print_error("Could not read chunk type or length"));
	if (ft_strnequ(chunk_type, "IEND", 4))
		return (OVER);
	if (alloc_img_and_data(img, &data, length) == PB)
		return (PB);
	if (((ret = read(fd, data, length)) < length
			|| (ret = read(fd, crc, 4)) < 4))
	{
		free(img);
		free(data);
		return (print_error("Could not read enough data"));
	}
	ret = process_chunk_data(chunk_type, data, length, *img);
	free(data);
	return (OK);
}

int					png_to_img(t_png *png, t_img *img)
{
	unsigned int	y;

	img->width = png->width;
	img->height = png->height;
	if (alloc_img_tab(img) == PB)
		return (print_error("Could not alloc img pixels tab"));
	y = -1;
	while (++y < png->height)
		unfilter_line((unsigned char*)png->pixels + (img->width * BPP + 1) * y,
						BPP * img->width,
						(unsigned char*)(img->pixels[y]),
						(y == 0) ? NULL : (unsigned char*)(img->pixels[y - 1]));
	post_process_lines(img);
	return (OK);
}

int					parse_png(char *filename, t_img *img)
{
	int				fd;
	int				ret;
	t_png			*png_img;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (print_error("Invalid filename"));
	if (check_png_signature(fd) == PB)
		return (print_error("Invalid file signature"));
	ret = OK;
	png_img = NULL;
	while (ret == OK)
		ret = process_chunk(fd, &png_img);
	if (ret == PB)
		return (print_error("An error occured processing a chunk"));
	if (uncompress_data_blocks(png_img) == PB)
		return (print_error("An error occured uncompressing data"));
	ret = png_to_img(png_img, img);
	free_png(png_img);
	return (ret);
}
