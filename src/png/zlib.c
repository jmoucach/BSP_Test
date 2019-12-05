/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zlib.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:09:26 by sjulliot          #+#    #+#             */
/*   Updated: 2019/09/27 17:11:13 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../hdr/png.h"

int					process_zlib_headers(char **data, size_t *len)
{
	char			cmf;
	char			flg;
	char			cm;
	char			fdict;

	if (*len < 2)
		return (PB);
	cmf = (*data)[0];
	flg = (*data)[1];
	cm = cmf & 0xF;
	fdict = flg & 0x04;
	*len -= 2;
	*data += 2;
	if (cm != 8)
		return (print_error("Invalid cm. The PNG format only accepts 8.\n"));
	if (((int)cmf * 256 + (int)flg) % 31 != 0)
		return (print_error("Invalid flg\n"));
	if (fdict)
		return (print_error("fdict should not be set in PNG spec.\n"));
	return (OK);
}
