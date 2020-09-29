/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openwindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:02:04 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/29 09:57:05 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	close_hook(t_params *params)
{
	(void)params;
	exit(0);
	return (0);
}

static int	expose_hook(t_params *params)
{
	render(params);
	return (0);
}

static void	initminimap(t_params *params)
{
	params->mm.x = params->sizex;
	params->mm.y = params->sizey;
	params->mm.winx = WIN_X / 4;
	params->mm.winy = WIN_Y / 4;
	if ((params->mm.margstart = params->mm.winx - \
			(params->mm.winx / 5)) < params->mm.winy)
		params->mm.skip = 1;
	params->mm.size = params->mm.winx << 2;
	params->mm.p.x = params->mm.margstart >> 1;
	params->mm.p.y = params->mm.winy >> 1;
	initminimapblocks(params);
	params->mm.bsize = params->mm.winx >> 4;
	params->mm.bsizeh = params->mm.bsize >> 1;
}

static void	initwindow(t_params *params)
{
	params->win.mlx_ptr = mlx_init();
	params->win.win_ptr = mlx_new_window(params->win.mlx_ptr, \
							WIN_X, WIN_Y, "wolf3d");
	params->size = WIN_X * 4;
	params->bpp = 32;
	params->endian = END;
	initminimap(params);
}

void		openwindow(t_params *params)
{
	initwindow(params);
	mlx_expose_hook(params->win.win_ptr, expose_hook, params);
	mlx_hook(params->win.win_ptr, 17, (1L << 17), close_hook, params);
	mlx_hook(params->win.win_ptr, 2, (1L << 0), press_key, params);
	mlx_hook(params->win.win_ptr, 3, (1L << 1), release_key, params);
	mlx_loop_hook(params->win.win_ptr, render_loop, params);
	mlx_loop(params->win.mlx_ptr);
}
