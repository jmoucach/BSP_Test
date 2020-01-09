/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:23:27 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/06 11:36:59 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void *ft_realloc(void *ptr, size_t size)
{
	char *new_ptr;

	if (!(new_ptr = malloc(size)))
		return (NULL);
	ft_bzero(new_ptr, size);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

void print_wall(t_wall wall)
{
	ft_putendl("~~~");
	printf("|start: X:%f, Y:%f| |end: X:%f, Y:%f| |normal: X:%f, Y:%f|\n", wall.start.x, wall.start.y, wall.end.x,wall.end.y, wall.normal.x, wall.normal.y);
	ft_putendl("~~~");
}