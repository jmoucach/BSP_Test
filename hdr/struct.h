/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:19:39 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/02 13:01:52 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "doom.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_parse
{
	int				i;
	int				col;
	int				tmp;
}					t_parse;

typedef struct		s_vertex
{
	double			x;
	double			y;
}					t_vertex;

typedef struct		s_line_param
{
	t_point			diff;
	t_point			inc;
	int				error;
	int				off;
}					t_line_param;

typedef struct		s_ray
{
	t_vertex		pos;
	t_vertex		dir;
}					t_ray;

typedef struct		s_player
{
	double			angle;
	t_vertex		plane;
	t_vertex		pos;
	t_vertex		dir;
	double			walkspeed;
	double			sprintspeed;
	double			rspeed;
}					t_player;

typedef struct		s_raycast
{
	t_ray			ray;
	double			camera;
	t_point			m_pos;
	t_vertex		sidedist;
	t_vertex		deltadist;
	t_point			step;
	int				hit;
	double			wall;
	int				side;
	int				texh;
	int				texw;
	int				texnum;
	t_point			tex;
	int				lineheight;
	Uint32			color;
	int				drawstart;
	int				drawend;
	double			walldist;
}					t_raycast;

typedef struct		s_floorcast
{
	t_vertex		floor;
	t_vertex		currentfloor;
	t_point			floortex;
	double			currentdist;
	double			weight;
}					t_floorcast;

typedef struct		s_data
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Surface		**surface;
	Uint32			*pixels;
	double			ftime;
	int				yaw;
	t_player		p;
	double			sensitivity;
	int				**map;
	t_point			msize;
	short			toggle_minimap;
	short			quit;
	char			filled[1280];
}					t_data;

#endif
