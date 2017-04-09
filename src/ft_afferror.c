/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afferror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:49:49 by iburel            #+#    #+#             */
/*   Updated: 2016/11/05 15:53:39 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_afferror(int error)
{
	if (error == ERROR_ARG)
		ft_putendl_fd("usage : ./fillit file", 1);
	else if (error == ERROR_OPEN)
		ft_putendl_fd("error", 1);
	else if (error == ERROR_READ)
		ft_putendl_fd("error", 1);
	else if (error == ERROR_CLOSE)
		ft_putendl_fd("error", 1);
	else if (error == ERROR_MALLOC)
		ft_putendl_fd("error", 1);
	else if (error == ERROR_FILE)
		ft_putendl_fd("error", 1);
	exit(0);
}
