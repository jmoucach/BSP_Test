/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:50:13 by jmoucach          #+#    #+#             */
/*   Updated: 2018/11/14 17:24:00 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		j--;
	if (j < 1)
		return (ft_strnew(1));
	if (!(str = (char *)malloc(sizeof(*s) * (j + 2))))
		return (NULL);
	s = s + i;
	i = -1;
	while (++i <= j)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
