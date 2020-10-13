/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsky.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:55:47 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/13 18:17:36 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_color	getskyclr(t_tex *tex, int x, int y)
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

void	initskybox(t_params *p)
{
	p->sky.tex = loadtexskybox(p, "./textures/skyboxnight.xpm");
	p->sky.w = p->sky.tex->imgw >> 2;
	p->sky.start = WIN_X * 360 / p->fov / TWOPI;
}

void	drawskybox(t_params *p)
{
	int		i;
	int		j;
	int		pos;
	int		start;
	double	help;

	j = (WIN_Y >> 1) - 1;
	help = p->p.a - p->rstarthelp;
	if (help < 0)
		help += TWOPI;
	start = (int)(help * p->sky.start);
	while (j >= 0)
	{
		i = 0;
		pos = start;
		while (i < WIN_X)
		{
			drawdot(p->imgptr, i, j, getskyclr(p->sky.tex, \
					(int)pos % p->sky.w, j));
			pos++;
			i++;
		}
		j--;
	}
}

void	drawsky(t_params *params)
{
	int	i;
	int	end;

	i = 0;
	end = WIN_Y >> 1;
	while (i < end)
	{
		drawline(params->imgptr, g_initline(0, i, WIN_X, i), params->skyclr);
		i++;
	}
}
