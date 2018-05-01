/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 22:17:11 by pprivalo          #+#    #+#             */
/*   Updated: 2018/02/14 14:18:21 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_trans(t_mlx *mlx, int len, t_vector c1, t_vector c2)
{
	int		i;

	i = -1;
	while (++i < len)
	{
		mlx->map.points[i] = mlx->map.basic[i];
		mlx->map.colors[i] = (mlx->map.points[i][2] > mlx->g_plane) ? c2 : c1;
	}
	ft_scale(mlx, 0);
	ft_scale(mlx, 1);
	ft_scale(mlx, 2);
	ft_rotate_z(mlx, mlx->ang[2]);
	ft_rotate_x(mlx, mlx->ang[0]);
	ft_rotate_y(mlx, mlx->ang[1]);
	ft_move(mlx, mlx->offset[0], 0);
	ft_move(mlx, mlx->offset[1], 1);
	ft_move(mlx, LINE / 2 + WIN_WIDTH / 2 -
				mlx->map.width * mlx->scale[0] / 2, 0);
	ft_move(mlx, WIN_HEIGHT / 2 -
				mlx->map.height * mlx->scale[1] / 2, 1);
}

static void	ft_draw_dir(t_vector v0, int delta[3], t_vector c[2], t_mlx ml)
{
	int		i;
	int		point;

	i = -1;
	if (!ml.line_dir)
		while ((++i <= delta[0]) && (v0[0] += ml.params[2]))
		{
			point = round(ml.params[0] * v0[0] + ml.params[1]);
			mlx_pixel_put(ml.mlx, ml.win, v0[0], point,
							get_grad(c[0], c[1], delta[0], i));
		}
	else
		while ((++i <= delta[1]) && (v0[1] += ml.params[2]))
		{
			point = round(ml.params[0] * v0[1] + ml.params[1]);
			mlx_pixel_put(ml.mlx, ml.win, point, v0[1],
							get_grad(c[0], c[1], delta[1], i));
		}
}

static void	ft_draw_line(t_vector v0, t_vector v1, t_mlx ml, t_vector c[2])
{
	int		delta[3];

	if (((v0[0] > WIN_WIDTH || v0[0] < 0) && (v1[0] > WIN_WIDTH || v1[0] < 0))
		|| ((v0[1] > WIN_HEIGHT || v0[1] < 0)
		&& (v1[1] > WIN_HEIGHT || v1[1] < 0)))
		return ;
	delta[0] = fabs(v0[0] - v1[0]);
	delta[1] = fabs(v0[1] - v1[1]);
	if (delta[0] >= delta[1])
	{
		ml.params[0] = (v1[1] - v0[1]) / (v1[0] - v0[0]);
		ml.params[1] = v0[1] - ml.params[0] * v0[0];
		ml.params[2] = (v1[0] >= v0[0]) ? 1 : -1;
		v0[0] -= ml.params[2];
		ml.line_dir = 0;
	}
	else
	{
		ml.params[2] = (v1[1] >= v0[1]) ? 1 : -1;
		ml.params[0] = (v1[0] - v0[0]) / (v1[1] - v0[1]);
		ml.params[1] = v0[0] - ml.params[0] * v0[1];
		v0[1] -= ml.params[2];
		ml.line_dir = 1;
	}
	ft_draw_dir(v0, delta, c, ml);
}

static void	ft_check_and_draw(t_mlx mlx, int i)
{
	t_vector	c[2];

	c[0] = mlx.map.colors[i];
	if (i % mlx.map.width != mlx.map.width - 1)
	{
		c[1] = mlx.map.colors[i + 1];
		ft_draw_line(mlx.map.points[i], mlx.map.points[i + 1], mlx, c);
	}
	if (i / (mlx.map.width) < mlx.map.height - 1)
	{
		c[1] = mlx.map.colors[i + mlx.map.width];
		ft_draw_line(mlx.map.points[i],
					mlx.map.points[i + mlx.map.width], mlx, c);
	}
}

void		ft_draw(t_mlx mlx)
{
	int			i;
	int			len;

	i = -1;
	len = mlx.map.width * mlx.map.height;
	mlx_clear_window(mlx.mlx, mlx.win);
	ft_write_legend1(mlx);
	if (len == 1)
		ft_print_dot(mlx);
	else
	{
		ft_trans(&mlx, len, mlx.color[0], mlx.color[1]);
		while (++i < len)
			ft_check_and_draw(mlx, i);
	}
}
