/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawfloor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:55:47 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/16 13:08:38 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
