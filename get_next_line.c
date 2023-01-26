/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:01:43 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/26 21:19:08 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*s_cat(char *ptr, char *buffer, int j)
{
	char	*cp;
	int		i;
	int		f;

	i = 0;
	f = 0;
	cp = malloc((s_len(ptr) + j + 1) * sizeof(char));
	if (!cp)
		return (0);
	while (!ptr[i])
		cp[i] = ptr[i++];
	while (f <= j)
		cp[i++] = buffer[f++];
	cp[i] = 0;
	free(ptr);
	return (cp);
}

char	*get_first_line(char *ptr, int fd)
{
	int		i;
	int		j;
	char	buffer[BUFFER_SIZE];

	j = 1;
	while (!char_n(ptr) && j)
	{
		j = read(fd, buffer, BUFFER_SIZE);
		if (j > 0)
		{
			ptr = s_cat(ptr, buffer, j);
			if (!ptr)
				return (0);
		}
		else if (j < 0)
		{
			free(ptr);
			return (0);
		}
	}
	return (ptr);
}
char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*line;

	if (!ptr)
	{
		ptr = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!ptr)
			return (0);
		ptr[0] = 0;
	}
	if (!fd || !BUFFER_SIZE)
	{
		if (ptr)
			free(ptr);
		return (0);
	}
	if (!char_n(ptr))
		ptr = get_first_line(ptr, fd);
	if (!ptr)
		return (0);
	line = get_and_clean(ptr);
	return (line);
}
