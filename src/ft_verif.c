/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:42:28 by dchirol           #+#    #+#             */
/*   Updated: 2017/01/04 22:44:28 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_checkborders(unsigned long int tab)
{
	unsigned long int	n;
	int					nb;

	nb = 0;
	n = 1;
	while (n <= 0x8000)
	{
		if (tab & n)
		{
			nb += (((tab >> 4) & n) == n)
				+ (((tab << 4) & n) == n)
				+ (((tab >> 1) & n) == n && !(n & 0x8888))
				+ (((tab << 1) & n) == n && !(n & 0x1111));
		}
		n = n << 1;
	}
	if (nb < 6)
		ft_afferror(ERROR_FILE);
}

void	ft_check(char *str, unsigned long int *tab)
{
	int i;
	int j;
	int nb;

	nb = 0;
	i = -4;
	while ((i = i + 4) < 16)
	{
		j = 0;
		while (j < 4)
		{
			if (str[j + i] == '#' && nb++ < 4)
				*tab = *tab | 0x10000;
			else if (str[j + i] != '.')
				ft_afferror(ERROR_FILE);
			j++;
			*tab = *tab >> 1;
		}
		if (str[j + i] != '\n')
			ft_afferror(ERROR_FILE);
		str++;
	}
	if (str[i] != '\n' && str[i] != '\0')
		ft_afferror(ERROR_FILE);
}

void	ft_rearrange(unsigned long int *tab)
{
	while (*tab)
	{
		while (!(*tab & 0x000f))
			*tab = *tab >> 4;
		while (!(*tab & 0x1111))
			*tab = *tab >> 1;
		tab++;
	}
}
