/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:38:17 by jmoucach          #+#    #+#             */
/*   Updated: 2019/12/02 09:42:12 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../hdr/doom.h"

double dotproduct(t_vertex v1, t_vertex v2)
{
	double result;

	result = v1.x * v2.x + v1.y * v2.y;
	return result;
}