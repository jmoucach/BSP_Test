/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:23:16 by jmoucach          #+#    #+#             */
/*   Updated: 2018/11/15 11:18:47 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_num_len(int n)
{
	if (n == -217483648)
		return (2 + (-n) / 10);
	if (n < 0)
		return (1 + ft_num_len(-n));
	if (n / 10)
		return (1 + ft_num_len(n / 10));
	return (1);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	i = 0;
	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	if (!(str = (char*)malloc(sizeof(char) * (ft_num_len(n) + 1))))
		return (NULL);
	sign = (n < 0 ? 1 : 0);
	if (n < 0)
		n = -n;
	while (n / 10)
	{
		str[i++] = (n % 10 + 48);
		n = n / 10;
	}
	str[i++] = (n % 10 + 48);
	str[i] = (sign ? '-' : '\0');
	i = (str[i] == '-' ? i + 1 : i);
	str[i] = '\0';
	return (ft_strrev(str));
}
