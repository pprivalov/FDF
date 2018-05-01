/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:30:24 by pprivalo          #+#    #+#             */
/*   Updated: 2018/02/14 15:30:56 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_errors(int err, char *filename)
{
	if (err == 1)
	{
		ft_putstr("./fdf: ");
		ft_putstr(filename);
		ft_putstr(": Can't read file\n");
	}
	if (err == 2)
	{
		ft_putstr("./fdf: ");
		ft_putstr(filename);
		ft_putstr(": Invalid map\n");
	}
	if (err == 3)
		ft_putstr("Malloc error\n");
	if (err == 4)
		ft_putstr("usage: ./fdf [file]\n");
	if (err == 5)
		ft_putstr("Finish\n");
	if (err == 6)
	{
		ft_putstr("./fdf: ");
		ft_putstr(filename);
		ft_putstr(": Can't open file\n");
	}
	exit(0);
}
