/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:39:00 by jmoucach          #+#    #+#             */
/*   Updated: 2018/11/14 17:35:21 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*str) * (ft_strlen(s1) +
						ft_strlen(s2) + 1))))
		return (NULL);
	str = ft_strcat(ft_strcpy(str, s1), s2);
	return (str);
}
