/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initabl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:48:59 by dchirol           #+#    #+#             */
/*   Updated: 2017/01/04 22:48:56 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_adapt(t_ulint *tab, int square, t_ulint *adapt)
{
	while (*tab)
	{
		if (square > 3)
		{
			*adapt = (*tab & 0x000f)
				| ((*tab & 0x00f0) << (square - 3))
				| ((*tab & 0x0f00) << (square * 2 - 6))
				| ((*tab & 0xf000) << (square * 3 - 9));
		}
		else
			*adapt = *tab;
		tab++;
		adapt++;
	}
}

static void		ft_deadlyloop(int square, unsigned long int *table)
{
	t_ulint	n;
	int		k;
	int		j;
	int		i;

	k = 0;
	i = 0;
	n = 1 << square;
	while (i < square)
	{
		if ((table[k] << (square + 1)) >= table[k])
			table[k] = (table[k] << (square + 1)) | n;
		else
		{
			j = 0;
			while ((table[k] << j) < 0x8000000000000000)
				j++;
			n = 1 << (square - j);
			k++;
			i--;
		}
		i++;
	}
}

void			ft_initable(unsigned long int *table, int square)
{
	t_ulint	n;
	int		i;
	int		k;

	table[0] = 0;
	table[1] = 0;
	table[2] = 0;
	ft_deadlyloop(square, table);
	n = 1;
	i = 0;
	k = (square > 7) + (square > 10);
	n = n << (square * (square + 2) - 1 - 64 * k);
	while (i < square)
	{
		table[k] = table[k] | n;
		n = n >> 1;
		i++;
	}
}
