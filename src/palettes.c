/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:56:05 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/29 11:49:39 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		mandel_wiki(int num)
{
	int		colors[6];

	colors[0] = 0x07034A;
	colors[1] = 0x460328;
	colors[2] = 0x852517;
	colors[3] = 0xC0510A;
	colors[4] = 0xC75704;
	colors[5] = 0xC75704;
	return (colors[num]);
}

static int		psychedelic(int num)
{
	int		colors[6];

	colors[0] = 0x3C00FF;
	colors[1] = 0x00F9FF;
	colors[2] = 0x00FF38;
	colors[3] = 0xFDFF00;
	colors[4] = 0xFD00FF;
	colors[5] = 0xFD00FF;
	return (colors[num]);
}

static int		google(int num)
{
	int		colors[6];

	colors[0] = 0x00d46B;
	colors[1] = 0x0161FF;
	colors[2] = 0xD62D20;
	colors[3] = 0xFFA700;
	colors[4] = 0xFFFFFF;
	colors[5] = 0xFFFFFF;
	return (colors[num]);
}

static int		fiftyshades(int num)
{
	int		colors[6];

	colors[0] = 0x101010;
	colors[1] = 0x404040;
	colors[2] = 0x7F7F7F;
	colors[3] = 0xBFBFBF;
	colors[4] = 0xFFFFFF;
	colors[5] = 0xFFFFFF;
	return (colors[num]);
}

int				get_palette(t_fractol *f, int num)
{
	int		color;

	if (f->palette == 1)
		color = mandel_wiki(num);
	else if (f->palette == 2)
		color = psychedelic(num);
	else if (f->palette == 3)
		color = google(num);
	else if (f->palette == 4)
		color = fiftyshades(num);
	return (color);
}
