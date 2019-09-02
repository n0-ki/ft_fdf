/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:02:16 by nolakim           #+#    #+#             */
/*   Updated: 2019/08/11 19:11:12 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*current(t_fdf *fdf)
{
	t_map *new;

	new = MAP;
	while (new)
	{
		if (new->x == MAP->x && new->y == MAP->y + 1)
			return (new);
		else
			new = new->next;
	}
	return (NULL);
}

void	ft_repeat(t_fdf *fdf)
{
	ft_2disbetter(fdf);
	mlx_clear_window(fdf->init, fdf->win);
	drawshit(fdf);
}

int		key_hook(int key, t_fdf *fdf)
{
	if (key == 53)
		ft_exit(fdf);
	else if (key == 126)
		fdf->transy -= 2;
	else if (key == 124)
		fdf->transx += 2;
	else if (key == 125)
		fdf->transy += 2;
	else if (key == 123)
		fdf->transx -= 2;
	else if (key == 13)
		fdf->mat->dx += 2;
	else if (key == 1)
		fdf->mat->dx -= 2;
	else if (key == 2)
		fdf->mat->dy += 2;
	else if (key == 0)
		fdf->mat->dy -= 2;
	ft_repeat(fdf);
	return (0);
}

void	ft_exit(t_fdf *fdf)
{
	while (MAP)
	{
		free(MAP);
		MAP = MAP->next;
	}
	free(fdf->mat);
	free(fdf);
	ft_putstr("Program has been closed\n");
	exit(1);
}
