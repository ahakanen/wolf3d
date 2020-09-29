/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:31:13 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/22 10:12:08 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	validlast(t_params *params)
{
	int i;

	i = 0;
	while (i < params->sizex)
	{
		if (params->map[params->sizey - 1][i] != '1')
			print_error(ERRMAP);
		i++;
	}
	if (params->sizex < 3 || params->sizey < 3)
		print_error(ERRMAP);
}

static void	parseblocks(char **blocks, t_params *params, int j)
{
	int i;

	if (!(params->map[j] = ft_strnew(params->sizex)))
		print_error(ERRMEM);
	i = 0;
	while (i < params->sizex)
	{
		params->map[j][i] = blocks[i][0];
		i++;
	}
}

void		savemap(int fd, t_params *params)
{
	int		i;
	int		j;
	char	*line;
	char	**blocks;

	if (!(params->map = (char **)malloc(sizeof(char *) * params->sizey)))
		print_error(ERRMEM);
	params->sizex = (params->sizex + 1) / 2;
	j = 0;
	while ((i = ft_gnl(fd, &line)) != 0)
	{
		if (i == -1)
			print_error(ERRDEF);
		if (!(blocks = ft_strsplit(line, ' ')))
			print_error(ERRDEF);
		parseblocks(blocks, params, j);
		ft_freestrarray(blocks);
		free(line);
		j++;
	}
	validlast(params);
}
