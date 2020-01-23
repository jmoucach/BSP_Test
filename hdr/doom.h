/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:17:05 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/21 13:28:23 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "/Users/jmoucach/.brew/include/SDL2/SDL.h"
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
	short		isUsed;
	struct s_wlist	*next;
}				t_wlist;

typedef struct s_box
{
	t_vertex Min;
	t_vertex Max;
}				t_box;

typedef struct s_BSPNode
{
	t_wall		wall;
	short isleaf;
	int front;
	int	 back;
	t_box	boundingbox;
}				t_BSPNode;

typedef struct s_leaf
{
	int start;
	int end;
	int PVS_index;
	int Portal_index[50];
	int NumberOfPortals;
	t_box	boundingbox;
}				t_leaf;

typedef struct s_portal
{
	short NumberOfLeaves;
	t_vertex start;
	t_vertex end;
	int LeafOwners[2];
	struct s_portal *next;
}				t_portal;

typedef struct s_bsputil
{
	t_wlist *front;
	t_wlist *back;
	t_wlist *front_split;
	t_wlist *back_split;
}				t_bsputil;

void			game_loop(t_data *data, t_wlist *walls);

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
void	draw_walls_from_bsp(t_data *data);
void	draw_bin_tree(t_data *data, t_BSPNode *node, int level, t_point point);

int choose_best_splitter(t_wlist *list);
int get_splitter_score(t_wlist *candidate, t_wlist *list);
void splitwall(t_wlist *list, t_wall splitter, t_wlist **frontsplit,
	t_wlist **backsplit);
t_BSPNode *bspcompiler(t_wlist *walls);
void	draw_3d_walls(t_data *data, t_BSPNode *bsp);



void addback_wlist(t_wlist **list, t_wlist *new);
void	make_some_walls(t_wlist **walls);
int get_wlist_length(t_wlist *list);
void print_wlist(t_wlist *list);

// increment.c
void increment_nodes(t_data *data);
void increment_walls(t_data *data);
void increment_leaves(t_data *data);
void increment_portals(t_data *data);
//

//
void new_bspcompiler(t_wlist **walls, int NodeId, t_data *data);
int count_unused(t_wlist *list);
void *ft_realloc(void *ptr, size_t size);
void print_wall(t_wall wall);
void printtree(t_data *data);
//

void Calculatebox_list(t_box *box, t_wlist *list);
void Calculatebox_wall(t_box *box, t_wall wall);

void draw_boudingbox(t_data *data, t_box box, int colour);
t_wall expand_wall_to_boundingbox(t_box box, t_wall wall);

//
t_portal *dup_portal(t_portal *portal);
void dup_portal_data(t_portal *portal, t_portal**dup);
void splitportal(t_portal *portal, t_portal **front, t_portal **back, t_data *data, int NodeId);
t_portal *clip_portal(t_portal *portal, t_data *data, int NodeId);
t_portal *find_initial_portal(t_data *data, int NodeId);
short check_dup_portal(t_data *data, t_portal *portal);
//
#endif
