/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadtexture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:41:16 by ahakanen          #+#    #+#             */
/*   Updated: 2020/10/13 16:13:38 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_tex	*loadtexture(t_params *params, char *path)
{
	t_tex	*tex;

	if (!(tex = ft_memalloc(sizeof(t_tex))))
		print_error(ERRMEM);
	if (!(tex->img = mlx_xpm_file_to_image(params->win.mlx_ptr, \
			path, &tex->imgw, &tex->imgh)))
		print_error(ERRTEX);
	if (tex->imgw != TILE || tex->imgh != TILE)
		print_error(ERRTEX);
	tex->img_ptr = mlx_get_data_addr(tex->img, &params->bpp, \
				&tex->imgw, &params->endian);
	return (tex);
}

t_tex	*loadtexskybox(t_params *params, char *path)
{
	t_tex	*tex;

	if (!(tex = ft_memalloc(sizeof(t_tex))))
		print_error(ERRMEM);
	if (!(tex->img = mlx_xpm_file_to_image(params->win.mlx_ptr, \
			path, &tex->imgw, &tex->imgh)))
		print_error(ERRSKYBOX);
	if (tex->imgh != WIN_Y >> 1)
		print_error(ERRSKYBOX);
	tex->img_ptr = mlx_get_data_addr(tex->img, &params->bpp, \
				&tex->imgw, &params->endian);
	return (tex);
}
