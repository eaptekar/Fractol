/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:25:55 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/22 19:30:07 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			exit_redcross(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}

int			key_hook(int kcode, t_fractol *f)
{
	if (kcode == K_ESC)
	{
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		exit(1);
	}
	else if (kcode == K_SPACE)
		reset(f);
	else if (kcode == K_Q)
	{
		if (f->recalc)
			f->recalc = 0;
		else
			f->recalc = 1;
	}
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
