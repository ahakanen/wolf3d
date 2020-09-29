/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:40:52 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/29 09:17:27 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check(t_params *params)
{
	if (params->p.movef == 1)
		movement(params, WASDUP);
	if (params->p.moveb == 1)
		movement(params, WASDDOWN);
	if (params->p.rotleft == 1)
		rotation(params, WASDLEFT);
	if (params->p.rotright == 1)
		rotation(params, WASDRIGHT);
	//mlx_clear_window(params->win.mlx_ptr, params->win.win_ptr);
	render(params);
}

int		press_key(int key, t_params *params)
{
	if (key == WASDUP || key == WASDLEFT || \
		key == WASDDOWN || key == WASDRIGHT)
		movestart(key, params);
	check(params);
	return (0);
}

int		release_key(int key, t_params *params)
{
	if (key == ESC)
		exit(0);
	if (key == WASDUP || key == WASDLEFT || \
		key == WASDDOWN || key == WASDRIGHT)
		movestop(key, params);
	check(params);
	return (0);
}
