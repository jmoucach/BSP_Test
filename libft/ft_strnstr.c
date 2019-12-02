/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:42:49 by jmoucach          #+#    #+#             */
/*   Updated: 2018/11/12 21:17:15 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < (int)len)
	{
		while (haystack[i + j] == needle[j] && (i + j) < ((int)len) &&
				haystack[i + j] && needle[j])
			j++;
		if (needle[j] == '\0' && haystack[i + j] == '\0')
			return ((char *)needle);
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
		j = 0;
	}
	return (0);
}
