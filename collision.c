/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:29:05 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/02 17:51:15 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	checkcollisionxf(t_params *params)
{
	double	help;
	int		i;
	int		j;

	help = params->p.x + params->p.dx * params->p.speed;
	if (params->p.a > HALFPI && params->p.a < THREEHALVESPI)
		i = ((int)(help - (TILE >> 2))) >> 6;
	else
		i = ((int)(help + (TILE >> 2))) >> 6;
	j = (int)params->p.y >> 6;
	if (parsebsolid(params, params->map[j][i]) == 0)
		params->p.x = help;
}

void	checkcollisionxb(t_params *params)
{
	double	help;
	int		i;
	int		j;

	help = params->p.x - params->p.dx * params->p.speed;
	if (params->p.a > HALFPI && params->p.a < THREEHALVESPI)
		i = ((int)(help + (TILE >> 2))) >> 6;
	else
		i = ((int)(help - (TILE >> 2))) >> 6;
	j = (int)params->p.y >> 6;
	if (parsebsolid(params, params->map[j][i]) == 0)
		params->p.x = help;
}

void	checkcollisionyf(t_params *params)
{
	double	help;
	int		i;
	int		j;

	help = params->p.y + params->p.dy * params->p.speed;
	i = (int)params->p.x >> 6;
	if (params->p.a > PI)
		j = ((int)(help - (TILE >> 2))) >> 6;
	else
		j = ((int)(help + (TILE >> 2))) >> 6;
	if (parsebsolid(params, params->map[j][i]) == 0)
		params->p.y = help;
}

void	checkcollisionyb(t_params *params)
{
	double	help;
	int		i;
	int		j;

	help = params->p.y - params->p.dy * params->p.speed;
	i = (int)params->p.x >> 6;
	if (params->p.a > PI)
		j = ((int)(help + (TILE >> 2))) >> 6;
	else
		j = ((int)(help - (TILE >> 2))) >> 6;
	if (parsebsolid(params, params->map[j][i]) == 0)
		params->p.y = help;
}