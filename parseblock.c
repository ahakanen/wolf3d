/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseblock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:46:16 by ahakanen          #+#    #+#             */
/*   Updated: 2020/12/07 12:06:13 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_block	parseb(t_params *params, char b)
{
	int		i;

	i = 0;
	while (i < BLOCKCOUNT)
	{
		if (params->blocks[i].mapchar == b)
			return (params->blocks[i]);
		i++;
	}
	print_error(ERRBLOCKPARSE);
}

t_color	parsebcolor(t_params *params, char b)
{
	int		i;

	i = 0;
	while (i < BLOCKCOUNT)
	{
		if (params->blocks[i].mapchar == b)
			return (params->blocks[i].mmcolor);
		i++;
	}
	print_error(ERRBLOCKPARSE);
}

int		parsebsolid(t_params *params, char b)
{
	int		i;

	i = 0;
	while (i < BLOCKCOUNT)
	{
		if (params->blocks[i].mapchar == b)
			return (params->blocks[i].solid);
		i++;
	}
	print_error(ERRBLOCKPARSE);
}

t_tex	*parsebtex(t_params *params, char b)
{
	int		i;

	i = 0;
	while (i < BLOCKCOUNT)
	{
		if (params->blocks[i].mapchar == b)
			return (params->blocks[i].tex);
		i++;
	}
	print_error(ERRBLOCKPARSE);
}
