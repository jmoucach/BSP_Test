/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:17:05 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/04 15:50:42 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "/usr/include/SDL2/SDL.h"
# include "struct.h"
# include "proto.h"
# include "png.h"
# include "../libft/inc/libft.h"

# include <fcntl.h>
# include <math.h>

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 800

# define C_FRONT 1
# define C_BACK -1
# define C_SPANNING 0
# define C_ALIGN 2

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
	struct s_BSPNode *parent;
	struct s_BSPNode *front;
	struct s_BSPNode *back;
}				t_BSPNode;


t_wall create_emptywall(void);
t_wlist *dup_wlist(t_wlist *l);
t_wall create_wall(t_vertex start, t_vertex end, t_vertex normal);
t_vertex wall_wall_intersection(t_wall w1, t_wall w2);
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
void draw_2dwall(t_data *data, t_wall wall, int color);
void	draw_walls_from_bsp(t_BSPNode *bsp, t_data *data, int level);
void	draw_bin_tree(t_data *data, t_BSPNode *node, int level, t_point point);

int choose_best_splitter(t_wlist *list);
int get_splitter_score(t_wlist *candidate, t_wlist *list);
void splitwall(t_wall wall, t_wall splitter, t_wlist **frontsplit,
	t_wlist **backsplit);
t_BSPNode *bspcompiler(t_wlist *walls);
void	get_bsp_parents(t_BSPNode *bsp);
void	draw_3d_walls(t_data *data, t_BSPNode *bsp);

void	make_some_walls(t_wlist **walls);


#endif
