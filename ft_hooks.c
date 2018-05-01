/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 22:07:31 by pprivalo          #+#    #+#             */
/*   Updated: 2018/02/14 15:28:13 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** key hooks for -scale
*/

static void	keyboard_minus(t_mlx *mlx)
{
	if (mlx->g_mode == 0)
	{
		if (mlx->scale[0] - 1 >= 0 && mlx->scale[1] - 1 >= 0)
		{
			mlx->scale[0] -= 1;
			mlx->scale[1] -= 1;
			mlx->scale[2] = mlx->scale[0] * (1 + mlx->scale[3]) / 10;
		}
	}
	else
	{
		if (mlx->g_mode == 3)
		{
			mlx->scale[3] -= 0.1;
			mlx->scale[2] = mlx->scale[0] * (1 + mlx->scale[3]) / 10;
		}
		else if (mlx->g_mode == 1 && mlx->scale[1] - 1 >= 0)
			mlx->scale[1] -= 1;
		else if (mlx->g_mode == 2 && mlx->scale[0] - 1 >= 0)
			mlx->scale[0] -= 1;
	}
}

/*
** key hooks for +scale
*/

static void	keyboard_plus(t_mlx *mlx)
{
	if (mlx->g_mode == 0)
	{
		mlx->scale[0] += 1;
		mlx->scale[1] += 1;
		mlx->scale[2] = mlx->scale[0] * (1 + mlx->scale[3]) / 10;
	}
	else
	{
		if (mlx->g_mode == 3)
		{
			mlx->scale[3] += 0.1;
			mlx->scale[2] = mlx->scale[0] * (1 + mlx->scale[3]) / 10;
		}
		else if (mlx->g_mode == 1)
			mlx->scale[1] += 1;
		else if (mlx->g_mode == 2)
			mlx->scale[0] += 1;
	}
}

/*
** key hooks for rotation x, y_right, return
*/

static void	keyboard_hook3(int key, t_mlx *mlx)
{
	if (key == 15)
	{
		mlx->scale = (t_vector){mlx->g_start_scale, mlx->g_start_scale,
								mlx->g_start_scale / 10, 0};
		mlx->offset = (t_vector){0, 0, 0, 0};
		mlx->color[0] = (t_vector){255, 165, 0, 0};
		mlx->color[1] = (t_vector){255, 0, 0, 0};
		mlx->ang = (t_vector){30, -30, -25, 0};
		mlx->g_mode = 0;
		mlx->g_plane = 0;
	}
	else if (key == 13)
		mlx->ang[0] += 1;
	else if (key == 1)
		mlx->ang[0] -= 1;
	else if (key == 2)
		mlx->ang[1] += 1;
	else if (key == 82)
		mlx->g_c_mode = !mlx->g_c_mode;
	else if (key == 69)
		mlx->g_plane++;
	else if (key == 78)
		mlx->g_plane--;
}

/*
** key hooks for rotation y_left, z_left, color
*/

static void	keyboard_hook2(int key, t_mlx *mlx)
{
	if (key == 51)
	{
		mlx->scale = (t_vector){mlx->g_start_scale, mlx->g_start_scale,
								mlx->g_start_scale / 10, 0};
		mlx->offset = (t_vector){0, 0, 0, 0};
		mlx->color[0] = (t_vector){255, 255, 255, 0};
		mlx->color[1] = (t_vector){255, 255, 255, 0};
		mlx->ang = (t_vector){0, 0, 0, 0};
		mlx->g_mode = 0;
		mlx->g_plane = 0;
	}
	else if (key == 0)
		mlx->ang[1] -= 1;
	else if (key == 14)
		mlx->ang[2] -= 1;
	else if (key == 86 || key == 87 || key == 88)
	{
		if (mlx->color[mlx->g_c_mode][key - 86] + 5 < 256)
			mlx->color[mlx->g_c_mode][key - 86] += 5;
	}
	else if (key == 83 || key == 84 || key == 85)
	{
		if (mlx->color[mlx->g_c_mode][key - 83] - 5 >= 0)
			mlx->color[mlx->g_c_mode][key - 83] -= 5;
	}
}

/*
** key hooks scale_mode, ESC, scale, move, rotaion z_right
*/

int			keyboard_hook(int key, t_mlx *mlx)
{
	if (key == 6 || key == 7 || key == 8)
		mlx->g_mode = (mlx->g_mode == 9 - key) ? 0 : 9 - key;
	if (key == 53)
		ft_errors(5, "");
	else if (key == 24)
		keyboard_plus(mlx);
	else if (key == 27)
		keyboard_minus(mlx);
	else if (key == 126 && mlx->map.points[0][1] - 10 > 0)
		mlx->offset[1] -= 10;
	else if (key == 125 && mlx->map.points[(mlx->map.width) *
						(mlx->map.height - 1)][1] + 10 < WIN_HEIGHT - 1)
		mlx->offset[1] += 10;
	else if (key == 124 && mlx->map.points[mlx->map.width - 1][0] +
							10 < WIN_WIDTH)
		mlx->offset[0] += 10;
	else if (key == 123 && mlx->map.points[0][0] - 10 > 250)
		mlx->offset[0] -= 10;
	else if (key == 12)
		mlx->ang[2] += 1;
	keyboard_hook2(key, mlx);
	keyboard_hook3(key, mlx);
	ft_draw(*mlx);
	return (0);
}
