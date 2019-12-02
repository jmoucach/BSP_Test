/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:17:52 by jmoucach          #+#    #+#             */
/*   Updated: 2018/11/14 19:26:36 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (i < ft_strlen(haystack))
	{
		if (ft_strncmp((char *)&haystack[i], needle, ft_strlen(needle)) == 0)
			return ((result = (char *)&haystack[i]));
		i++;
	}
	return (NULL);
}
