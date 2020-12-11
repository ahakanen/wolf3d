/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:23:26 by ahakanen          #+#    #+#             */
/*   Updated: 2020/12/07 12:59:34 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	blockhelp(void)
{
	ft_putendl("S = player start platform");
	ft_putendl("0 = default ground");
	ft_putendl("1 = default wall");
	ft_putendl("2 = stone floor");
	ft_putendl("3 = stone wall");
}

void		help(void)
{
	ft_putendl("__________\n");
	ft_putendl("Map should be a rectangle of 1-blocks with any other blocks");
	ft_putendl("inside, separated by single spaces, file ending on a '\\n'.");
	ft_putendl("The mapfile should not be named 'help'");
	ft_putendl("If there is no player start, it will default to thelast '0'.");
	ft_putendl("There should not be multiple player starts,");
	ft_putendl("The minimum map size is 3x3.");
	ft_putendl("The map must have a place for the player to start in.");
	ft_putendl("__________\n");
	ft_putendl("Blocks:");
	blockhelp();
}
