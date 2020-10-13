/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawfloor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:55:47 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/13 14:52:13 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>//test

static void	initvalues(t_params *p, t_flr *f)
{
	f->xl = cos(p->p.a - p->rstarthelp);
	f->yl = sin(p->p.a - p->rstarthelp);
	f->xr = cos(p->p.a + p->rstarthelp);
	f->yr = sin(p->p.a + p->rstarthelp);
	f->wpos = f->j - (WIN_Y >> 1);
	f->rd = ((WIN_Y >> 1) << 6) / f->wpos;
	f->step.x = f->rd * (f->xr - f->xl) / WIN_X;
	f->step.y = f->rd * (f->yr - f->yl) / WIN_X;
	f->pos.x = p->p.x + f->rd * f->xl + f->step.x * f->i;
	f->pos.y = p->p.y + f->rd * f->yl + f->step.y * f->i;
}

void		drawfloortex(t_params *p, int xstart, int xlimit, int num)
{
	t_flr	f;

	f.j = WIN_Y;
	while (f.j > WIN_Y >> 1)
	{
		f.i = xstart;
		initvalues(p, &f);
		while (f.i < xlimit)
		{
			if ((int)f.pos.x >> 6 > 0 && (int)f.pos.y >> 6 > 0 && \
				(int)f.pos.x >> 6 < p->sizex && (int)f.pos.y >> 6 < p->sizey)
				f.tex = parsebtex(p, \
					p->map[(int)f.pos.y >> 6][(int)f.pos.x >> 6]);
			else
				f.tex = parsebtex(p, '0');
			drawdot(p->imgptr, f.i, f.j, clrfromtex(f.tex, \
								(int)f.pos.x % TILE, (int)f.pos.y % TILE));
			f.pos = vecadd2(f.pos, f.step);
			f.i++;
		}
		f.j--;
	}
}

void	drawfloor(t_params *params)
{
	int	i;

	i = WIN_Y >> 1;
	while (i < WIN_Y)
	{
		drawline(params->imgptr, g_initline(0, i, WIN_X, i), params->floorclr);
		i++;
	}
}
