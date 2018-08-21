/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 19:46:49 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/21 20:53:53 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Need to add some colors
*/

static int			exit_redcross(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}

static int			key_hook(int kcode, t_fractol *f)
{
	if (kcode == K_ESC)
		exit(1);
	return (0);
}

int			mouse_zoom(int kcode, int x, int y, t_fractol *f)
{
	if (kcode == SCROLL_DOWN)
		zoom_out(f, x, y);
	else if (kcode == SCROLL_UP)
		zoom_in(f, x, y);
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	draw_image(f);
	return (0);
}

void		set_win(t_fractol *f)
{
	f->size = 2.8;
	f->center_x = -0.65;
	f->center_y = 0.0;
	f->maxiter = 25;
}

void	mandelbrot(void)
{
	t_fractol	f;

	ft_bzero(&f, sizeof(t_fractol));
	f.mlx_ptr = mlx_init();
	f.win_ptr = mlx_new_window(f.mlx_ptr, WIN_SIZE, WIN_SIZE, "Mandelbrot");
	set_win(&f);
	draw_image(&f);
	mlx_do_key_autorepeatoff(f.mlx_ptr);
	mlx_hook(f.win_ptr, 17, (1L << 17), exit_redcross, &f);
	mlx_hook(f.win_ptr, 2, (1L << 0), key_hook, &f);
	mlx_mouse_hook(f.win_ptr, mouse_zoom, &f);
	mlx_loop(f.mlx_ptr);
}

/*
**  COLOR PALETTE
**	1. 1B1D2B
**	2. 092C52
**	3. 1687C4
**	4. 24B3D6
**	5. D5E0EB
*/
