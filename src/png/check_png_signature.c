/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_signature.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:30:17 by sjulliot          #+#    #+#             */
/*   Updated: 2019/09/27 16:48:42 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../libft/inc/libft.h"
#include "../../hdr/png.h"

int					check_png_signature(int fd)
{
	const char		magic_value[] = {137, 80, 78, 71, 13, 10, 26, 10};
	char			magic_section[8];
	int				ret;

	if ((ret = read(fd, magic_section, 8)) < 8)
		return (PB);
	return ((ft_strncmp(magic_section, magic_value, 8)) ? PB : OK);
}
