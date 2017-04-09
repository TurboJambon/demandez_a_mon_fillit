/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:40:55 by dchirol           #+#    #+#             */
/*   Updated: 2017/01/29 18:34:32 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fillit7(t_ulint *tab, t_ulint *table, int square)
{
	int	i;
	int	limit;

	if (*tab == 0)
		return (1);
	limit = (square + 1) * (square);
	i = 0;
	while (i < limit)
	{
		if (!(*table & (*tab << i)))
		{
			*table |= (*tab << i);
			if (ft_fillit7(tab + 1, table, square))
			{
				*tab = i;
				return (1);
			}
			*table ^= *tab << i;
		}
		i++;
	}
	return (0);
}
