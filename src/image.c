/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 20:54:39 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/29 18:06:07 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			pixel2image(t_fractol *f, int x, int y, int color)
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

void		draw_image(t_fractol *f)
{
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIN_SIZE, WIN_SIZE);
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

static int	calc_inter(int start, int end, double p)
{
	if (start == end)
		return (start);
	return ((int)((double)start + (end - start) * p));
}

static int	clr_calc(t_color pick, double p)
{
	int		red;
	int		green;
	int		blue;
	int		color;

	red = calc_inter(pick.start_red, pick.end_red, p);
	green = calc_inter(pick.start_green, pick.end_green, p);
	blue = calc_inter(pick.start_blue, pick.end_blue, p);
	color = blue | (green << 8) | (red << 16);
	return (color);
}

int			get_color(t_fractol *f, double n)
{
	int		color1;
	int		color2;
	int		color;
	int		num;
	t_color	pick;

	pick.index = ((int)(5 * n / f->maxiter) + f->offset) % 5;
	color2 = get_palette(f, pick.index);
	color1 = get_palette(f, pick.index + 1);
	pick.start_red = (color1 & 0xFF0000) >> 16;
	pick.end_red = (color2 & 0xFF0000) >> 16;
	pick.start_green = (color1 & 0xFF00) >> 8;
	pick.end_green = (color2 & 0xFF00) >> 8;
	pick.start_blue = (color1 & 0xFF);
	pick.end_blue = (color2 & 0xFF);
	pick.p = fmod(n / f->maxiter, 1.0f / 5) * 5;
	color = clr_calc(pick, (int)(pick.p + 1) - pick.p);
	return (color);
}
