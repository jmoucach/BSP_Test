/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 02:36:28 by jmoucach          #+#    #+#             */
/*   Updated: 2018/11/14 19:10:24 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int			wc(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int			lc(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char			*ft_strcpycharstop(char *dest, char *src, char c)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char				**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(*tab) * (wc(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c)
		{
			if (!(tab[j] = (char*)malloc(sizeof(*tab) * ((lc(s + i, c) + 1)))))
				return (NULL);
			ft_strcpycharstop(tab[j], (char *)(s + i), c);
			i = i + lc(s + i, c);
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}
