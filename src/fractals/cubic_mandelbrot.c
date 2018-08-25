/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:14:50 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/25 19:29:45 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_mcube(t_fractol *f)
{
	f->size = 2.8;
	f->center_x = 0.0;
	f->center_y = 0.0;
	f->maxiter = 40;
	f->frac = 5;
}

static int		calcul_iter_mcube(t_fractol *f, int x, int y)
{
	t_calcul	mb;
	int			n;

	n = 0;
	mb.a_0 = (x * f->size / WIN_SIZE) + f->center_x - (f->size / 2);
	mb.b_0 = (y * f->size / WIN_SIZE) + f->center_y - (f->size / 2);
	mb.a = mb.a_0;
	mb.b = mb.b_0;
	while ((n < f->maxiter) && (mb.a * mb.a + mb.b * mb.b < 4))
	{
		mb.temp = mb.a * mb.a * mb.a -  3 * mb.a * mb.b * mb.b + mb.a_0;
		mb.b = 3 * mb.a * mb.a * mb.b - mb.b * mb.b * mb.b + mb.b_0;
		mb.a = mb.temp;
		n++;
	}
	return (n);
}

void			draw_mcube(t_fractol *f)
{
	int			x;
	int			y;
	int			n;
	int			color;

	y = 0;
	while (y < WIN_SIZE)
	{
		x = 0;
		while (x < WIN_SIZE)
		{
			n = calcul_iter_mcube(f, x, y);
			color = 0x000000;
			if (n < f->maxiter)
				color = palette(f, n % 12);
			pixel2image(f, x, y, color);
			x++;
		}
		y++;
	}
}
