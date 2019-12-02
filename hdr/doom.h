/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:17:05 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/02 14:22:40 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "SDL.h"
# include "struct.h"
# include "proto.h"
# include "png.h"
# include "../libft/inc/libft.h"

# include <fcntl.h>
# include <math.h>

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define C_FRONT 1;
# define C_BACK -1;
# define C_SPANNING 0;

typedef struct s_wall
{
	t_vertex	start;
	t_vertex	end;
	t_vertex	normal;
}				t_wall;

typedef struct s_wlist
{
	int			id;
	t_wall		wall;
	struct s_wlist	*next;
	struct s_wlist	*prev;
}				t_wlist;

typedef struct s_BSPNode
{
	t_wall		wall;
	struct s_BSPNode *front;
	struct s_BSPNode *back;
}				t_BSPNode;


void remove_wlist(t_wlist **list, int id);
void add_wlist(t_wlist **list, t_wlist *new);
t_wlist *new_wlist(t_wall wall, int id);
int classifywall(t_wall w1, t_wall w2);
int classifypoint(t_vertex pt, t_wall wall);
double dotproduct(t_vertex v1, t_vertex v2);
t_vertex add_vertex(t_vertex v1, t_vertex v2);
t_vertex create_vertex(double x, double y);
t_vertex unit_vertex(t_vertex v);
t_vertex perp_vertex(t_vertex v);
t_vertex substract_vertex(t_vertex v1, t_vertex v2);
void draw_2dwall(t_data *data, t_wall wall);


#endif