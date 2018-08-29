/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:16:17 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/29 17:59:38 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "mlx_keys_macos.h"

# define WIN_SIZE		1024
# define MAX_ITER		200
# define MIN_ITER		1

# define ERROR(X)		ft_putendl_exit(X, -1)

typedef struct			s_color
{
	int					start_red;
	int					end_red;
	int					start_green;
	int					end_green;
	int					start_blue;
	int					end_blue;
	double				p;
	int					index;
}						t_color;

typedef struct			s_calcul
{
	double				a_0;
	double				b_0;
	double				a;
	double				b;
	double				temp;
}						t_calcul;

typedef struct			s_fractol
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	double				size;
	double				center_x;
	double				center_y;
	double				st_size;
	double				st_x;
	double				st_y;
	int					maxiter;
	int					frac;
	int					mouse_x;
	int					mouse_y;
	int					recalc;
	int					palette;
	int					offset;
}						t_fractol;

void					draw_image(t_fractol *f);
int						pixel2image(t_fractol *f, int x, int y, int colour);
int						get_color(t_fractol *f, double n);
int						get_palette(t_fractol *f, int num);

void					init_mndlbrt(t_fractol *f);
void					draw_mandelbrot(t_fractol *f);

void					init_julia(t_fractol *f);
void					draw_julia(t_fractol *f);

void					init_ship(t_fractol *f);
void					draw_ship(t_fractol *f);

void					init_tricorn(t_fractol *f);
void					draw_tricorn(t_fractol *f);

void					init_mcube(t_fractol *f);
void					draw_mcube(t_fractol *f);

void					init_jcube(t_fractol *f);
void					draw_jcube(t_fractol *f);

void					init_buffalo(t_fractol *f);
void					draw_buffalo(t_fractol *f);

int						mouse_hook(int kcode, int x, int y, t_fractol *f);
int						key_hook(int kcode, t_fractol *f);
void					fractal_change(int kcode, t_fractol *f);
int						exit_redcross(void *param);
void					reset(t_fractol *f);
int						mouse_place(int x, int y, t_fractol *f);
void					put_legend(t_fractol *f);

void					zoom_in(t_fractol *f, int x, int y);
void					zoom_out(t_fractol *f, int x, int y);
void					zoom_center(t_fractol *f);

#endif
