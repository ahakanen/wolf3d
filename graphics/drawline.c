/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:13:29 by ahakanen          #+#    #+#             */
/*   Updated: 2020/08/28 14:48:18 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

static void	invert2(t_imgptr ptr, t_line line, t_dl ints, t_color color)
{
	while (ints.y > line.yb)
	{
		if (ints.p >= 0)
		{
			drawdot(ptr, ints.x, ints.y, color);
			ints.x = ints.x + 1;
			ints.p = ints.p + 2 * ints.dx - 2 * ints.dy;
		}
		else
		{
			drawdot(ptr, ints.x, ints.y, color);
			ints.p = ints.p + 2 * ints.dx;
		}
		ints.y = ints.y - 1;
	}
}

static void	drawline2(t_imgptr ptr, t_line line, t_dl ints, t_color color)
{
	while (ints.y < line.yb)
	{
		if (ints.p >= 0)
		{
			drawdot(ptr, ints.x, ints.y, color);
			ints.x = ints.x + 1;
			ints.p = ints.p + 2 * ints.dx - 2 * ints.dy;
		}
		else
		{
			drawdot(ptr, ints.x, ints.y, color);
			ints.p = ints.p + 2 * ints.dx;
		}
		ints.y = ints.y + 1;
	}
}

static void	invert1(t_imgptr ptr, t_line line, t_dl ints, t_color color)
{
	while (ints.x < line.xb)
	{
		if (ints.p >= 0)
		{
			drawdot(ptr, ints.x, ints.y, color);
			ints.y = ints.y - 1;
			ints.p = ints.p + 2 * ints.dy - 2 * ints.dx;
		}
		else
		{
			drawdot(ptr, ints.x, ints.y, color);
			ints.p = ints.p + 2 * ints.dy;
		}
		ints.x = ints.x + 1;
	}
}

static void	drawline1(t_imgptr ptr, t_line line, t_dl ints, t_color color)
{
	while (ints.x < line.xb)
	{
		if (ints.p >= 0)
		{
			drawdot(ptr, ints.x, ints.y, color);
			ints.y = ints.y + 1;
			ints.p = ints.p + 2 * ints.dy - 2 * ints.dx;
		}
		else
		{
			drawdot(ptr, ints.x, ints.y, color);
			ints.p = ints.p + 2 * ints.dy;
		}
		ints.x = ints.x + 1;
	}
}

void		drawline(t_imgptr ptr, t_line line, t_color color)
{
	t_dl	ints;

	if (line.xa > line.xb)
		reverseline(&line);
	if ((ints.dx = ft_abs(line.xb - line.xa)) == 0)
		drawstraighty(ptr, line, color);
	else if ((ints.dy = ft_abs(line.yb - line.ya)) == 0)
		drawstraightx(ptr, line, color);
	else
	{
		ints.x = line.xa;
		ints.y = line.ya;
		ints.p = 2 * ints.dy - ints.dx;
		ints.m = slope(line.xa, line.ya, line.xb, line.yb);
		if (-1 <= ints.m && ints.m < 0)
			invert1(ptr, line, ints, color);
		else if (0 <= ints.m && ints.m <= 1)
			drawline1(ptr, line, ints, color);
		else if (ints.m < -1)
			invert2(ptr, line, ints, color);
		else
			drawline2(ptr, line, ints, color);
	}
}
