/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 20:54:39 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/22 17:49:49 by eaptekar         ###   ########.fr       */
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
	if (f->frac == 1)
		draw_mandelbrot(f);
	else if (f->frac == 2)
		draw_julia(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}

int		palette(int	num)
{
	int		colors[24];

	colors[0] = 0xA00A1E;
	colors[1] = 0x930A28;
	colors[2] = 0x860A32;
	colors[3] = 0x790A3C;
	colors[4] = 0x6C0A46;
	colors[5] = 0x5F0A50;
	colors[6] = 0x520A5A;
	colors[7] = 0x460A64;
	colors[8] = 0x4B0A69;
	colors[9] = 0x450B6C;
	colors[10] = 0x3F0C70;
	colors[11] = 0x3A0D74;
	colors[12] = 0x340E78;
	colors[13] = 0x2F0F7C;
	colors[14] = 0x291080;
	colors[15] = 0x241184;
	colors[16] = 0x1E1288;
	colors[17] = 0x19148C;
	colors[18] = 0x1E1987;
	colors[19] = 0x652E5A;
	colors[20] = 0xAD442D;
	colors[21] = 0xF55A00;
	colors[22] = 0xFA5F00;
	colors[23] = 0xFF6400;
	return (colors[num]);
}
