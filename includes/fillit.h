/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:15:59 by iburel            #+#    #+#             */
/*   Updated: 2017/01/29 16:30:59 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "prototype.h"
# include "libft.h"

# define READ_SIZE 550
# define ERROR_ARG 1
# define ERROR_OPEN 2
# define ERROR_READ 3
# define ERROR_CLOSE 4
# define ERROR_MALLOC 5
# define ERROR_FILE 6

#endif
