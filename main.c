/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:38:16 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/02 19:08:19 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			usage(void)
{
	ft_putendl("Usage: ./wolf3d mapfile or ./wolf3d help");
	exit(1);
}

void			print_error(int type)
{
	ft_putstr("Error - ");
	if (type == 0)
		ft_putendl("Default Error");
	if (type == 1)
		ft_putendl("Out of Memory");
	if (type == 2)
		ft_putendl("Invalid Map");
	if (type == 3)
		ft_putendl("Missing or Empty Map?");
	if (type == 4)
		ft_putendl("Texture Error");
	if (type == 5)
		ft_putendl("Block Parse Error");
	exit(1);
}

static void		initthreadlims(t_params *params)
{
	int		i;
	double	j;
	double	lhelp;

	i = 0;
	params->threadlim = (int *)malloc(sizeof(int) * CPUCORES);
	params->tastart = (double *)malloc(sizeof(double) * CPUCORES);
	params->limit = WIN_X / CPUCORES;
	lhelp = params->limit * params->onefov;
	while (i < CPUCORES)
	{
		params->threadlim[i] = params->limit * (i + 1);
		params->tastart[i] = lhelp * i;
		i++;
	}
}

static t_params	initparams(void)
{
	t_params	params;
	params.p.a = 0;
	params.p.x = 0;
	params.p.y = 0;
	params.p.movef = 0;
	params.p.moveb = 0;
	params.p.rotleft = 0;
	params.p.rotright = 0;
	params.fov = 60;
	params.onefov = params.fov * DEG / WIN_X;
	params.offset = WIN_Y >> 1;
	params.rstarthelp = (params.fov >> 1) * DEG;
	params.mhelp = (TILE * WIN_Y >> 1);
	params.mm.skip = 0;
	params.p.ai = 0;
	params.skyclr = g_initcolor(98, 24, 19, 0);
	params.floorclr = g_initcolor(50, 150, 150, 0);
	initthreadlims(&params);
	params.llimit = (double)(1.0 / (double)FRAMELIMIT);
	params.llimitacc = 0;
	params.fps = 0;
	params.fpsloc = g_initvec2(WIN_X - (WIN_X / 16), WIN_Y / 16);
	params.toggletex = 0;
	return (params);
}

int				main(int argc, char **argv)
{
	t_params params;

	if (argc != 2)
		usage();
	if (ft_strcmp(argv[1], "help") == 0)
	{
		help();
		exit(1);
	}
	params = initparams();
	validate(open(argv[1], O_RDONLY), &params);
	savemap(open(argv[1], O_RDONLY), &params);
	initplayerstart(&params);
	initrotarr(&params);
	openwindow(&params);
	return (0);
}
