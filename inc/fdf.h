/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:43:20 by pprivalo          #+#    #+#             */
/*   Updated: 2018/02/14 15:26:01 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H
# include <mlx.h>
# include "libft.h"
# include <fcntl.h>
# include "vector.h"
# include <math.h>
# define WIN_WIDTH 1600
# define WIN_HEIGHT 1000
# define LINE 300
# define MAX(a, b) a >= b ? a : b
# define MIN(a, b) a <= b ? a : b
# define ABS(a) a < 0 ? -a : a
# define RND(a) (int)(a + 0.55555)

typedef struct	s_map
{
	t_vector	*points;
	t_vector	*basic;
	t_vector	*colors;
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
}				t_map;

typedef struct	s_mlx
{
	int			g_mode;
	int			g_c_mode;
	int			g_plane;
	int			g_start_scale;
	int			line_dir;
	t_map		map;
	t_vector	params;
	t_vector	scale;
	t_vector	offset;
	t_vector	ang;
	t_vector	color[2];
	void		*mlx;
	void		*win;
}				t_mlx;

int				ft_map_reader(char *filename, t_map *map);
void			ft_errors(int err, char *filename);
int				exit_x(void);
int				keyboard_hook(int key, t_mlx *mlx);
void			ft_draw(t_mlx	mlx);
void			ft_rotate_x(t_mlx *mlx, double ang);
void			ft_rotate_y(t_mlx *mlx, double ang);
void			ft_rotate_z(t_mlx *mlx, double ang);
void			ft_move(t_mlx *mlx, double offset, int axs);
void			ft_scale(t_mlx *mlx, int axs);
unsigned int	color(t_vector color);
unsigned int	get_grad(t_vector c1, t_vector c2, int delta, int i);
void			ft_write_legend1(t_mlx mlx);
void			ft_print_dot(t_mlx mlx);

#endif
