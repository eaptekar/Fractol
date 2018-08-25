/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:25:55 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/25 18:32:18 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			exit_redcross(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}

static void	fractal_change(int kcode, t_fractol *f)
{
	if (kcode == K_1)
		f->frac = 1;
	else if (kcode == K_2)
		f->frac = 2;
	else if (kcode == K_3)
		f->frac = 3;
	else if (kcode == K_4)
		f->frac = 4;
	else if (kcode == K_5)
		f->frac = 5;
	else if (kcode == K_6)
		f->frac = 6;
	else if (kcode == K_7)
		f->frac = 7;
	reset(f);
}

int			key_hook(int kcode, t_fractol *f)
{
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	if (kcode == K_ESC)
	{
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		exit(1);
	}
	else if (kcode == K_SPACE)
		reset(f);
	else if ((kcode >= K_1 && kcode <= K_5) || kcode == K_7)
		fractal_change(kcode, f);
	else if (kcode == K_Q)
	{
		if (f->recalc)
			f->recalc = 0;
		else
			f->recalc = 1;
	}
	draw_image(f);
	return (0);
}

int			mouse_hook(int kcode, int x, int y, t_fractol *f)
{
	if (kcode == M_BUT_LEFT && f->maxiter < MAX_ITER)
		f->maxiter++;
	else if (kcode == M_BUT_RIGHT && f->maxiter > MIN_ITER)
		f->maxiter--;
	else if (kcode == M_SCR_DOWN)
		zoom_out(f, x, y);
	else if (kcode == M_SCR_UP)
		zoom_in(f, x, y);
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	draw_image(f);
	return (0);
}

int		mouse_place(int x, int y, t_fractol *f)
{
	if (f->recalc)
	{
		f->mouse_x = x;
		f->mouse_y = y;
	}
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	draw_image(f);
	return (0);
}
