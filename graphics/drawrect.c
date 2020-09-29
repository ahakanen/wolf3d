/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawrect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:24:43 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:16:55 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

void	drawsq(t_imgptr ptr, t_vec2 loc, int r, t_color clr)
{
	drawline(ptr, g_initline(loc.x - r, loc.y - r, loc.x + r, loc.y - r), clr);
	drawline(ptr, g_initline(loc.x - r, loc.y - r, loc.x - r, loc.y + r), clr);
	drawline(ptr, g_initline(loc.x + r, loc.y - r, loc.x + r, loc.y + r), clr);
	drawline(ptr, g_initline(loc.x - r, loc.y + r, loc.x + r, loc.y + r), clr);
}

void	drawsqf(t_imgptr ptr, t_vec2 loc, int r, t_color clr)
{
	int	i;
	int	end;

	i = loc.y - r;
	end = loc.y + r;
	while (i < end)
	{
		drawline(ptr, g_initline(loc.x - r, i, \
				loc.x + r, i), clr);
		i++;
	}
}

void	drawrect(t_imgptr ptr, t_vec2 loc, t_vec2 dim, t_color clr)
{
	drawline(ptr, g_initline(loc.x - dim.x, loc.y - dim.y, \
				loc.x + dim.x, loc.y - dim.y), clr);
	drawline(ptr, g_initline(loc.x - dim.x, loc.y - dim.y, \
				loc.x - dim.x, loc.y + dim.y), clr);
	drawline(ptr, g_initline(loc.x + dim.x, loc.y - dim.y, \
				loc.x + dim.x, loc.y + dim.y), clr);
	drawline(ptr, g_initline(loc.x - dim.x, loc.y + dim.y, \
				loc.x + dim.x, loc.y + dim.y), clr);
}

void	drawrectf(t_imgptr ptr, t_vec2 loc, t_vec2 dim, t_color clr)
{
	int	i;
	int	end;

	i = loc.y - dim.y;
	end = loc.y + dim.y;
	while (i < end)
	{
		drawline(ptr, g_initline(loc.x - dim.x, i, \
				loc.x + dim.x, i), clr);
		i++;
	}
}
