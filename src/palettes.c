/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:56:05 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/25 20:31:53 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init(int num)
{
	int		colors[22];

	colors[0] = 0xA00A1E;
	colors[1] = 0x930A28;
	colors[2] = 0x860A32;
	colors[3] = 0x790A3C;
	colors[4] = 0x6C0A46;
	colors[5] = 0x5F0A50;
	colors[6] = 0x520A5A;
	colors[7] = 0x460A64;
	colors[8] = 0x450B6C;
	colors[9] = 0x3F0C70;
	colors[10] = 0x3A0D74;
	colors[11] = 0x340E78;
	colors[12] = 0x2F0F7C;
	colors[13] = 0x291080;
	colors[14] = 0x1E1288;
	colors[15] = 0x19148C;
	colors[16] = 0x1E1987;
	colors[17] = 0x652E5A;
	colors[18] = 0xAD442D;
	colors[19] = 0xF55A00;
	colors[20] = 0xFA5F00;
	colors[21] = 0xFF6400;	
	return (colors[num]);
}

int		mandel_wiki(int num)
{
	int		colors[12];

	colors[0] = 0x000F57;
	colors[1] = 0x001372;
	colors[2] = 0x4235FF;
	colors[3] = 0xB1C2FF;
	colors[4] = 0xFFFADC;
	colors[5] = 0xFFD653;
	colors[6] = 0xFF871A;
	colors[7] = 0xF29F03;
	colors[8] = 0xA3350F;
	colors[9] = 0x711B1B;
	colors[10] = 0x4F0C13;
	colors[11] = 0x000E45;
	return (colors[num]);
}