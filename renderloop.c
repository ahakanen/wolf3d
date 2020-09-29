/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:13:35 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/29 09:45:31 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h> //test

int	render_loop(t_params *params)
{
	int	fps;

	render(params);
	fps = 0;
	fps = (int)params->cframe;
	printf("fps = %d\n", fps);//test
	return (0);
}