/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afftetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 20:46:54 by iburel            #+#    #+#             */
/*   Updated: 2016/12/07 23:28:25 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_afftetra(unsigned long int tetra)
{
	unsigned long int	n;

	n = 1;
	while (n <= 0x8000)
	{
		if (tetra & n)
			ft_putchar('#');
		else
			ft_putchar('.');
		if (n & 0x8888)
			ft_putchar('\n');
		n = n << 1;
	}
}
