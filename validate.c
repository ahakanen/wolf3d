/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:24:57 by ahakanen          #+#    #+#             */
/*   Updated: 2020/09/23 11:35:08 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	validline(char *line, t_params *params)
{
	int	i;

	i = 0;
	if (params->isfirst == 1)
		while (line[i])
		{
			if (line[i] != '1' && i % 2 == 0)
				print_error(ERRMAP);
			if (line[i] != ' ' && i % 2 == 1)
				print_error(ERRMAP);
			i++;
		}
	else
		while (line[i])
		{
			if (line[i] == ' ' && i % 2 == 0)
				print_error(ERRMAP);
			if (line[i] != ' ' && i % 2 == 1)
				print_error(ERRMAP);
			i++;
		}
}

void		validate(const int fd, t_params *params)
{
	int		i;
	char	*line;

	i = 0;
	params->sizey = 0;
	params->isfirst = 1;
	if (read(fd, NULL, 0) == -1)
		print_error(ERREMPTY);
	while ((i = ft_gnl(fd, &line)) != 0)
	{
		if (i == -1)
			print_error(ERRMAP);
		if (params->isfirst == 1)
			params->sizex = ft_strlen(line);
		else if ((int)ft_strlen(line) != params->sizex)
			print_error(ERRMAP);
		validline(line, params);
		params->sizey++;
		params->isfirst = 0;
		free(line);
	}
	if (params->isfirst == 1)
		print_error(ERREMPTY);
}
