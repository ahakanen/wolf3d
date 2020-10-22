/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawminimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:09:51 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/19 12:35:50 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		drawminiborder(t_params *params, int margstart)
{
	int i;

	params->mm.color = (t_color) {120, 120, 120, 0};
	params->mm.margleft = (t_line) {margstart, 0, margstart, params->mm.winy};
	i = margstart;
	while (i < params->mm.winx)
	{
		params->mm.margleft = (t_line) {i, 0, i, params->mm.winy};
		params->mm.color.g += 5;
		if (params->mm.color.g > 250)
			params->mm.color.g = 250;
		drawline(g_initimgptr(params->mm.img_ptr, params->mm.winx, \
				params->mm.winy), params->mm.margleft, params->mm.color);
		i++;
	}
	drawline(g_initimgptr(params->mm.img_ptr, params->mm.winx, \
					params->mm.winy), g_initline(0, params->mm.winy - 1, \
					params->mm.winx, params->mm.winy - 1), params->mm.color);
}

void		drawminimap2(t_params *params)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (j < 17)
	{
		while (i < 17)
		{
			if (params->mm.blocks[j][i] != '0')
			{
				drawblock(params, i, j);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void		drawminimap(t_params *params)
{
	if (params->mm.skip == 0)
	{
		params->mm.img = mlx_new_image(params->win.mlx_ptr, params->mm.winx, \
									params->mm.winy);
		params->mm.img_ptr = mlx_get_data_addr(params->mm.img, &params->bpp, \
										&params->mm.size, &params->endian);
		params->mm.ptr = g_initimgptr(params->mm.img_ptr, params->mm.winx, \
				params->mm.winy);
		drawcirclef(params->mm.ptr, params->mm.p, 3, g_initcolor(0, 250, 0, 0));
		getblocksaroundplayer(params);
		params->mm.poffset = (t_vec2) {(params->p.x - (((int)params->p.x >> 6) \
			<< 6)) / 64, (params->p.y - (((int)params->p.y >> 6) << 6)) / 64};
		params->mm.poffset = matxvec2(scalemat2(params->mm.bsize), \
							params->mm.poffset);
		params->mm.poffset = vecadd2(params->mm.poffset, \
			g_initvec2(-params->mm.bsizeh, -params->mm.bsizeh));
		params->mm.poffset = matxvec2(rotmat2(-params->p.a + 1.5708), \
										params->mm.poffset);
		params->mm.boffset = vecadd2(params->mm.p, params->mm.poffset);
		drawminimap2(params);
		drawminiborder(params, params->mm.margstart);
	}
}
