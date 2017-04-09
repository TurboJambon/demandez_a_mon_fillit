/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:45:33 by dchirol           #+#    #+#             */
/*   Updated: 2017/01/04 22:51:38 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_middle(t_ulint *tab, t_ulint *table, int square, int *i)
{
	while (*i < 64)
	{
		if (!(table[0] & (*tab << *i)) && !(table[1] & (*tab >> (64 - *i))))
		{
			table[0] = table[0] | (*tab << *i);
			table[1] = table[1] | (*tab >> (64 - *i));
			if (ft_fillit10(tab + 1, table, square))
			{
				*tab = *i;
				return (1);
			}
			table[0] = table[0] ^ (*tab << *i);
			table[1] = table[1] ^ (*tab >> (64 - *i));
		}
		(*i)++;
	}
	return (0);
}

static int		ft_end(t_ulint *tab, t_ulint *table, int square, int *i)
{
	int limit;

	limit = (square + 1) * square;
	while (*i < limit)
	{
		if (!(table[1] & (*tab << (*i - 64))))
		{
			table[1] = table[1] | (*tab << (*i - 64));
			if (ft_fillit10(tab + 1, table, square))
			{
				*tab = *i;
				return (1);
			}
			table[1] = table[1] ^ (*tab << (*i - 64));
		}
		(*i)++;
	}
	return (0);
}

int				ft_fillit10(t_ulint *tab, t_ulint *table, int square)
{
	int	i;
	int	limit;

	if (*tab == 0)
		return (1);
	limit = 64 - 3 * (square + 1) + 4;
	i = -1;
	while (++i < limit)
	{
		if (!(table[0] & (*tab << i)))
		{
			table[0] = table[0] | (*tab << i);
			if (ft_fillit10(tab + 1, table, square))
			{
				*tab = i;
				return (1);
			}
			table[0] = table[0] ^ (*tab << i);
		}
	}
	if (ft_middle(tab, table, square, &i))
		return (1);
	if (ft_end(tab, table, square, &i))
		return (1);
	return (0);
}
