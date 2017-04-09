/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:54:45 by iburel            #+#    #+#             */
/*   Updated: 2016/11/03 16:54:46 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_filetostr(char *file)
{
	int		fd;
	int		ret;
	char	*buf;
	char	*str;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_afferror(ERROR_OPEN);
	if (!(buf = (char *)malloc(sizeof(*buf) * (READ_SIZE + 1))))
		ft_afferror(ERROR_MALLOC);
	if ((ret = read(fd, buf, READ_SIZE)) == -1)
		ft_afferror(ERROR_READ);
	if (close(fd) == -1)
		ft_afferror(ERROR_CLOSE);
	if (ret > 545)
		ft_afferror(ERROR_FILE);
	buf[ret] = '\0';
	if (!(str = (char *)malloc(sizeof(*str) * (ret + 1))))
		ft_afferror(ERROR_MALLOC);
	str = ft_strcpy(str, buf);
	free(buf);
	return (str);
}
