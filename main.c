/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 04:14:55 by nolakim           #+#    #+#             */
/*   Updated: 2019/08/10 16:55:53 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*initmap(void)
{
	t_map	*m;

	if (!(m = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	m->x = 0;
	m->y = 0;
	m->z = 0;
	m->color = 0;
	m->px = 0.0;
	m->py = 0.0;
	m->next = NULL;
	return (m);
}

t_fdf	*initmax(t_fdf *fdf)
{
	t_fdf	*f;

	f = fdf;
	fdf->max_x = 0;
	fdf->max_y = 0;
	fdf->dax = 0;
	fdf->day = 0;
	return (f);
}

t_rmat	*initmat(void)
{
	t_rmat	*mat;

	mat = (t_rmat *)malloc(sizeof(t_rmat));
	mat->x[0] = 0.0;
	mat->x[1] = 0.0;
	mat->x[2] = 0.0;
	mat->y[0] = 0.0;
	mat->y[1] = 0.0;
	mat->y[2] = 0.0;
	mat->z[0] = 0.0;
	mat->z[1] = 0.0;
	mat->dx = 0.0;
	mat->rx = 0.0;
	mat->dy = 0.0;
	mat->ry = 0.0;
	mat->dz = 0.0;
	mat->rz = 0.0;
	return (mat);
}

void	ft_wireframe(t_fdf *fdf, char *av)
{
	fdf->init = mlx_init();
	fdf->win = mlx_new_window(fdf->init, WIN_W, WIN_H, &av[1]);
	drawshit(fdf);
	mlx_hook(fdf->win, 2, 0, key_hook, fdf);
	mlx_loop(fdf->init);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		filestuff(fdf, av[1], 0, 0);
		fdf->mat = initmat();
		ft_2disbetter(fdf);
		ft_wireframe(fdf, av[1]);
	}
}
