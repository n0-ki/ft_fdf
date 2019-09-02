/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgstuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 08:38:07 by nolakim           #+#    #+#             */
/*   Updated: 2019/08/10 16:48:10 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_2disbetter(t_fdf *fdf)
{
	t_map	*f;

	f = MAP;
	fdf->mat->rx = fdf->mat->dx * (PI / 180);
	fdf->mat->ry = fdf->mat->dy * (PI / 180);
	fdf->mat->rz = fdf->mat->dz * (PI / 180);
	while (f)
	{
		MX[0] = (double)f->x;
		MY[0] = ((f->y) * cos(fdf->mat->rx)) + f->z * sin(fdf->mat->rx);
		MZ[0] = (f->z * cos(fdf->mat->rx)) - f->y * sin(fdf->mat->rx);
		MX[1] = (MX[0] * cos(fdf->mat->ry)) - (MZ[0] * sin(fdf->mat->ry));
		MY[1] = MY[0];
		MZ[1] = (MZ[0] * cos(fdf->mat->ry)) + (MX[0] * sin(fdf->mat->rz));
		MX[2] = (MX[1] * cos(fdf->mat->rz)) + (MX[0] * sin(fdf->mat->rz));
		MY[2] = (MY[1] * cos(fdf->mat->rz)) - (MX[1] * sin(fdf->mat->rz));
		MX[2] *= (WIN_W - 500) / fdf->max_x;
		MY[2] *= (WIN_H - 500) / fdf->max_y;
		MX[2] += 200;
		MY[2] += 200;
		f->px = MX[2] + fdf->transx;
		f->py = MY[2] + fdf->transy;
		f = f->next;
	}
}
