/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:16:17 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/21 20:41:08 by eaptekar         ###   ########.fr       */
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

# define K_ESC		53

#define SCROLL_UP		4
#define SCROLL_DOWN		5

# define ERROR(X)		ft_putendl_exit(X, -1)

typedef struct	s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	float		size;
	float		center_x;
	float		center_y;
	int			maxiter;

}				t_fractol;

void	mandelbrot(void);
void	draw_image(t_fractol *f);
int		palette(int	num);
int		pixel2image(t_fractol *f, int x, int y, int colour);
void	zoom_in(t_fractol *f, int x, int y);
void	zoom_out(t_fractol *f, int x, int y);

#endif