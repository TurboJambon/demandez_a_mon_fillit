/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit13.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:45:55 by dchirol           #+#    #+#             */
/*   Updated: 2017/01/04 22:50:46 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_start(t_ulint *tab, t_ulint *table, int square, int *i)
{
	int limit;
	int k;

	k = square / 100;
	square %= 100;
	limit = 64 + 64 * k - 3 * (square + 1) + 4;
	while (*i < limit)
	{
		if (!(table[k] & (*tab << *i)))
		{
			table[k] = table[k] | (*tab << *i);
			if (ft_fillit13(tab + 1, table, square))
			{
				*tab = *i;
				return (1);
			}
			table[k] = table[k] ^ (*tab << *i);
		}
		(*i)++;
	}
	return (0);
}

static int		ft_middle(t_ulint *tab, t_ulint *table, int square, int *i)
{
	int k;

	k = square / 100;
	square %= 100;
	while (*i < 64 + 64 * k)
	{
		if (!(table[k] & (*tab << *i)) && !(table[k] & (*tab >> (64 - *i))))
		{
			table[k] = table[k] | (*tab << *i);
			table[k + 1] = table[k + 1] | (*tab >> (64 - *i));
			if (ft_fillit13(tab + 1, table, square))
			{
				*tab = *i;
				return (1);
			}
			table[k] = table[k] ^ (*tab << *i);
			table[k + 1] = table[k + 1] ^ (*tab >> (64 - *i));
		}
		(*i)++;
	}
	return (0);
}

static int		ft_end(t_ulint *tab, t_ulint *table, int square, int *i)
{
	int limit;

	square %= 100;
	limit = (square + 1) * square;
	while (*i < limit)
	{
		if (!(table[2] & (*tab << (*i - 128))))
		{
			table[2] = table[2] | (*tab << (*i - 128));
			if (ft_fillit13(tab + 1, table, square))
			{
				*tab = *i;
				return (1);
			}
			table[2] = table[2] ^ (*tab << (*i - 128));
		}
		(*i)++;
	}
	return (0);
}

int				ft_fillit13(t_ulint *tab, t_ulint *table, int square)
{
	int		i;
	int		k;

	if (*tab == 0)
		return (1);
	k = 0;
	i = 0;
	while (k < 2)
	{
		square += 100 * k;
		if (ft_start(tab, table, square, &i))
			return (1);
		if (ft_middle(tab, table, square, &i))
			return (1);
		k++;
	}
	if (ft_end(tab, table, square, &i))
		return (1);
	return (0);
}
