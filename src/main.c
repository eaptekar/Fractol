/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:15:18 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/29 18:09:22 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_legend(t_fractol *f)
{
	ft_putendl("\n  Control Keys\n");
	ft_putendl("Move = Arrows");
	ft_putendl("Change palette = A or D");
	ft_putendl("Change color = Tab");
	ft_putendl("Reset = Space");
	ft_putendl("Iterations number = Left and Right mouse buttons");
	ft_putendl("Zoom = scroll mouse wheel");
	ft_putendl("Freeze julia or julia_cubic = Q\n");
	ft_putendl("  Choose fractal\n");
	ft_putendl("1 = mandelbrot");
	ft_putendl("2 = julia");
	ft_putendl("3 = burningship");
	ft_putendl("4 = tricorn");
	ft_putendl("5 = mandelbrot_cubic");
	ft_putendl("6 = julia_cubic");
	ft_putendl("7 = buffalo");
	ft_putendl("\nPress [ESC] to quit\n");
}

void		reset(t_fractol *f)
{
	if (f->frac == 1)
		init_mndlbrt(f);
	else if (f->frac == 2)
		init_julia(f);
	else if (f->frac == 3)
		init_ship(f);
	else if (f->frac == 4)
		init_tricorn(f);
	else if (f->frac == 5)
		init_mcube(f);
	else if (f->frac == 6)
		init_jcube(f);
	else if (f->frac == 7)
		init_buffalo(f);
	draw_image(f);
}

void		fractal_change(int kcode, t_fractol *f)
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

static int	fractal_select(char *str, t_fractol *f)
{
	f->palette = 1;
	if (!ft_strcmp(str, "mandelbrot"))
		f->frac = 1;
	else if (!ft_strcmp(str, "julia"))
		f->frac = 2;
	else if (!ft_strcmp(str, "burningship"))
		f->frac = 3;
	else if (!ft_strcmp(str, "tricorn"))
		f->frac = 4;
	else if (!ft_strcmp(str, "mandelbrot_cubic"))
		f->frac = 5;
	else if (!ft_strcmp(str, "julia_cubic"))
		f->frac = 6;
	else if (!ft_strcmp(str, "buffalo"))
		f->frac = 7;
	else
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_fractol	f;

	ft_bzero(&f, sizeof(t_fractol));
	if (argc != 2 || !(fractal_select(argv[1], &f)))
	{
		ft_putendl("Usage: ./fractol <fractal>\n1 - mandelbrot\n2 - julia");
		ft_putendl("3 - burningship\n4 - tricorn\n5 - mandelbrot_cubic");
		ft_putendl_exit("6 - julia_cubic\n7 - buffalo", 0);
	}
	put_legend(&f);
	f.mlx_ptr = mlx_init();
	f.win_ptr = mlx_new_window(f.mlx_ptr, WIN_SIZE, WIN_SIZE, "Fractol");
	reset(&f);
	mlx_hook(f.win_ptr, 17, (1L << 17), exit_redcross, &f);
	mlx_hook(f.win_ptr, 2, (1L << 0), key_hook, &f);
	mlx_mouse_hook(f.win_ptr, mouse_hook, &f);
	mlx_hook(f.win_ptr, 6, (1L << 6), mouse_place, &f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
