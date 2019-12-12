/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:23:27 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/12 15:17:40 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

void *ft_realloc(void *ptr, size_t size)
{
	char *new_ptr;

	if (!(new_ptr = malloc(size)))
		return (NULL);
	ft_bzero(new_ptr, size);
	ft_memmove(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}