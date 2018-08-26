/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:56:05 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/26 20:00:24 by eaptekar         ###   ########.fr       */
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

int		get_palette(t_fractol *f, int num)
{
	int		color;

	if (f->palette == 1)
		color = mandel_wiki(num);
	else if (f->palette == 2)
		color = psychedelic(num);
	else if (f->palette == 3)
		color = google(num);
	return (color);
}

// int		pal1(int num)
// {
// 	int		colors[22];

// 	colors[0] = 0xA00A1E;
// 	colors[1] = 0x930A28;
// 	colors[2] = 0x860A32;
// 	colors[3] = 0x790A3C;
// 	colors[4] = 0x6C0A46;
// 	colors[5] = 0x5F0A50;
// 	colors[6] = 0x520A5A;
// 	colors[7] = 0x460A64;
// 	colors[8] = 0x450B6C;
// 	colors[9] = 0x3F0C70;
// 	colors[10] = 0x3A0D74;
// 	colors[11] = 0x340E78;
// 	colors[12] = 0x2F0F7C;
// 	colors[13] = 0x291080;
// 	colors[14] = 0x1E1288;
// 	colors[15] = 0x19148C;
// 	colors[16] = 0x1E1987;
// 	colors[17] = 0x652E5A;
// 	colors[18] = 0xAD442D;
// 	colors[19] = 0xF55A00;
// 	colors[20] = 0xFA5F00;
// 	colors[21] = 0xFF6400;	
// 	return (colors[num]);
// }
