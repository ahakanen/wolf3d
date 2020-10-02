/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimapblocks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 10:12:38 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/02 17:36:41 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	drawblock(t_params *params, int i, int j)
{
	t_polyline	*pl;

	params->mm.blockv = g_initvec2(params->mm.boffset.x + (i - 8) * \
		params->mm.bsize, params->mm.boffset.y + (j - 8) * params->mm.bsize);
	pl = plmakesq(params->mm.blockv, params->mm.bsizeh);
	plshiftxapplymat(&pl, rotmat2(-params->p.a + 4.71239), params->mm.boffset);
	pldraw(&pl, params->mm.ptr, parsebcolor(params, params->mm.blocks[j][i]));
	pldel(&pl);
}

void	initminimapblocks(t_params *params)
{
	int		i;

	i = 0;
	params->mm.blocks = (char **)malloc(sizeof(char*) * 18);
	while (i < 17)
	{
		params->mm.blocks[i] = ft_strnew(17);
		i++;
	}
	params->mm.blocks[17] = NULL;
}

void	getblocksaroundplayer(t_params *params)
{
	int		i;
	int		j;
	int		startx;
	int		starty;

	i = 0;
	j = 0;
	startx = ((int)params->p.x >> 6) - 8;
	starty = ((int)params->p.y >> 6) - 8;
	while (j < 17)
	{
		while (i < 17)
		{
			if (starty + j >= 0 && startx + i >= 0 && \
				startx + i < params->sizex && starty + j < params->sizey)
				params->mm.blocks[j][i] = params->map[starty + j][startx + i];
			else
				params->mm.blocks[j][i] = '0';
			i++;
		}
		j++;
		i = 0;
	}
}
