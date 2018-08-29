/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:26:43 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/29 11:45:50 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_ship(t_fractol *f)
{
	f->size = 4.0;
	f->center_x = -0.5;
	f->center_y = -0.25;
	f->maxiter = 35;
	f->frac = 3;
}

static double	calcul_iter_ship(t_fractol *f, int x, int y)
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
		mb.b = fabs(2 * mb.a * mb.b) + mb.b_0;
		mb.a = mb.temp;
		n++;
	}
	if (n == f->maxiter)
		return (255);
	zn = log(mb.a * mb.a + mb.b * mb.b) / 2.0f;
	nu = log(zn / log(2)) / log(2);
	i = n + 1 - nu;
	i < 0 ? i = 0 : (0);
	return (i);
}

void			draw_ship(t_fractol *f)
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
			n = calcul_iter_ship(f, x, y);
			color = 0x000000;
			if (n != 255)
				color = get_color(f, n);
			pixel2image(f, x, y, color);
			x++;
		}
		y++;
	}
}
