/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:25:42 by jmoucach          #+#    #+#             */
/*   Updated: 2018/11/14 14:27:07 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
	{
		((unsigned char*)dst)[i] = ((const unsigned char*)src)[i];
		if (((const unsigned char*)src)[i] == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
