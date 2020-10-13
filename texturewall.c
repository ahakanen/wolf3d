/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturewall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:49:21 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/13 16:13:05 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_color		clrfromtex(t_tex *tex, int x, int y)
{
	t_color	color;
	int		i;

	i = y * tex->imgw + x * 4;
	color.r = tex->img_ptr[i];
	color.g = tex->img_ptr[i + 1];
	color.b = tex->img_ptr[i + 2];
	color.a = tex->img_ptr[i + 3];
	return (color);
}

void		drawtex(t_tparams *p, t_rtex rtex, t_rp rp)
{
	int		i;
	int		end;
	double	step;
	double	stepi;

	step =  (double)TILE / ((int)rp.height << 1);
	stepi = 0;
	i = p->offset - (int)rp.height;
	if (i < 0)
	{
		stepi = -i * step;
		i = 0;
	}
	end = p->offset + (int)rp.height;
	while (i < end && i < WIN_Y)
	{
		drawdot(p->imgptr, rp.start, i, clrfromtex(rtex.tex, rtex.offset, (int)stepi));
		stepi += step;
		i++;
	}
}