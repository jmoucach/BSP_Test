/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:19:39 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/30 13:35:36 by jmoucach         ###   ########.fr       */
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

typedef struct		s_data
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	Uint32			*pixels;
	double			ftime;
	//
	struct s_BSPNode *Nodes;
	int NumberOfNodes;
	int MaxNodes;

	struct s_wall *Walls;
	int NumberOfWalls;
	int MaxWalls;

	struct s_leaf *Leaves;
	int NumberOfLeaves;
	int MaxLeaves;

	struct s_portal **Portals;
	int NumberOfPortals;
	int MaxPortals;
	//
	int				**map;
	t_point			msize;
	short			toggle_minimap;
	short			quit;
	char			filled[1280];
}					t_data;

#endif
