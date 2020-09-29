/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotarr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:09:13 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:42:11 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	initrotarr(t_params *params)
{
	int		i;
	int		j;
	double	singlerot;

	i = 0;
	j = 0;
	params->rotarrlast = STARTROTANGLES * 3;
	singlerot = TWOPI / STARTROTANGLES;
	if (!(params->rotarr = (double *)malloc(sizeof(double) * \
			params->rotarrlast)))
		print_error(ERRMEM);
	while (i < params->rotarrlast)
	{
		params->rotarr[i] = singlerot * j;
		params->rotarr[i + 1] = cos(params->rotarr[i]);
		params->rotarr[i + 2] = sin(params->rotarr[i]);
		i += 3;
		j++;
	}
	params->p.dx = params->rotarr[1];
	params->p.dy = params->rotarr[2];
}
