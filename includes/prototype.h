/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 20:43:36 by iburel            #+#    #+#             */
/*   Updated: 2017/01/05 00:27:40 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

typedef	unsigned long int	t_ulint;
typedef unsigned long int	t_ul;

int		ft_power(int nb, int power);
void	ft_afferror(int error);
char	*ft_filetostr(char *file);
void	ft_afftetra(t_ulint tetra);
void	ft_afftetralong(t_ulint *tetra);
void	ft_afftetradapt(t_ulint adapt, int square);
void	ft_afftable(t_ulint *table, int square);
int		ft_fillit7(t_ulint *tab, t_ulint *table, int square);
int		ft_fillit10(t_ulint *tab, t_ulint *table, int square);
int		ft_fillit13(t_ulint *tab, t_ulint *table, int square);
void	ft_affsolution(t_ulint *tab, t_ulint *i, int square);
int		ft_sqrt(int nb);
void	ft_adapt(t_ulint *tab, int square, t_ulint *adapt);
void	ft_initable(t_ulint *table, int square);
void	ft_checkborders(t_ulint tab);
void	ft_check (char *str, t_ulint *tab);
void	ft_rearrange(t_ulint *tab);

#endif
