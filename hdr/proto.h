/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:03:28 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/12 14:46:45 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "wolf3d.h"

/*
** INIT
*/

short			create_renderer_texture_and_pixels(t_data *data);
void			nullify_surfaces(t_data *data);
short			init(t_data *data);
void			set_values(t_data *data);
void			set_raycast_values(t_raycast *value, t_player player, int x);

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
void			game_loop(t_data *data);

/*
** Show player
*/

void			show_player(t_data *data, t_point length);

/*
** Raycasting
*/

void			give_draw_values(t_raycast *values, t_data *data);
void			get_texturing_values(t_raycast *values, t_data *data);
void			set_dist_and_step(t_raycast *values);
void			hit_wall(t_raycast *values, t_data *data);
void			raycasting(t_data *data);

/*
** Load image
*/

Uint32			get_pixel(SDL_Surface *s, int x, int y);
SDL_Surface		*loadimage(char *path);
short			loadmedia(t_data *data);

/*
** Parsing
*/

short			count_lines_and_col(t_data *data, char *str);
short			parse_boudaries(char *str, t_data *data);
short			parse_map(t_data *data, char *str);
short			parse_char(char *str);

/*
** Floor caster
*/

void			floor_side(t_floorcast *f, t_raycast *r);
void			roofcaster(t_data *data, t_raycast *r, int x);
void			floorcaster(t_data *data, t_raycast *r, int x);

/*
** movement
*/

void			strafe(t_data *data, int strafe);
void			walk(t_data *data, int walkdir);
void			sprint(t_data *data, int sprintdir);
void			rotate(t_data *data, int rotdir);

#endif
