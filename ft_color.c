/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:08:52 by pprivalo          #+#    #+#             */
/*   Updated: 2018/02/14 11:57:00 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	color(t_vector color)
{
	return (((int)color[0] << 16) | ((int)color[1] << 8) | (int)color[2]);
}

unsigned int	get_grad(t_vector c1, t_vector c2, int delta, int i)
{
	return (color((t_vector){c1[0] + (c2[0] - c1[0]) / delta * i,
							c1[1] + (c2[1] - c1[1]) / delta * i,
							c1[2] + (c2[2] - c1[2]) / delta * i}));
}
