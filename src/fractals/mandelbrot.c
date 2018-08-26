/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 19:46:49 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/26 19:30:48 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Need to add some colors
*/

void			init_mndlbrt(t_fractol *f)
{
	f->size = 2.8;
	f->center_x = -0.65;
	f->center_y = 0.0;
	f->maxiter = 40;
	f->frac = 1;
}

static double		calcul_iter_mndlbrt(t_fractol *f, int x, int y)
{
	t_calcul	mb;
	int			n;
	double		zn;
	double		nu;
	double		i;

	n = 0;
	mb.a_0 = (x * f->size / WIN_SIZE) + f->center_x - (f->size / 2);
	mb.b_0 = (y * f->size / WIN_SIZE) + f->center_y - (f->size / 2);
	mb.a = mb.a_0;
	mb.b = mb.b_0;
	while ((n < f->maxiter) && (mb.a * mb.a + mb.b * mb.b < 4))
	{
		mb.temp = mb.a * mb.a - mb.b * mb.b + mb.a_0;
		mb.b = 2 * mb.a * mb.b + mb.b_0;
		mb.a = mb.temp;
		n++;
	}
	if (n == f->maxiter)
		return (255);
	zn = log(mb.a * mb.a + mb.b * mb.b) / 2;
	nu = log(zn / log(2)) / log(2);
	i = n + 1 - nu;
	i < 0 ? i = 0 : (0);
	return (i);
}

void			draw_mandelbrot(t_fractol *f)
{
	int			x;
	int			y;
	double		n;
	int			color;

	y = 0;
	while (y < WIN_SIZE)
	{
		x = 0;
		while (x < WIN_SIZE)
		{
			n = calcul_iter_mndlbrt(f, x, y);
			color = 0x000000;
			if (n != 255)
				color = get_color(f, n);
			pixel2image(f, x, y, color);
			x++;
		}
		y++;
	}
}
