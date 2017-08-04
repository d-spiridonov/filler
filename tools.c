/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:51:23 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/07/22 19:44:18 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	clearflf(t_f *flf)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		flf->bst[i].corx = -1;
		flf->bst[i].cory = -1;
		flf->bst[i].toenemy = -1;
		flf->diffx[i] = 0;
		flf->diffy[i++] = 0;
	}
	flf->bi = 0;
}

void	initialize(t_f *flf)
{
	flf->x_token = 0;
	flf->y_token = 0;
	flf->tki = 0;
	flf->mpi = 0;
	flf->ex = -1;
	flf->ey = -1;
}

void	substitute(t_f *flf)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = (char)((flf->p == 'O') ? 'O' : 'X');
	while (i < flf->x_token)
	{
		while (j < flf->y_token)
		{
			if (flf->token[i][j] == '.')
				j++;
			if (flf->token[i][j] == '*')
				flf->token[i][j++] = c;
		}
		i++;
		j = 0;
	}
}

void	smallmpx(t_f *flf)
{
	int tx;
	int ty;

	if (flf->map[3][3] != 'X')
	{
		tx = 3 - flf->bst[flf->bi].corx;
		ty = 3 - flf->bst[flf->bi].cory;
		modulus(&tx, &ty);
		flf->bst[flf->bi].toenemy = tx + ty;
	}
	else
	{
		tx = 5 - flf->bst[flf->bi].corx;
		ty = 16 - flf->bst[flf->bi].cory;
		modulus(&tx, &ty);
		flf->bst[flf->bi].toenemy = tx + ty;
	}
	if (flf->bst[flf->bi].toenemy < 0)
		flf->bst[flf->bi].toenemy = flf->bst[flf->bi].toenemy * -1;
}

void	clearmemory(t_f *flf)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	if (flf->fst % 2 > 0)
	{
		while (i < flf->mapx)
			ft_strdel(&flf->map[i++]);
		free(flf->map);
	}
	else if (flf->fst % 2 == 0 && flf->fst != 0)
	{
		while (i < flf->mapx)
			ft_strdel(&flf->map2[i++]);
		free(flf->map2);
	}
	while (i2 < flf->x_token)
		ft_strdel(&flf->token[i2++]);
	free(flf->token);
}
