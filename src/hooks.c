/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:25:55 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/29 17:17:02 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			exit_redcross(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}

static void	add_hook(int kcode, t_fractol *f)
{
	if (kcode == K_TAB)
	{
		f->offset++;
		if (f->offset == 5)
			f->offset = 0;
	}
	else if (kcode == K_Q)
	{
		if (f->recalc)
			f->recalc = 0;
		else
			f->recalc = 1;
	}
	else if (kcode == K_UP)
		f->center_y += f->size * 0.01;
	else if (kcode == K_DOWN)
		f->center_y -= f->size * 0.01;
	else if (kcode == K_LEFT)
		f->center_x += f->size * 0.01;
	else if (kcode == K_RIGHT)
		f->center_x -= f->size * 0.01;
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
	else if (kcode == K_N_PLUS)
		zoom_center(f);
	else if (kcode == K_A && f->palette >= 2)
		f->palette--;
	else if (kcode == K_D && f->palette <= 3)
		f->palette++;
	add_hook(kcode, f);
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

int			mouse_place(int x, int y, t_fractol *f)
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
