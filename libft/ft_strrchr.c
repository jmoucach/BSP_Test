/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:15:54 by jmoucach          #+#    #+#             */
/*   Updated: 2018/11/09 13:59:57 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while (len != 0 && *(s + len) != (char)c)
		len--;
	if (*(s + len) == (char)c)
		return ((char*)(s + len));
	return (NULL);
}
