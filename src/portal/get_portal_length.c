/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_portal_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:10:10 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/27 17:11:43 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom.h"

int get_portal_length(t_portal *portal)
{
	if (!portal)
		return (0);
	return (vertex_distance(portal->start, portal->end));
}
