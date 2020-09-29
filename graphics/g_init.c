/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 13:49:22 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:18:30 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

t_imgptr	g_initimgptr(char *img_ptr, int sizex, int sizey)
{
	t_imgptr imgptr;

	imgptr.img_ptr = img_ptr;
	imgptr.sizex = sizex;
	imgptr.sizey = sizey;
	imgptr.size = sizex * sizey * 4;
	return (imgptr);
}

t_line		g_initline(int xa, int ya, int xb, int yb)
{
	t_line	line;

	line.xa = xa;
	line.ya = ya;
	line.xb = xb;
	line.yb = yb;
	return (line);
}

t_color		g_initcolor(int r, int g, int b, int a)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}
