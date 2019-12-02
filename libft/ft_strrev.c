/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 01:48:23 by jmoucach          #+#    #+#             */
/*   Updated: 2018/11/15 11:19:05 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrev(char *str)
{
	char	temp;
	int		n;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	n = i - 1;
	i = 0;
	while (i < n)
	{
		temp = str[i];
		str[i] = str[n];
		str[n] = temp;
		n--;
		i++;
	}
	return (str);
}
