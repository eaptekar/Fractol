/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 20:31:53 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/21 20:38:53 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_fractol *f, int x, int y)
{
	float	new_size;
	float	zoom_change;
	float	offset_x;
	float	offset_y;

	new_size = f->size * 0.9;
	zoom_change = new_size - f->size;
	offset_x = (((WIN_SIZE / 2.0) - x) / WIN_SIZE) * zoom_change;
	offset_y = (((WIN_SIZE / 2.0) - y) / WIN_SIZE) * zoom_change;
	f->center_x = f->center_x + offset_x;
	f->center_y = f->center_y + offset_y;
	f->size = new_size;
}

void	zoom_out(t_fractol *f, int x, int y)
{
	float	new_size;
	float	zoom_change;
	float	offset_x;
	float	offset_y;

	new_size = f->size * 1.1;
	zoom_change = new_size - f->size;
	offset_x = (((WIN_SIZE / 2.0) - x) / WIN_SIZE) * zoom_change;
	offset_y = (((WIN_SIZE / 2.0) - y) / WIN_SIZE) * zoom_change;
	f->center_x = f->center_x + offset_x;
	f->center_y = f->center_y + offset_y;
	f->size = new_size;
}