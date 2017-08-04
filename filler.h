/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 14:01:33 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/07/22 17:56:25 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H
# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include "./libft/ft_printf.h"

/*
** toenemy - distance to the enemy
** corx - coordinate of the x that we are going to place
** cory - coordinate of the y that we are going to place
*/

typedef struct	s_bst
{
	int			toenemy;
	int			corx;
	int			cory;
}				t_bst;

/*
** **map - 1st map to read
** **map2 - 2nd map to read
** **token - token to read
** tki - token iterator
** mpi - map iterator
** p - my player
** e - enemy player
** mapx - size of map (x)
** mapy - size of map (y)
** x_token - size of token (x)
** y_token - size of token (y)
** diffx[100] - new tokens of the enemy (x)
** diffy[100] - new tokens of the enemy (y)
** fst - whether we compare with the previous map or the next one
** bst - different placable options and their distance to enemy's nearest point
** bi - iterator for bst
** ei - iterator for diffx and diffy
** ex - variable to keep the best value for distance between enemy and me (x)
** ey - variable to keep the best value for distance between enemy and me (y)
** place - variable to know if we can place the figure
*/

typedef struct	s_f
{
	char		**map;
	char		**map2;
	char		**token;
	int			tki;
	int			mpi;
	char		p;
	char		e;
	size_t		mapx;
	size_t		mapy;
	size_t		x_token;
	size_t		y_token;
	int			diffx[1000];
	int			diffy[1000];
	int			fst;
	t_bst		bst[1000];
	int			bi;
	int			ei;
	int			ex;
	int			ey;
	int			place;
}				t_f;

typedef	struct	s_ifpl
{
	int			cont;
	int			x;
	int			y;
	int			tmp;
	int			s;
}				t_ifpl;

void			checkplayer(char *str, t_f *flf);
int				allocatemem(char *line, t_f *flf);
void			token(char *str, t_f *flf);
int				checkline(char *str, t_f *flf);
int				ifplacable(int i, int j, t_f *flf);
void			substitute(t_f *flf);
void			placetoken(t_f *flf);
void			modulus(int *nw, int *old);
void			clearflf(t_f *flf);
void			priorityset(int i, int j, t_f *flf);
void			findbest(t_f *flf);
void			smallmpx(t_f *flf);
void			initialize(t_f *flf);
void			modulus(int *nw, int *old);
int				checkdistance(int ex, int ey, t_f *flf);
void			checkfirstmap(t_ifpl *ifpl, t_f *flf, int i, int j);
void			checksecondmap(t_ifpl *ifpl, t_f *flf, int i, int j);
void			findenemymore(t_f *flf);
void			findenemyfirst(t_f *flf);
int				checkdistancefirst(t_f *flf, int ex, int ey);
int				checkdistancemore(t_f *flf, int ex, int ey);
void			clearmemory(t_f *flf);
void			ifplinit(t_ifpl *ifpl, int j);

#endif
