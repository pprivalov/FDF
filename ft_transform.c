/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 05:22:03 by pprivalo          #+#    #+#             */
/*   Updated: 2018/02/13 21:26:35 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scale(t_mlx *mlx, int axs)
{
	int			i;
	int			len;
	t_vector	*mtrx;

	i = -1;
	len = mlx->map.width * mlx->map.height;
	mtrx = ft_make_m(
			(t_vector){1, 0, 0, 0},
			(t_vector){0, 1, 0, 0},
			(t_vector){0, 0, 1, 0},
			(t_vector){0, 0, 0, 1});
	mtrx[axs][axs] = mlx->scale[axs];
	while (++i < len)
		mlx->map.points[i] = ft_mult_mtrx(mtrx, mlx->map.points[i]);
	free(mtrx);
}

void	ft_move(t_mlx *mlx, double offset, int axs)
{
	int			i;
	int			len;

	i = -1;
	len = mlx->map.width * mlx->map.height;
	while (++i < len)
		mlx->map.points[i][axs] += offset;
}

void	ft_rotate_x(t_mlx *mlx, double ang)
{
	int			i;
	int			len;
	int			x;
	int			y;
	t_vector	*mtrx;

	i = -1;
	len = mlx->map.width * mlx->map.height;
	ang = ang * acos(-1) / 180;
	x = mlx->map.basic[0][0] + (mlx->map.width * mlx->scale[0]) / 2;
	y = mlx->map.basic[0][1] + (mlx->map.height * mlx->scale[1]) / 2;
	mtrx = ft_make_m(
			(t_vector){1, 0, 0, 0},
			(t_vector){0, cos(ang), -sin(ang), 0},
			(t_vector){0, sin(ang), cos(ang), 0},
			(t_vector){0, 0, 0, 1});
	ft_move(mlx, -x, 0);
	ft_move(mlx, -y, 1);
	while (++i < len)
		mlx->map.points[i] = ft_mult_mtrx(mtrx, mlx->map.points[i]);
	ft_move(mlx, x, 0);
	ft_move(mlx, y, 1);
	free(mtrx);
}

void	ft_rotate_y(t_mlx *mlx, double ang)
{
	int			i;
	int			len;
	int			x;
	int			y;
	t_vector	*mtrx;

	i = -1;
	len = mlx->map.width * mlx->map.height;
	ang = ang * acos(-1) / 180;
	x = mlx->map.basic[0][0] + (mlx->map.width * mlx->scale[0]) / 2;
	y = mlx->map.basic[0][1] + (mlx->map.height * mlx->scale[1]) / 2;
	mtrx = ft_make_m(
			(t_vector){cos(ang), 0, sin(ang), 0},
			(t_vector){0, 1, 0, 0},
			(t_vector){-sin(ang), 0, cos(ang), 0},
			(t_vector){0, 0, 0, 1});
	ft_move(mlx, -x, 0);
	ft_move(mlx, -y, 1);
	while (++i < len)
		mlx->map.points[i] = ft_mult_mtrx(mtrx, mlx->map.points[i]);
	ft_move(mlx, x, 0);
	ft_move(mlx, y, 1);
	free(mtrx);
}

void	ft_rotate_z(t_mlx *mlx, double ang)
{
	int			i;
	int			len;
	int			x;
	int			y;
	t_vector	*mtrx;

	i = -1;
	len = mlx->map.width * mlx->map.height;
	ang = ang * acos(-1) / 180;
	x = mlx->map.basic[0][0] + (mlx->map.width * mlx->scale[0]) / 2;
	y = mlx->map.basic[0][1] + (mlx->map.height * mlx->scale[1]) / 2;
	mtrx = ft_make_m(
			(t_vector){cos(ang), sin(ang), 0, 0},
			(t_vector){-sin(ang), cos(ang), 0, 0},
			(t_vector){0, 0, 1, 0},
			(t_vector){0, 0, 0, 1});
	ft_move(mlx, -x, 0);
	ft_move(mlx, -y, 1);
	while (++i < len)
		mlx->map.points[i] = ft_mult_mtrx(mtrx, mlx->map.points[i]);
	ft_move(mlx, x, 0);
	ft_move(mlx, y, 1);
	free(mtrx);
}
