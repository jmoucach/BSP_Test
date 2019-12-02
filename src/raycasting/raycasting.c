/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:22:58 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/08 16:29:17 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/wolf3d.h"

void			set_dist_and_step(t_raycast *r)
{
	if (r->ray.dir.x < 0)
	{
		r->step.x = -1;
		r->sidedist.x = (r->ray.pos.x - r->m_pos.x) * r->deltadist.x;
	}
	else
	{
		r->step.x = 1;
		r->sidedist.x = (r->m_pos.x + 1.0 - r->ray.pos.x) * r->deltadist.x;
	}
	if (r->ray.dir.y < 0)
	{
		r->step.y = -1;
		r->sidedist.y = (r->ray.pos.y - r->m_pos.y) * r->deltadist.y;
	}
	else
	{
		r->step.y = 1;
		r->sidedist.y = (r->m_pos.y + 1.0 - r->ray.pos.y) * r->deltadist.y;
	}
}

void			get_texturing_values(t_raycast *r, t_data *data)
{
	if (r->side == 0)
	{
		r->walldist = fabs((r->m_pos.x - r->ray.pos.x + (1 - r->step.x) / 2)
			/ r->ray.dir.x);
		if (r->ray.dir.x > 0)
			r->texnum = 0;
		else
			r->texnum = 1;
		r->wall = r->ray.pos.y + r->walldist * r->ray.dir.y;
	}
	else
	{
		r->walldist = fabs((r->m_pos.y - r->ray.pos.y + (1 - r->step.y) / 2)
			/ r->ray.dir.y);
		if (r->ray.dir.y > 0)
			r->texnum = 2;
		else
			r->texnum = 3;
		r->wall = r->ray.pos.x + r->walldist * r->ray.dir.x;
	}
	r->wall -= floor(r->wall);
	r->texw = data->surface[r->texnum]->w;
	r->texh = data->surface[r->texnum]->h;
	r->tex.x = r->wall * r->texh;
	r->lineheight = abs((int)(SCREEN_HEIGHT / r->walldist));
}

void			hit_wall(t_raycast *r, t_data *data)
{
	while (r->hit == 0)
	{
		if (r->sidedist.x < r->sidedist.y)
		{
			r->sidedist.x += r->deltadist.x;
			r->m_pos.x += r->step.x;
			r->side = 0;
		}
		else
		{
			r->sidedist.y += r->deltadist.y;
			r->m_pos.y += r->step.y;
			r->side = 1;
		}
		if (data->map[r->m_pos.x][r->m_pos.y] > 0)
		{
			r->hit = 1;
		}
	}
}

void			give_draw_values(t_raycast *r, t_data *data)
{
	if (r->lineheight < 0)
		r->lineheight = SCREEN_HEIGHT;
	r->drawstart = -r->lineheight / 2 + (SCREEN_HEIGHT + data->yaw) / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->lineheight / 2 + (SCREEN_HEIGHT + data->yaw) / 2;
	if (r->drawend >= SCREEN_HEIGHT)
		r->drawend = SCREEN_HEIGHT - 1;
	if (r->drawend < 0)
		r->drawend = SCREEN_HEIGHT - 1;
}

void			raycasting(t_data *data)
{
	t_raycast	r;
	t_player	player;
	t_point		pt;

	pt.x = -1;
	player = data->p;
	while (++pt.x < SCREEN_WIDTH)
	{
		set_raycast_values(&r, player, pt.x);
		set_dist_and_step(&r);
		hit_wall(&r, data);
		get_texturing_values(&r, data);
		give_draw_values(&r, data);
		pt.y = r.drawstart;
		while (pt.y <= r.drawend)
		{
			r.tex.y = (pt.y * 2 - (SCREEN_HEIGHT + data->yaw) + r.lineheight)
				* (r.texh / 2) / (r.lineheight + 1);
			r.color = get_pixel(data->surface[r.texnum],
				r.tex.x, r.tex.y);
			data->pixels[pt.x + pt.y * SCREEN_WIDTH] = r.color;
			pt.y++;
		}
		floorcaster(data, &r, pt.x);
	}
}
