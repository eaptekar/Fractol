/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 20:54:39 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/25 21:16:59 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// CHECK ALL MLX RETURNS

int		pixel2image(t_fractol *f, int x, int y, int color)
{
	char			*pixel;
	int				bpp;
	int				size_line;
	int				endian;

	if (x >= WIN_SIZE || x < 1 || y >= WIN_SIZE || y < 1)
		return (1);
	pixel = mlx_get_data_addr(f->img_ptr, &bpp, &size_line, &endian);
	ft_memmove((void*)(&pixel[y * size_line + \
		x * (bpp / 8)]), (void*)&color, 4);
	return (0);
}

void	draw_image(t_fractol *f)
{
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIN_SIZE, WIN_SIZE);
	f->palette = 1;
	if (f->frac == 1)
		draw_mandelbrot(f);
	else if (f->frac == 2)
		draw_julia(f);
	else if (f->frac == 3)
		draw_ship(f);
	else if (f->frac == 4)
		draw_tricorn(f);
	else if (f->frac == 5)
		draw_mcube(f);
	else if (f->frac == 6)
		draw_jcube(f);
	else if (f->frac == 7)
		draw_buffalo(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}

static int			clr_calc(t_color pick, int n)
{
	int		red;
	int		green;
	int		blue;
	int		color;

	red = pick.start_red + (pick.end_red - pick.start_red) * n / pick.maxiter;
	green = pick.start_green + (pick.end_green - pick.start_green) * n / pick.maxiter;
	blue = pick.start_blue + (pick.end_blue - pick.start_blue) * n / pick.maxiter;
	color = blue | (green << 8) | (red << 16);
	return (color);
}

int				palette(t_fractol *f, int n)
{
	int		color;
	t_color	pick;

	// if (f->palette == 1)
	// 	color = init(num);
	// else if (f->palette == 2)
	// 	color = mandel_wiki(num);
	pick.start_red = 173;
	pick.end_red = 0;
	pick.start_green = 40;
	pick.end_green = 250;
	pick.start_blue = 73;
	pick.end_blue = 218;
	pick.maxiter = f->maxiter;
	color = clr_calc(pick, n);
	return (color);
}
