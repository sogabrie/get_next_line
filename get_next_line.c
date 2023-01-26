/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:01:43 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/26 17:22:41 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *ptr, char *pt, int fd)
{
	size_t	i;
	size_t 	j;
	char	c;
	char	mas[BUFFER_SIZE];

	i = 0;
	j = 0;
	while(0 < read(fd, &c, 1) && c != '\n')
	{
		if (i < BUFFER_SIZE)
			mas[i++] = c;
		else
		{
			pt = malloc ((ft_strlen(ptr) + BUFFER_SIZE + 1) * sizeof(char));
			if (!pt)
				return (0);
			frimov(ptr, pt, j);
			catmas(ptr, mas, i); 
			j += i;
			i = 0;
			mas[i++] = c;
		}
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	char	*ptr;
	char	*pt;
	size_t	f;

	if (!fd || !BUFFER_SIZE)
		return (0);
	f = get_line(ptr, pt, fd);
	if (!f)
	{
		if (ptr)
			free(ptr);
		return (0);
	}
	return (ptr);
}
