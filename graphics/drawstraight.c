/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawstraight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:17:37 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:16:15 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

void	drawstraighty(t_imgptr ptr, t_line line, t_color color)
{
	double	i;

	if (line.ya > line.yb)
	{
		i = line.ya;
		line.ya = line.yb;
		line.yb = i;
	}
	while (line.ya < line.yb)
	{
		drawdot(ptr, line.xa, line.ya, color);
		line.ya++;
	}
}

void	drawstraightx(t_imgptr ptr, t_line line, t_color color)
{
	double	i;

	if (line.xa > line.xb)
	{
		i = line.xa;
		line.xa = line.xb;
		line.xb = i;
	}
	while (line.xa < line.xb)
	{
		drawdot(ptr, line.xa, line.ya, color);
		line.xa++;
	}
}
