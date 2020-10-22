/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initplayerstart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 14:02:14 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/22 13:17:01 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		initplayer(t_params *params)
{
	params->p.a = 0;
	params->p.x = 0;
	params->p.y = 0;
	params->p.movef = 0;
	params->p.moveb = 0;
	params->p.rotleft = 0;
	params->p.rotright = 0;
	params->p.strafeleft = 0;
	params->p.straferight = 0;
}

static void	initplayerstart2(t_params *params)
{
	params->p.speed = 4;
	params->p.x = ((int)params->p.x << 6) + 32;
	params->p.y = ((int)params->p.y << 6) + 32;
}

static void	validplayerstart(t_params *params)
{
	if (params->p.x == 0 || params->p.y == 0)
		print_error(ERRMAP);
	initplayerstart2(params);
}

void		initplayerstart(t_params *params)
{
	params->j = 0;
	while (params->j < params->sizey)
	{
		params->i = 0;
		while (params->i < params->sizex)
		{
			if (params->map[params->j][params->i] == '0')
			{
				params->p.x = params->i;
				params->p.y = params->j;
			}
			if (params->map[params->j][params->i] == 'S')
			{
				params->p.x = params->i;
				params->p.y = params->j;
				params->j = params->sizey;
				break ;
			}
			params->i++;
		}
		params->j++;
	}
	validplayerstart(params);
}
