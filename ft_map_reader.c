/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:43:06 by pprivalo          #+#    #+#             */
/*   Updated: 2018/02/14 15:27:57 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_width(char *line)
{
	int		i;
	char	**buf;
	int		width;

	i = -1;
	width = 0;
	buf = ft_strsplit(line, ' ');
	while (buf[++i])
	{
		width++;
		free(buf[i]);
	}
	free(buf);
	return (width);
}

static void	ft_take_size(char *filename, int *width, int *height)
{
	char	*line;
	int		fd;
	int		gnl;

	*height = 0;
	*width = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_errors(6, filename);
	while ((gnl = get_next_line(fd, &line)))
	{
		if (gnl < 0)
			ft_errors(1, filename);
		if (*width == -1)
			*width = ft_get_width(line);
		else if (*width != ft_get_width(line))
			ft_errors(2, filename);
		(*height)++;
		free(line);
	}
	close(fd);
}

static void	ft_set_params(t_map *map, int x, int y, char **split)
{
	(map->basic)[y * map->width + x] = (t_vector){x, y, ft_atoi(split[x]), 1};
	free(split[x]);
	(map->colors)[y * map->width + x] = (t_vector){255, 255, 255, 0};
	map->depth_min = MIN(map->depth_min, (map->basic)[y * map->width + x][2]);
	map->depth_max = MAX(map->depth_max, (map->basic)[y * map->width + x][2]);
}

static void	ft_read_map(char *f, t_map *map)
{
	char	**split;
	char	*line;
	int		fd;
	int		x;
	int		y;

	y = 0;
	fd = open(f, O_RDONLY);
	map->depth_min = 0;
	map->depth_max = 0;
	if (fd == -1)
		ft_errors(1, f);
	while (get_next_line(fd, &line))
	{
		x = -1;
		split = ft_strsplit(line, ' ');
		while (++x < map->width)
			ft_set_params(map, x, y, split);
		free(split);
		free(line);
		y++;
	}
	close(fd);
}

int			ft_map_reader(char *filename, t_map *map)
{
	ft_take_size(filename, &map->width, &map->height);
	if (!(map->points = (t_vector *)malloc(sizeof(t_vector) *
								(map->width * map->height))) ||
		!(map->basic = (t_vector *)malloc(sizeof(t_vector) *
								(map->width * map->height))) ||
		!(map->colors = (t_vector *)malloc(sizeof(t_vector) *
								(map->width * map->height))))
		ft_errors(3, "");
	ft_read_map(filename, map);
	return (1);
}
