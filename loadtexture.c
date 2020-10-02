/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadtexture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:41:16 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/02 14:42:46 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_tex	loadtexture(t_params *params, char *path)
{
	t_tex	tex;
	int		imgw;
    int		imgh;

	if (!(tex.img = mlx_xpm_file_to_image(params->win.mlx_ptr, \
			path, &imgw, &imgh)))
		print_error(ERRTEX);
	if (imgw != TILE || imgh != TILE)
		print_error(ERRTEX);
	tex.img_ptr = mlx_get_data_addr(tex.img, &params->bpp, \
				&imgw, &params->endian);
	return (tex);
}
