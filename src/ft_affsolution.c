/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affsolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:45:56 by dchirol           #+#    #+#             */
/*   Updated: 2017/01/04 22:51:57 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_calc(t_ulint *tab, t_ulint *i, int square, char *sol)
{
	int		j;
	int		k;
	char	c;

	c = 'A';
	while (*tab)
	{
		*i = *i - *i / (square + 1);
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if ((*tab >> (j * 4 + k)) & 1)
					sol[*i + j * square + k] = c;
				k++;
			}
			j++;
		}
		tab++;
		i++;
		c++;
	}
}

void			ft_affsolution(t_ulint *tab, t_ulint *i, int square)
{
	char	*sol;
	char	c;
	int		j;

	c = 'A';
	if (!(sol = (char *)malloc(sizeof(*sol) * (square * square + 1))))
		ft_afferror(ERROR_MALLOC);
	ft_memset(sol, '.', square * square);
	ft_calc(tab, i, square, sol);
	sol[square * square] = '\0';
	j = 0;
	while (j < square)
	{
		write(1, sol, square);
		ft_putchar('\n');
		sol += square;
		j++;
	}
}
