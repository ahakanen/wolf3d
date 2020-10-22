/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:01:53 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/19 12:44:01 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	rotation(t_params *params, int dir)
{
	if (dir == WASDLEFT)
	{
		params->p.ai -= 3;
		if (params->p.ai < 0)
			params->p.ai = params->rotarrlast - 3;
		params->p.a = params->rotarr[params->p.ai];
		params->p.dx = params->rotarr[params->p.ai + 1];
		params->p.dy = params->rotarr[params->p.ai + 2];
	}
	if (dir == WASDRIGHT)
	{
		params->p.ai += 3;
		if (params->rotarrlast <= params->p.ai)
			params->p.ai = 0;
		params->p.a = params->rotarr[params->p.ai];
		params->p.dx = params->rotarr[params->p.ai + 1];
		params->p.dy = params->rotarr[params->p.ai + 2];
	}
}

void	movement(t_params *params, int dir)
{
	if (dir == WASDUP)
	{
		checkcollisionxf(params);
		checkcollisionyf(params);
	}
	if (dir == WASDDOWN)
	{
		checkcollisionxb(params);
		checkcollisionyb(params);
	}
}

void	movestop(int key, t_params *params)
{
	if (key == WASDUP)
		params->p.movef = 0;
	if (key == WASDDOWN)
		params->p.moveb = 0;
	if (key == WASDLEFT)
		params->p.rotleft = 0;
	if (key == WASDRIGHT)
		params->p.rotright = 0;
}

void	movestart(int key, t_params *params)
{
	if (key == WASDUP)
		params->p.movef = 1;
	if (key == WASDDOWN)
		params->p.moveb = 1;
	if (key == WASDLEFT)
		params->p.rotleft = 1;
	if (key == WASDRIGHT)
		params->p.rotright = 1;
}
