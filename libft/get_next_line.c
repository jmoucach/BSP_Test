/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:36:08 by jmoucach          #+#    #+#             */
/*   Updated: 2019/02/24 19:59:49 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static t_list	*ft_link_select(size_t fd, t_list **lst)
{
	t_list			*new;

	new = *lst;
	while (new)
	{
		if (new->content_size == fd)
			return (new);
		new = new->next;
	}
	if (!(new = ft_lstnew("\0", 1)))
		return (NULL);
	new->content_size = fd;
	ft_lstadd(lst, new);
	return (new);
}

static int		ft_red(void **str, int fd)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	if (read(fd, buf, 0) < 0)
		return (0);
	while (!ft_strchr(*str, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (0);
		buf[ret] = '\0';
		tmp = *str;
		if (!(*str = ft_strjoin(*str, buf)))
			return (0);
		free(tmp);
	}
	return (1);
}

static int		ft_line_treat(void **str, char **line)
{
	char			*tmp;
	int				i;
	int				j;

	if (!str || !(*str))
		return (-1);
	i = ft_strlen(*str);
	tmp = *str;
	if (ft_strchr(*str, '\n'))
	{
		j = ft_strlen(ft_strchr(*str, '\n'));
		if (!(*line = ft_strsub(*str, 0, i - j)))
			return (-1);
		if (!(*str = ft_strsub(*str, i - j + 1, i)))
			return (-1);
	}
	else
	{
		*line = ft_strdup(*str);
		*str = NULL;
	}
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*current;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	current = ft_link_select(fd, &lst);
	if (!ft_red(&(current->content), fd))
		return (-1);
	if (!current->content || !ft_strlen(current->content))
		return (0);
	return (ft_line_treat(&(current->content), &(*line)));
}
