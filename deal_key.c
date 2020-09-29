/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:40:52 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/29 15:15:36 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
