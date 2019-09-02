/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sketch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 06:31:27 by nolakim           #+#    #+#             */
/*   Updated: 2019/08/10 16:53:55 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	sketchdir(t_map *prev, t_map *cur, t_fdf *fdf)
{
	fdf->dax = fabs(cur->px - prev->px);
	fdf->day = fabs(cur->py - prev->py);
	g_dir = fdf->dax >= fdf->day ? 1 : 0;
	PXY(g_dir, prev->px, prev->py) <= CXY(g_dir, cur->px, cur->py) ?
	sketch(prev, cur, fdf) :
	sketch(cur, prev, fdf);
}

void	sketch(t_map *prev, t_map *cur, t_fdf *fdf)
{
	double	e;
	double	x;
	double	y;
	double	slope;

	x = prev->px;
	y = prev->py;
	e = 2 * A_SWAP(g_dir, MDX, MDY) - ASWAP(g_dir, MDX, MDY);
	slope = YX(g_dir, x, y) < PSWAP(g_dir, cur->px, cur->py) ? 1 : -1;
	while (XY(g_dir, x, y) < P_SWAP(g_dir, cur->px, cur->py))
	{
		mlx_pixel_put(fdf->init, fdf->win, x, y, g_dir ? 0x00000FF : 0xFFFFFFF);
		if (e > 0)
		{
			e += 2 * (A_SWAP(g_dir, MDX, MDY) - ASWAP(g_dir, MDX, MDY));
			if (g_dir)
				y += slope;
			else if (g_dir == 0)
				x += slope;
		}
		else
			e += 2 * A_SWAP(g_dir, MDX, MDY);
		(g_dir) ? x++ : y++;
	}
}

void	drawshit(t_fdf *fdf)
{
	t_map	*prev;
	t_map	*f;

	prev = MAP;
	f = current(fdf);
	while (prev->next)
	{
		if (prev->x + 1 == prev->next->x && prev->next->y == prev->y)
			sketchdir(prev, prev->next, fdf);
		if (f->x == prev->x && f->y == prev->y + 1)
			sketchdir(prev, f, fdf);
		if (f->next)
			f = f->next;
		if (prev->next)
			prev = prev->next;
	}
}
