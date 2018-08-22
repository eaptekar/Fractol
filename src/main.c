/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:15:18 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/22 18:30:30 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset(t_fractol *f)
{
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	if (f->frac == 1)
		init_mndlbrt(f);
	else if (f->frac == 2)
		init_julia(f);
	draw_image(f);
}

void	fractal_select(char *str)
{
	if (!ft_strcmp(str, "1"))
		mandelbrot();
	else if (!ft_strcmp(str, "2"))
		julia();
}

/*
** Arguments in the main exist only for testing
** It will take the number of the fractal
** But I am going to create window via ./fractal with the list of fractals
** Notes: multi windows, check errors in argv[...]
*/

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_putendl_exit("usage: ./fractol <fractal_number>\n1 - mandelbrot\n2 - julia", 0);
	fractal_select(argv[1]);
	return (0);
}
