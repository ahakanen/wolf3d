/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawcircle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:43:37 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:14:06 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

static void	drawcirclef2(t_circleparams p)
{
	drawline(p.ptr, g_initline(p.loc.x + p.x, p.loc.y + p.y, p.loc.x - p.x, \
				p.loc.y + p.y), p.color);
	drawline(p.ptr, g_initline(p.loc.x + p.x, p.loc.y - p.y, p.loc.x - p.x, \
				p.loc.y - p.y), p.color);
	drawline(p.ptr, g_initline(p.loc.x + p.y, p.loc.y + p.x, p.loc.x - p.y, \
				p.loc.y + p.x), p.color);
	drawline(p.ptr, g_initline(p.loc.x + p.y, p.loc.y - p.x, p.loc.x - p.y, \
				p.loc.y - p.x), p.color);
}

void		drawcirclef(t_imgptr ptr, t_vec2 loc, int r, t_color color)
{
	t_circleparams	p;

	p.ptr = ptr;
	p.loc = loc;
	p.color = color;
	p.x = 0;
	p.y = r;
	p.d = 3 - 2 * r;
	drawcirclef2(p);
	while (p.y >= p.x)
	{
		p.x++;
		if (p.d > 0)
		{
			p.y--;
			p.d = p.d + 4 * (p.x - p.y) + 10;
		}
		else
			p.d = p.d + 4 * p.x + 6;
		drawcirclef2(p);
	}
}

static void	drawcircle2(t_circleparams p)
{
	drawdot(p.ptr, p.loc.x + p.x, p.loc.y + p.y, p.color);
	drawdot(p.ptr, p.loc.x - p.x, p.loc.y + p.y, p.color);
	drawdot(p.ptr, p.loc.x + p.x, p.loc.y - p.y, p.color);
	drawdot(p.ptr, p.loc.x - p.x, p.loc.y - p.y, p.color);
	drawdot(p.ptr, p.loc.x + p.y, p.loc.y + p.x, p.color);
	drawdot(p.ptr, p.loc.x - p.y, p.loc.y + p.x, p.color);
	drawdot(p.ptr, p.loc.x + p.y, p.loc.y - p.x, p.color);
	drawdot(p.ptr, p.loc.x - p.y, p.loc.y - p.x, p.color);
}

void		drawcircle(t_imgptr ptr, t_vec2 loc, int r, t_color color)
{
	t_circleparams	p;

	p.ptr = ptr;
	p.loc = loc;
	p.color = color;
	p.x = 0;
	p.y = r;
	p.d = 3 - 2 * r;
	drawcircle2(p);
	while (p.y >= p.x)
	{
		p.x++;
		if (p.d > 0)
		{
			p.y--;
			p.d = p.d + 4 * (p.x - p.y) + 10;
		}
		else
			p.d = p.d + 4 * p.x + 6;
		drawcircle2(p);
	}
}
