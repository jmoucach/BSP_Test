/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:55:06 by sjulliot          #+#    #+#             */
/*   Updated: 2019/12/02 13:01:55 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PNG_H
# define PNG_H

# include "../libft/inc/libft.h"

# define OK					0
# define PB					-1
# define OVER				1

# define MAX_WIDTH			1024
# define MAX_HEIGHT			1024

# define GREYSCALE			0
# define TRUECOLOR			2
# define INDEXED			3
# define GREY_WITH_ALPHA	4
# define TRUE_WITH_ALPHA	6

# define NO_FILTER			0
# define FILTER_SUB			1
# define FILTER_UP			2
# define FILTER_AVG			3
# define FILTER_PAETH		4

# define BPP				4

# define NO_COMPRESSION		0
# define FIXED_HUFFMAN		1
# define DYNAMIC_HUFFMAN	2
# define RESERVED			3

# define FIRST_BIT_MASK		0x01
# define SECOND_BIT_MASK	0x02
# define THIRD_BIT_MASK		0x04

typedef struct		s_block_header
{
	char			bfinal;
	char			btype;
	unsigned short	len;
	unsigned short	nlen;
}					t_block_header;

typedef struct		s_buffer
{
	unsigned int	len;
	char			*data;
}					t_buffer;

typedef struct		s_plte
{
	unsigned char	len;
	char			*values;
}					t_plte;

typedef union		u_color
{
	unsigned int	number;
	unsigned char	channel[4];
}					t_color;

/*
** WARNING : DO NOT CHANGE ORDER, used in parsing
*/
typedef struct		s_png
{
	unsigned int	width;
	unsigned int	height;
	char			depth;
	char			color_type;
	char			compression_method;
	char			filter_method;
	char			interlace_method;
	t_plte			plte;
	t_color			*pixels;
	t_list			*data_blocks;
}					t_png;

typedef struct		s_img
{
	unsigned int	width;
	unsigned int	height;
	t_color			**pixels;
}					t_img;

/*
** process_ihdr.c
*/
int					process_ihdr(char *data, unsigned int len, t_png *img);

/*
** png_utils.c
*/
int					alloc_img_tab(t_img *img);
int					alloc_pixels(t_png *img, size_t len);
int					print_error(char *msg);
void				reverse_int(unsigned int *val);
void				free_png(t_png *png);

/*
** png_utils2.c
*/
int					read_chunk_type_and_length(int fd,
												char *length,
												char *type);
int					alloc_img_and_data(t_png **img, char **data, int length);

/*
** process_idat.c
*/
int					uncompress_data_blocks(t_png *img);
int					process_idat(char *data, unsigned int len, t_png *img);

/*
** process_plte.c
*/
int					process_plte(char *data, unsigned int len, t_png *img);

/*
** check_png_signature.c
*/
int					check_png_signature(int fd);

/*
** idat_block_extraction.c
*/
int					extract_one_block(t_buffer *buffer,
										unsigned int *content_len,
										unsigned int *total_read_len,
										t_png *img);
/*
** idat_utils.c
*/
t_buffer			buffer_init(unsigned int len, char *data);
void				move_buffer(t_buffer *buffer, int offset);
size_t				compute_total_length(t_list *data_blocks);
void				free_block(void *data, size_t len);

/*
** parse_png.c
*/
int					parse_png(char *filename, t_img *img);

/*
** post_processing.c
*/
void				post_process_lines(t_img *img);

/*
** unfiltering.c
*/
int					unfilter_line(unsigned char *filtered_row,
									int len,
									unsigned char *to,
									unsigned char *last_unfiltered_raw);
/*
** unfiltering_utils.c
*/
int					paeth(int a, int b, int c);

/*
** zlib.c
*/
int					process_zlib_headers(char **data, size_t *len);

#endif
