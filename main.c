/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:56:48 by pprivalo          #+#    #+#             */
/*   Updated: 2018/02/14 15:26:45 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			exit_x(void)
{
	ft_errors(5, "");
	return (0);
}

static void	ft_set_and_loop(t_mlx *mlx)
{
	mlx->ang = (t_vector){30, -30, -25, 0};
	mlx->g_mode = 0;
	mlx->g_c_mode = 0;
	mlx->g_plane = 0;
	mlx_hook(mlx->win, 17, 1L << 17, exit_x, mlx);
	mlx_hook(mlx->win, 2, 5, keyboard_hook, mlx);
	ft_draw(*mlx);
	mlx_loop(mlx->mlx);
}

int			main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac == 2)
	{
		if (ft_map_reader(av[1], &mlx.map))
		{
			mlx.mlx = mlx_init();
			mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT,
														"FDF");
			mlx.g_start_scale = (WIN_WIDTH + WIN_HEIGHT) /
							(mlx.map.width + mlx.map.height) / 2;
			mlx.scale = (t_vector){mlx.g_start_scale, mlx.g_start_scale,
						mlx.g_start_scale / 10, 0};
			mlx.offset = (t_vector){0, 0, 0, 0};
			mlx.color[0] = (t_vector){255, 165, 0, 0};
			mlx.color[1] = (t_vector){255, 0, 0, 0};
			ft_set_and_loop(&mlx);
			return (1);
		}
	}
	else
		ft_errors(4, "");
	return (0);
}
