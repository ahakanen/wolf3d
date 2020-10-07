/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initblocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:43:03 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/07 18:43:37 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_block	emptyblock(t_params *params)
{
	t_block block;

	block.mapchar = '0';
	block.mmcolor = g_initcolor(250, 250, 250, 0);
	block.solid = 0;
	block.tex = loadtexture(params, "./textures/testc64.xpm");
	return (block);
}

static t_block	defaultblock(t_params *params)
{
	t_block	block;

	block.mapchar = '1';
	block.mmcolor = g_initcolor(0, 0, 250, 0);
	block.solid = 1;
	block.tex = loadtexture(params, "./textures/test64.xpm");
	return (block);
}

static t_block	startblock(t_params *params)
{
	t_block	block;

	block.mapchar = 'S';
	block.mmcolor = g_initcolor(250, 250, 250, 0);
	block.solid = 0;
	block.tex = loadtexture(params, "./textures/startplatform.xpm");
	return (block);
}

void	initblocks(t_params *params)
{
	int	i;

	i = 0;
	if (!(params->blocks = (t_block *)malloc(sizeof(t_block) * BLOCKCOUNT)))
		print_error(ERRMEM);
	params->blocks[0] = emptyblock(params);
	params->blocks[1] = defaultblock(params);
	params->blocks[2] = startblock(params);
}