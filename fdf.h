/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 06:50:56 by nolakim           #+#    #+#             */
/*   Updated: 2019/08/11 19:31:14 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>

# include "minilibx/mlx.h"
# include "libft/libft.h"
# define WIN_H ((int)1080)
# define WIN_W ((int)1080)
# define PI 3.14159265359
# define WHITE ((int)16777215)
# define MX fdf->mat->x
# define MY fdf->mat->y
# define MZ fdf->mat->z
# define MDX fdf->dax
# define MDY fdf->day
# define MAP fdf->map
# define PSWAP(g_dir, px, py) ((g_dir) ? (py) : (px))
# define P_SWAP(g_dir, px, py) ((g_dir) ? (px) : (py))
# define ASWAP(g_dir, dx, dy) ((g_dir) ? (dx) : (dy))
# define A_SWAP(g_dir, dx, dy) ((g_dir) ? (dy) : (dx))
# define XY(g_dir, x, y) ((g_dir) ? (x) : (y))
# define YX(g_dir, x, y) ((g_dir) ? (y) : (x))
# define PXY(g_dir, prex, prey) ((g_dir) ? (prex) : (prey))
# define CXY(g_dir, curx, cury) ((g_dir) ? (curx) : (cury))

int					g_dir;

typedef struct		s_rmat
{
	double			x[3];
	double			y[3];
	double			z[2];
	double			dx;
	double			rx;
	double			dy;
	double			ry;
	double			dz;
	double			rz;
}					t_rmat;

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	int				color;
	double			px;
	double			py;
	struct s_map	*next;
}					t_map;

typedef struct		s_fdf
{
	t_map			*map;
	t_rmat			*mat;
	void			*init;
	void			*win;
	int				max_x;
	int				max_y;
	int				dax;
	int				day;
	double			transx;
	double			transy;
}					t_fdf;

void				makeimg(t_fdf *fdf);
void				drawshit(t_fdf *fdf);
void				ft_2disbetter(t_fdf *fdf);
void				ft_repeat(t_fdf *fdf);
int					key_hook(int key, t_fdf *fdf);
t_rmat				*initmat(void);
void				filestuff(t_fdf *fdf, char *av, int y, int x);
t_fdf				*initmax(t_fdf *fdf);
t_map				*initmap(void);
t_map				*current(t_fdf *fdf);
void				sketch(t_map *prev, t_map *cur, t_fdf *fdf);
void				ft_exit(t_fdf *fdf);

#endif
