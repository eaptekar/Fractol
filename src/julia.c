/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:46:16 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/22 19:54:14 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_julia(t_fractol *f)
{
	f->size = 3.0;
	f->center_x = 0.0;
	f->center_y = 0.0;
	f->maxiter = 35;
	f->frac = 2;
	f->recalc = 1;
	f->mouse_x = 131;
	f->mouse_y = 604;
	f->st_size = f->size;
	f->st_x = f->center_x;
	f->st_y = f->center_y;
}

static int		calcul_iter_julia(t_fractol *f, int x, int y)
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
		mb.temp = mb.a * mb.a - mb.b * mb.b + mb.a_0;
		mb.b = 2 * mb.a * mb.b + mb.b_0;
		mb.a = mb.temp;
		n++;
	}
	return (n);
}

void			draw_julia(t_fractol *f)
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
			n = calcul_iter_julia(f, x, y);
			color = 0x000000;
			if (n < f->maxiter)
				color = palette(n % 24);
			pixel2image(f, x, y, color);
			x++;
		}
		y++;
	}
}

void			julia(void)
{
	t_fractol	f;

	ft_bzero(&f, sizeof(t_fractol));
	f.mlx_ptr = mlx_init();
	f.win_ptr = mlx_new_window(f.mlx_ptr, WIN_SIZE, WIN_SIZE, "Julia");
	init_julia(&f);
	draw_image(&f);
	mlx_hook(f.win_ptr, 17, (1L << 17), exit_redcross, &f);
	mlx_hook(f.win_ptr, 2, (1L << 0), key_hook, &f);
	mlx_mouse_hook(f.win_ptr, mouse_hook, &f);
	mlx_hook(f.win_ptr, 6, (1L << 6), mouse_place, &f);
	mlx_loop(f.mlx_ptr);
}
