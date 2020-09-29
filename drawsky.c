/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsky.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:55:47 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/16 13:08:31 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
