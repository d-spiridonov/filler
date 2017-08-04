/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:21:04 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/07/22 17:22:24 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	checkfirstmap(t_ifpl *ifpl, t_f *flf, int i, int j)
{
	while (ifpl->x < flf->x_token && i < flf->mapx)
	{
		while (ifpl->y < flf->y_token && j < flf->mapy)
		{
			if (flf->token[ifpl->x][ifpl->y] == flf->map[i][j] && \
					flf->map[i][j] == flf->p)
			{
				ifpl->cont++;
				ifpl->s++;
			}
			else if (flf->token[ifpl->x][ifpl->y] == flf->p && \
					flf->map[i][j] == '.')
				ifpl->s++;
			else if (flf->token[ifpl->x][ifpl->y] == '.')
				ifpl->s++;
			ifpl->y++;
			j++;
		}
		j = ifpl->tmp;
		ifpl->y = 0;
		ifpl->x++;
		i++;
	}
}

void	checksecondmap(t_ifpl *ifpl, t_f *flf, int i, int j)
{
	while (ifpl->x < flf->x_token && i < flf->mapx)
	{
		while (ifpl->y < flf->y_token && j < flf->mapy)
		{
			if (flf->map2[i][j] == flf->p && ifpl->cont < 1 &&
				flf->token[ifpl->x][ifpl->y] == flf->p && j < flf->mapy)
			{
				ifpl->cont++;
				ifpl->s++;
			}
			else if (flf->token[ifpl->x][ifpl->y] == flf->p && flf->map[i][j] \
			== '.' && flf->map2[i][j] == '.')
				ifpl->s++;
			else if (flf->token[ifpl->x][ifpl->y] == '.')
				ifpl->s++;
			ifpl->y++;
			j++;
		}
		j = ifpl->tmp;
		ifpl->y = 0;
		ifpl->x++;
		i++;
	}
}

void	ifplinit(t_ifpl *ifpl, int j)
{
	ifpl->s = 0;
	ifpl->x = 0;
	ifpl->y = 0;
	ifpl->cont = 0;
	ifpl->tmp = j;
}

int		ifplacable(int i, int j, t_f *flf)
{
	t_ifpl	ifpl;

	ifplinit(&ifpl, j);
	if (flf->fst % 2 == 0 || flf->fst == 0)
		checkfirstmap(&ifpl, flf, i, j);
	if (flf->fst % 2 > 0)
		checksecondmap(&ifpl, flf, i, j);
	if (ifpl.cont == 1 && ifpl.s == (flf->y_token * flf->x_token))
		return (1);
	else
		return (-1);
}

void	placetoken(t_f *flf)
{
	int i;
	int j;

	flf->place = 0;
	substitute(flf);
	i = 0;
	j = 0;
	while (i < flf->mapx)
	{
		while (j < flf->mapy + 1)
		{
			if (ifplacable(i, j, flf) == 1)
				priorityset(i, j, flf);
			j++;
		}
		i++;
		j = 0;
	}
	if (flf->place == 1)
		findbest(flf);
	else
		ft_printf("0 0\n");
	clearmemory(flf);
	flf->fst++;
}
