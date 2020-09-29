/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawdot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 09:58:37 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:18:08 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics/includes/graphics.h"

void	drawdot(t_imgptr ptr, int x, int y, t_color color)
{
	int	i;

	if (0 < ptr.size && 0 <= x && 0 <= y && x < ptr.sizex && y < ptr.sizey)
	{
		i = (y * ptr.sizex + x) * 4;
		if (i < ptr.size)
		{
			ptr.img_ptr[i] = color.r;
			ptr.img_ptr[i + 1] = color.g;
			ptr.img_ptr[i + 2] = color.b;
			ptr.img_ptr[i + 3] = color.a;
		}
	}
}
