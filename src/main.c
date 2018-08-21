/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:15:18 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/19 19:46:15 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

/*
** Arguments in the main exist only for testing
** It will take the name of the fractal
** But I am going to create window via ./fractal with the list of fractals
** Notes: multi windows, check errors in argv[...] 
** For now i will only write programm for mandelbrot set
*/

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_putendl_exit("usage: ./fractol <fractal_name>\n- mandelbrot", 0);
	mandelbrot();
	return (0);
}