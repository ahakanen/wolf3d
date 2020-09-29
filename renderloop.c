/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:13:35 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/29 16:44:40 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h> //test

void	check(t_params *params)
{
	params->lend = clock();
	params->lcycle = (double)(params->lend - params->lstart) / CLOCKS_PER_SEC;
	params->llimitacc += params->lcycle;
	params->lstart = clock();
	if (params->llimitacc >= params->llimit)
	{
		if (params->p.movef == 1)
			movement(params, WASDUP);
		if (params->p.moveb == 1)
			movement(params, WASDDOWN);
		if (params->p.rotleft == 1)
			rotation(params, WASDLEFT);
		if (params->p.rotright == 1)
			rotation(params, WASDRIGHT);
		params->llimitacc -= params->llimit;
		render(params);
		params->fps = 0;
		params->fps = (int)(1 / params->cframe);
		printf("fps = %d\n", params->fps);//test
	}
}

int	render_loop(t_params *params)
{
	check(params);
	return (0);
}