/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 13:58:25 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/07/22 17:54:12 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	checkplayer(char *str, t_f *flf)
{
	if (str[10] == '1')
	{
		flf->p = 'O';
		flf->e = 'X';
	}
	else
	{
		flf->p = 'X';
		flf->e = 'O';
	}
}

int		allocatemem(char *line, t_f *flf)
{
	int i;

	flf->mapx = 0;
	flf->mapy = 0;
	i = 8;
	while (ft_isdigit(line[i]) == 1)
		flf->mapx = flf->mapx * 10 + line[i++] - 48;
	i++;
	while (ft_isdigit(line[i]) == 1)
		flf->mapy = flf->mapy * 10 + line[i++] - 48;
	if (flf->fst % 2 == 0 || flf->fst == 0)
		flf->map = (char**)malloc(sizeof(char*) * (flf->mapx + 1));
	if (flf->fst % 2 > 0)
		flf->map2 = (char**)malloc(sizeof(char*) * (flf->mapx + 1));
	return (0);
}

void	token(char *str, t_f *flf)
{
	int i;

	i = 6;
	while (ft_isdigit(str[i]))
		flf->x_token = flf->x_token * 10 + str[i++] - 48;
	i++;
	while (ft_isdigit(str[i]))
		flf->y_token = flf->y_token * 10 + str[i++] - 48;
	flf->token = (char **)malloc(sizeof(char *) * (flf->x_token + 1));
}

int		checkline(char *str, t_f *flf)
{
	if (str[0] == ' ')
	{
		flf->bi = 0;
		return (0);
	}
	if (str[0] == '$')
		checkplayer(str, flf);
	else if (str[1] == 'l')
	{
		initialize(flf);
		allocatemem(str, flf);
	}
	else if (ft_isdigit(str[0]) && (flf->fst % 2 == 0 || flf->fst == 0))
		flf->map[flf->mpi++] = ft_strsub(str, 4, flf->mapy);
	else if (ft_isdigit(str[0]) && flf->fst % 2 > 0)
		flf->map2[flf->mpi++] = ft_strsub(str, 4, flf->mapy);
	else if (str[1] == 'i')
		token(str, flf);
	else if (ft_strchr(str, '*') || ft_strchr(str, '.'))
	{
		flf->token[flf->tki++] = ft_strdup(str);
		if (flf->tki == flf->x_token && flf->tki > 0)
			placetoken(flf);
	}
	return (0);
}

int		main(void)
{
	char	*str;
	t_f		flf;

	initialize(&flf);
	flf.fst = 0;
	while (get_next_line(0, &str) == 1)
	{
		checkline(str, &flf);
		clearflf(&flf);
		ft_strdel(&str);
	}
	return (0);
}
