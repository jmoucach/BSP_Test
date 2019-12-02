/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:02:22 by jmoucach          #+#    #+#             */
/*   Updated: 2018/11/12 14:37:58 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	a;
	int	i;
	int j;

	j = 0;
	i = 0;
	a = 0;
	while (dst[i])
		i++;
	while (src[a])
		a++;
	while (src[j] != '\0' && j + i < (int)size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	a = (((int)size <= i) ? (int)size + a : a + i);
	return (a);
}
