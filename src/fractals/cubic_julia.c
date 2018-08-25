/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:23:43 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/25 19:29:37 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_jcube(t_fractol *f)
{
	f->size = 4.0;
	f->center_x = 0.0;
	f->center_y = 0.0;
	f->maxiter = 35;
	f->frac = 6;
	f->recalc = 1;
	f->mouse_x = 520;
	f->mouse_y = 678;
	f->st_size = f->size;
	f->st_x = f->center_x;
	f->st_y = f->center_y;
}

static int		calcul_iter_jcube(t_fractol *f, int x, int y)
{
	t_calcul	mb;
	int			n;

	n = 0;
	mb.a = (x * f->size / WIN_SIZE) + f->center_x - (f->size / 2);
	mb.b = (y * f->size / WIN_SIZE) + f->center_y - (f->size / 2);
	mb.a_0 = (f->mouse_x * f->st_size / WIN_SIZE) + f->st_x - (f->st_size / 2);
	mb.b_0 = (f->mouse_y * f->st_size / WIN_SIZE) + f->st_y - (f->st_size / 2);
	while ((n < f->maxiter) && (mb.a * mb.a + mb.b * mb.b < 4))
	{
		mb.temp = mb.a * mb.a * mb.a -  3 * mb.a * mb.b * mb.b + mb.a_0;
		mb.b = 3 * mb.a * mb.a * mb.b - mb.b * mb.b * mb.b + mb.b_0;
		mb.a = mb.temp;
		n++;
	}
	return (n);
}

void			draw_jcube(t_fractol *f)
{
	int		x;
	int		y;
	int		n;
	int		color;

	y = 0;
	while (y < WIN_SIZE)
	{
		x = 0;
		while (x < WIN_SIZE)
		{
			n = calcul_iter_jcube(f, x, y);
			color = 0x000000;
			if (n < f->maxiter)
				color = palette(f, n % 12);
			pixel2image(f, x, y, color);
			x++;
		}
		y++;
	}
}
