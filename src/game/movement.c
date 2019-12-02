/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:14:45 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/08 16:29:17 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/wolf3d.h"

void		rotate(t_data *data, int rotdir)
{
	double	olddir;
	double	oldplane;

	if (rotdir != 0)
	{
		oldplane = data->p.plane.x;
		olddir = data->p.dir.x;
		data->p.dir.x = data->p.dir.x
			* cos(rotdir * data->p.rspeed * data->ftime)
			- data->p.dir.y * sin(rotdir * data->p.rspeed * data->ftime);
		data->p.dir.y = olddir * sin(rotdir * data->p.rspeed * data->ftime)
			+ data->p.dir.y * cos(rotdir * data->p.rspeed * data->ftime);
		data->p.plane.x = data->p.plane.x
			* cos(rotdir * data->p.rspeed * data->ftime) - data->p.plane.y
			* sin(rotdir * data->p.rspeed * data->ftime);
		data->p.plane.y = oldplane * sin(rotdir * data->p.rspeed * data->ftime)
			+ data->p.plane.y * cos(rotdir * data->p.rspeed * data->ftime);
	}
}

void		walk(t_data *data, int walkdir)
{
	double	dx;
	double	dy;

	dx = walkdir * data->p.dir.x * data->p.walkspeed * data->ftime;
	dy = walkdir * data->p.dir.y * data->p.walkspeed * data->ftime;
	if (data->map[(int)(data->p.pos.x + dx)]
		[(int)data->p.pos.y] == 0)
		data->p.pos.x += dx;
	if (data->map[(int)(data->p.pos.x)]
		[(int)(data->p.pos.y + dy)] == 0)
		data->p.pos.y += dy;
}

void		sprint(t_data *data, int sprintdir)
{
	double	dx;
	double	dy;

	dx = sprintdir * data->p.dir.x * data->p.sprintspeed * data->ftime;
	dy = sprintdir * data->p.dir.y * data->p.sprintspeed * data->ftime;
	if (data->map[(int)(data->p.pos.x + dx)]
		[(int)data->p.pos.y] == 0)
		data->p.pos.x += dx;
	if (data->map[(int)(data->p.pos.x)]
		[(int)(data->p.pos.y + dy)] == 0)
		data->p.pos.y += dy;
}

void		strafe(t_data *data, int strafe)
{
	double	dx;
	double	dy;

	dx = strafe * data->p.dir.y * data->p.walkspeed * data->ftime / 2;
	dy = -strafe * data->p.dir.x * data->p.walkspeed * data->ftime / 2;
	if (data->map[(int)(data->p.pos.x + dx)]
		[(int)data->p.pos.y] == 0)
		data->p.pos.x += dx;
	if (data->map[(int)(data->p.pos.x)]
		[(int)(data->p.pos.y + dy)] == 0)
		data->p.pos.y += dy;
}
