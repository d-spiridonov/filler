/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findplace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:46:56 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/07/22 17:48:10 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	modulus(int *nw, int *old)
{
	if (*nw < 0)
		*nw = *nw * -1;
	if (*old < 0)
		*old = *old * -1;
}

void	findbest(t_f *flf)
{
	int fin;
	int tmp;

	if (flf->bi > 0)
		flf->bi--;
	tmp = flf->bi;
	fin = flf->bi;
	while (tmp > -1)
	{
		if (flf->bst[fin].toenemy > flf->bst[tmp].toenemy)
			fin = tmp;
		tmp--;
	}
	ft_printf("%d %d\n", flf->bst[fin].corx, flf->bst[fin].cory);
}

int		checkdistance(int ex, int ey, t_f *flf)
{
	int tmp;

	if (flf->ex == -1 && flf->ey == -1)
		tmp = checkdistancefirst(flf, ex, ey);
	else
		tmp = checkdistancemore(flf, ex, ey);
	return (tmp);
}

void	findenemy(t_f *flf)
{
	flf->ei = 0;
	if (flf->fst > 0)
		findenemymore(flf);
	else
		findenemyfirst(flf);
	if (flf->ei > 0)
		flf->ei--;
	while (flf->ei > -1)
		flf->bst[flf->bi].toenemy = checkdistance(flf->diffx[flf->ei], \
		flf->diffy[flf->ei--], flf);
}

void	priorityset(int i, int j, t_f *flf)
{
	flf->place = 1;
	flf->ex = -1;
	flf->ey = -1;
	flf->bst[flf->bi].corx = i;
	flf->bst[flf->bi].cory = j;
	if (flf->p == 'X' && flf->mapx == 15 && flf->map[5][16] != 'X')
		smallmpx(flf);
	else
		findenemy(flf);
	flf->bi++;
}
