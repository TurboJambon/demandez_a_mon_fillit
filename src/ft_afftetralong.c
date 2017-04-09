/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afftetralong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:31:21 by dchirol           #+#    #+#             */
/*   Updated: 2016/12/10 17:42:36 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_afftetralong(unsigned long int *tetra)
{
	unsigned long int	n;

	while (*tetra)
	{
		n = 1;
		while (n <= 0x8000)
		{
			if (*tetra & n)
				ft_putchar('#');
			else
				ft_putchar('.');
			if (n & 0x8888)
				ft_putchar('\n');
			n = n << 1;
		}
		tetra++;
		ft_putchar('\n');
	}
}
