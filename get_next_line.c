/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:01:43 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/28 19:41:22 by sogabrie         ###   ########.fr       */
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
	while (ptr && ptr[i])
	{
		cp[i] = ptr[i];
		++i;
	}
	while (buffer[f])
		cp[i++] = buffer[f++];
	cp[i] = 0;
	printf("(ptr= %p)",cp);
	return (cp);
}

char	*get_first_line(char *ptr, int fd)
{
	int		j;
	char	*pt2;
	char	buffer[BUFFER_SIZE + 1];

	j = 1;
	while (!char_n(ptr) && j)
	{
		j = read(fd, buffer, BUFFER_SIZE);
		buffer[j] = 0;
		if (j > 0)
		{
			pt2 = s_cat(ptr, buffer, j);
			free(ptr);
			ptr = pt2;
			if (!ptr)
				return (0);
			//printf("ptr = %s\n",ptr);
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

	if (fd < 0 )
	{
		return (0);
	}
	if (!char_n(ptr))
		ptr = get_first_line(ptr, fd);
	if (!ptr)
		return (0);
	//printf("char_n(ptr) = %d\n",char_n(ptr));
	if (!char_n(ptr))
	{
		line = get_and_clean(ptr);
		free(ptr);
		ptr = 0;
	}
	else
	{
		line = malloc((char_n(ptr) + 1) * sizeof(char));
		if (!line)
			return (frret(ptr));
		line = get_and_clean(ptr);
		ptr = get_and_clean_ptr(ptr);
	}
	return (line);
}
