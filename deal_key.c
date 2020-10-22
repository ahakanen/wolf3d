/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:40:52 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/22 13:12:16 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>//test

static	int	arrowtowasd(int key)
{
	if (key == UP)
		return (WASDUP);
	if (key == DOWN)
		return (WASDDOWN);
	if (key == LEFT)
		return (WASDLEFT);
	if (key == RIGHT)
		return (WASDRIGHT);
}

int		press_key(int key, t_params *params)
{
	key = arrowtowasd(key);
	if (key == WASDUP || key == WASDLEFT || \
		key == WASDDOWN || key == WASDRIGHT || \
		key == Q || key == E)
		movestart(key, params);
	if (key == SHIFT)
		params->p.speed = 8;
	if (key == CTRL)
		params->p.speed = 2;
	if (key == T)
		params->toggletex = (params->toggletex + 1) % 2;
	if (key == M)
		params->mm.skip = (params->mm.skip + 1) % 2;
	printf("toggletex = |%d|\n", params->toggletex);//test
	printf("key = |%d|\n", key);//test
	check(params);
	return (0);
}

int		release_key(int key, t_params *params)
{
	key = arrowtowasd(key);
	if (key == ESC)
		exit(0);
	if (key == WASDUP || key == WASDLEFT || \
		key == WASDDOWN || key == WASDRIGHT || \
		key == Q || key == E)
		movestop(key, params);
	if (key == SHIFT)
		params->p.speed = 4;
	if (key == CTRL)
		params->p.speed = 4;
	check(params);
	return (0);
}
