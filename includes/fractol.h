/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:16:17 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/22 19:41:33 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include "libft.h"

# define WIN_SIZE		1024
# define MAX_ITER		100
# define MIN_ITER		1

# define K_ESC			53
# define K_SPACE		49
# define K_Q			12

# define M_BUT_LEFT		1
# define M_BUT_RIGHT	2
# define M_BUT_WHEEL	3
# define M_SCR_UP		4
# define M_SCR_DOWN		5

# define ERROR(X)		ft_putendl_exit(X, -1)

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
	float				size;
	float				center_x;
	float				center_y;
	float				st_size;
	float				st_x;
	float				st_y;
	int					maxiter;
	int					frac;
	int					mouse_x;
	int					mouse_y;
	int					recalc;
}						t_fractol;

void					mandelbrot(void);
void					init_mndlbrt(t_fractol *f);
void					draw_image(t_fractol *f);
void					draw_mandelbrot(t_fractol *f);
int						pixel2image(t_fractol *f, int x, int y, int colour);
int						palette(int	num);

void					init_julia(t_fractol *f);
void					draw_julia(t_fractol *f);
void					julia(void);

int						mouse_hook(int kcode, int x, int y, t_fractol *f);
int						key_hook(int kcode, t_fractol *f);
int						exit_redcross(void *param);
void					reset(t_fractol *f);
int						mouse_place(int x, int y, t_fractol *f);

void					zoom_in(t_fractol *f, int x, int y);
void					zoom_out(t_fractol *f, int x, int y);

#endif
