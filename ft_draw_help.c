/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:18:35 by pprivalo          #+#    #+#             */
/*   Updated: 2018/02/14 14:57:43 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_write_legend2(t_mlx mlx)
{
	char	*str;

	str = ft_itoa((int)mlx.color[mlx.g_c_mode][0]);
	mlx_string_put(mlx.mlx, mlx.win, 20, 240, 0xFF311F, str);
	free(str);
	mlx_string_put(mlx.mlx, mlx.win, 20, 260, 0x00C41C, "      g:  NUM5/NUM2");
	str = ft_itoa((int)mlx.color[mlx.g_c_mode][1]);
	mlx_string_put(mlx.mlx, mlx.win, 20, 260, 0x00C41C, str);
	free(str);
	mlx_string_put(mlx.mlx, mlx.win, 20, 280, 0x2445C4, "      b:  NUM6/NUM3");
	str = ft_itoa((int)mlx.color[mlx.g_c_mode][2]);
	mlx_string_put(mlx.mlx, mlx.win, 20, 280, 0x2445C4, str);
	free(str);
	mlx_string_put(mlx.mlx, mlx.win, 20, 320, 0xFF6305, "Null plane: ");
	str = ft_itoa(mlx.g_plane);
	mlx_string_put(mlx.mlx, mlx.win, 200, 320, 0xFF6305, str);
	free(str);
	mlx_string_put(mlx.mlx, mlx.win, 20, 340, 0xFF6305, "return:   'R'");
	mlx_string_put(mlx.mlx, mlx.win, 20, 360, 0xFF6305,
													"reset:    'Backspace'");
}

void		ft_write_legend1(t_mlx mlx)
{
	int		mode_color[4];
	char	*str;

	mode_color[0] = (mlx.g_mode == 2) ? 0x42FF3B : 0xFF6305;
	mode_color[1] = (mlx.g_mode == 1) ? 0x42FF3B : 0xFF6305;
	mode_color[2] = (mlx.g_mode == 3) ? 0x42FF3B : 0xFF6305;
	mode_color[3] = (mlx.g_mode == 0) ? 0x42FF3B : 0xFF6305;
	str = (mlx.g_c_mode == 0) ? "from" : "to";
	mlx_string_put(mlx.mlx, mlx.win, 20, 20, 0xFF6305, "rotate x: 'w'/'s'");
	mlx_string_put(mlx.mlx, mlx.win, 20, 40, 0xFF6305, "       y: 'a'/'d'");
	mlx_string_put(mlx.mlx, mlx.win, 20, 60, 0xFF6305, "       z: 'q'/'e'");
	mlx_string_put(mlx.mlx, mlx.win, 20, 80, mode_color[3],
														"scale:    '-'/'+'");
	mlx_string_put(mlx.mlx, mlx.win, 20, 100, mode_color[0], "   mod x: 'x'");
	mlx_string_put(mlx.mlx, mlx.win, 20, 120, mode_color[1], "   mod y: 'c'");
	mlx_string_put(mlx.mlx, mlx.win, 20, 140, mode_color[2], "   mod z: 'z'");
	mlx_string_put(mlx.mlx, mlx.win, 20, 180, 0xFF6305, "move:     arrows");
	mlx_string_put(mlx.mlx, mlx.win, 20, 220, 0xFF6305, "color");
	mlx_string_put(mlx.mlx, mlx.win, 80, 220, 0xFFFFFF, str);
	mlx_string_put(mlx.mlx, mlx.win, 20, 240, 0xFF311F, "      r:  NUM4/NUM1");
	ft_write_legend2(mlx);
}

void		ft_print_dot(t_mlx mlx)
{
	mlx.map.points[0] = mlx.map.basic[0];
	mlx.map.colors[0] =
		(mlx.map.points[0][2] > mlx.g_plane) ? mlx.color[1] : mlx.color[0];
	ft_move(&mlx, mlx.offset[0] + LINE / 2 + WIN_WIDTH / 2, 0);
	ft_move(&mlx, mlx.offset[1] + WIN_HEIGHT / 2, 1);
	mlx_pixel_put(mlx.mlx, mlx.win, mlx.map.points[0][0],
					mlx.map.points[0][1], color(mlx.map.colors[0]));
}
