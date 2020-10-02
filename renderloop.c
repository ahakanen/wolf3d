/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:13:35 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/02 19:14:41 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>//test

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
		if (!(params->fps = ft_itoa((int)(1.0 / params->llimitacc))))
			print_error(ERRMEM);
		render(params);
		mlx_string_put(params->win.mlx_ptr, params->win.win_ptr, \
			params->fpsloc.x, params->fpsloc.y, 0xFFFFFF, params->fps);
		free(params->fps);
		params->llimitacc = 0;
	}
}

int	render_loop(t_params *params)
{
	check(params);
	return (0);
}