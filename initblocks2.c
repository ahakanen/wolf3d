/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initblocks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:00:01 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/13 19:02:36 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_block	stonewallvine(t_params *params)
{
	t_block	block;

	block.mapchar = '3';
	block.mmcolor = g_initcolor(0, 0, 250, 0);
	block.solid = 1;
	block.tex = loadtexture(params, "./textures/wallvine.xpm");
	return (block);
}

void	initblocks2(t_params *params)
{
	params->blocks[4] = stonewallvine(params);
}