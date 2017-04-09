/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:45:12 by dchirol           #+#    #+#             */
/*   Updated: 2017/02/02 22:57:11 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void		ft_init2(int *square, t_ul **tab, t_ul **adapt, t_ul **table)
{
	int		nb;

	nb = *square;
	*square = ft_sqrt(nb * 4);
	if (*square == 2)
	{
		if (nb == 1 && **tab == 0x0033)
		{
			ft_putstr("AA\nAA\n");
			exit(4);
		}
		else
			*square = 3;
	}
	if (!(*adapt = (t_ulint *)ft_memalloc(sizeof(**adapt) * (nb + 1))))
		ft_afferror(ERROR_MALLOC);
	ft_adapt(*tab, *square, *adapt);
	if (!(*table = (t_ulint *)malloc(sizeof(**table) * 3)))
		ft_afferror(ERROR_MALLOC);
	ft_initable(*table, *square);
}

static void		ft_init(t_ulint **tab, char *name, int *nb)
{
	char				*str;
	int					i;

	str = ft_filetostr(name);
	*nb = ft_strlen(str) + 1;
	if (*nb % 21 != 0)
		ft_afferror(ERROR_FILE);
	*nb /= 21;
	if (!(*tab = (t_ulint *)ft_memalloc(sizeof(**tab) * (*nb + 1))))
		ft_afferror(ERROR_MALLOC);
	i = 0;
	while (i < *nb)
	{
		ft_check(str, *tab + i);
		ft_checkborders((*tab)[i]);
		str += 21;
		i++;
	}
	ft_rearrange(*tab);
}

int				main(int ac, char **av)
{
	int					(*f)(t_ulint *, t_ulint *, int);
	unsigned long int	*tab;
	unsigned long int	*adapt;
	unsigned long int	*table;
	int					square;

	if (ac != 2)
		ft_afferror(ERROR_ARG);
	ft_init(&tab, av[1], &square);
	ft_init2(&square, &tab, &adapt, &table);
	while (1)
	{
		if (square < 8)
			f = &ft_fillit7;
		else if (square < 11)
			f = &ft_fillit10;
		else
			f = &ft_fillit13;
		if ((*f)(adapt, table, square))
			break ;
		square++;
		ft_adapt(tab, square, adapt);
		ft_initable(table, square);
	}
	printf("Square *square : %d\n", square * square);
	printf("Table %lu\n", *table);
	printf("Tab %lu\n", tab[1]);
	printf("Adapt %lu", *adapt);
	ft_affsolution(tab, adapt, square);
}
