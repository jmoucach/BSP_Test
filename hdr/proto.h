/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:03:28 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/30 13:38:09 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "doom.h"

/*
** INIT
*/

short			create_renderer_texture_and_pixels(t_data *data);
void			nullify_surfaces(t_data *data);
short			init(t_data *data);
void			set_values(t_data *data);

/*
** Draw
*/

void			draw_rect_to_sdl(t_point pt_one, t_point pt_two,
	t_data *data, int colour);
void			setup_param(t_point pt_one, t_point pt_two,
	t_line_param *line_param);
void			drawline(t_point pt_one, t_point pt_two,
	t_data *data, int colour);

/*
** Main
*/

void			close_all(t_data *data);
int				name_parser(char *file_name);
void			free_map(t_data *data);

/*
** New map
*/

char			*join_strings(char *s1, char *s2);
short			count_lines_and_col(t_data *data, char *str);
short			allocate_map(t_data *data);
char			*read_map(int fd);
short			new_map(t_data *data, char *title);

/*
** Fill map
*/

void			print_map(t_data data);
short			fill_map(t_data *data, char *str);

/*
** Draw map box
*/

void			draw_minimap(t_data *data);

/*
** Event loop
*/

void			handle_input2(t_data *data, const Uint8 *state);
void			handle_input(t_data *data, const Uint8 *state);

/*
** Show player
*/

void			show_player(t_data *data, t_point length);

/*
** Parsing
*/

short			count_lines_and_col(t_data *data, char *str);
short			parse_boudaries(char *str, t_data *data);
short			parse_map(t_data *data, char *str);
short			parse_char(char *str);

#endif
