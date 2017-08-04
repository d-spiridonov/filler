/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findplace2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:48:35 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/07/22 17:50:50 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	findenemymore(t_f *flf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < flf->mapx)
	{
		while (y < flf->mapy + 1)
		{
			if (flf->map[x][y] != flf->map2[x][y] && (flf->map[x][y] == \
			flf->e || flf->map2[x][y] == flf->e))
			{
				flf->diffx[flf->ei] = x;
				flf->diffy[flf->ei++] = y;
			}
			y++;
		}
		x++;
		y = 0;
	}
}

void	findenemyfirst(t_f *flf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < flf->mapx)
	{
		while (y < flf->mapy + 1)
		{
			if (flf->map[x][y] == flf->e)
				flf->bst[flf->bi].toenemy = checkdistance(x, y, flf);
			y++;
		}
		x++;
		y = 0;
	}
}

int		checkdistancefirst(t_f *flf, int ex, int ey)
{
	int tx;
	int ty;
	int tmp;

	flf->ex = ex;
	flf->ey = ey;
	tx = ex - flf->bst[flf->bi].corx;
	ty = ey - flf->bst[flf->bi].cory;
	modulus(&tx, &ty);
	tmp = tx + ty;
	if (tmp < 0)
		tmp = tmp * -1;
	return (tmp);
}

int		checkdistancemore(t_f *flf, int ex, int ey)
{
	int tx;
	int ty;
	int tmp;
	int new;
	int old;

	tx = ex - flf->bst[flf->bi].corx;
	ty = ey - flf->bst[flf->bi].cory;
	modulus(&tx, &ty);
	new = tx + ty;
	old = (flf->ex - flf->bst[flf->bi].corx) + (flf->ey - \
	flf->bst[flf->bi].cory);
	modulus(&new, &old);
	if (new < old)
	{
		flf->ex = ex;
		flf->ey = ey;
		tmp = tx + ty;
		if (tmp < 0)
			tmp = tmp * -1;
	}
	return (tmp);
}
