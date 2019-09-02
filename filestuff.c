/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filestuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 04:14:50 by nolakim           #+#    #+#             */
/*   Updated: 2019/08/27 02:07:08 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*mapval(t_fdf *fdf, int **points, int y, int x)
{
	t_map	*f;

	MAP = initmap();
	f = MAP;
	while (y < fdf->max_y)
	{
		x = 0;
		while (x < fdf->max_x)
		{
			MAP->z = points[y][x];
			MAP->x = x;
			MAP->y = y;
			x++;
			MAP->next = initmap();
			MAP = MAP->next;
		}
		free(points[y]);
		y++;
	}
	free(points);
	return (f);
}

void	hwcount(t_fdf *fdf, int fd, char *av)
{
	int		i;
	char	*line;
	char	**split;

	fdf = initmax(fdf);
	if ((fd = open(av, O_RDONLY)) == -1)
		perror("feed me a real file wtf");
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		split = ft_strsplit(line, ' ');
		while (split[i])
		{
			if (i > fdf->max_x)
				fdf->max_x = i;
			free(split[i]);
			i++;
		}
		free(line);
		free(split);
		fdf->max_y++;
	}
	close(fd);
}

int		**pointspace(t_fdf *fdf, int y)
{
	int		**points;

	points = (int **)malloc(sizeof(int *) * fdf->max_y);
	while (y != fdf->max_y)
	{
		points[y] = (int *)malloc(sizeof(int) * fdf->max_x);
		y++;
	}
	return (points);
}

void	filestuff(t_fdf *fdf, char *av, int y, int x)
{
	int		fd;
	int		**points;
	char	*line;
	char	**split;

	hwcount(fdf, 0, av);
	points = pointspace(fdf, 0);
	if ((fd = open(av, O_RDONLY)) == -1)
		perror("feed me a real file");
	while (get_next_line(fd, &line) == 1)
	{
		x = 0;
		split = ft_strsplit(line, ' ');
		while (split[x])
		{
			if (ft_isdigit(split[x][0]) || split[x][0] == '-')
				points[y][x] = ft_atoi(split[x]);
			free(split[x]);
			x++;
		}
		y++;
		free(split);
		free(line);
	}
	MAP = mapval(fdf, points, 0, 0);
}
