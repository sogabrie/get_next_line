/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:01:43 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/27 20:25:21 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*s_cat(char *ptr, char *buffer, int j)
{
	char	*cp;
	int		i;
	int		f;

	i = -1;
	f = 0;
	cp = malloc((s_len(ptr) + j + 1) * sizeof(char));
	if (!cp)
		return (0);
	while (ptr[++i])
		cp[i] = ptr[i];
	//printf("i = %d\nj = %d\n", i, j);
	while (f < j)
		cp[i++] = buffer[f++];
	cp[i] = 0;
	//printf("cp =%s\n",cp);
	free(ptr);
	ptr = 0;
	return (cp);
}

char	*get_first_line(char *ptr, int fd)
{
	int		j;
	char	buffer[BUFFER_SIZE];

	j = 1;
	while (!char_n(ptr) && j)
	{
		//printf("ffffffff\n");
		j = read(fd, buffer, BUFFER_SIZE);
		//printf("j = %d\n", j);
		if (j > 0)
		{
			ptr = s_cat(ptr, buffer, j);
			if (!ptr)
				return (0);
		}
		else if (j < 0)
		{
			free(ptr);
			ptr = 0;
			return (0);
		}
	}
	return (ptr);
}
char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*line;

	if (!ptr && read(fd, 0, 0) >= 0)
	{
		ptr = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!ptr)
			return (0);
		ptr[0] = 0;
	}
	//printf("read = %zd\n",read(fd, 0 ,0));
	if (fd < 1 || !BUFFER_SIZE || (0 > read(fd, 0, 0)))
	{
		//printf("fre ptr\n");
		//printf("ptr =%s\n", ptr);
		frret(ptr);
		return (0);
	}
	//printf("ptr = %s\nptr_n = %d\nsize = %d\n", ptr, char_n(ptr), s_len(ptr));
	//printf("ptr = %s\n", ptr);
	if (!char_n(ptr))
		ptr = get_first_line(ptr, fd);
	//printf("ptr =%s\n", ptr);
	if (!ptr || !ptr[0])
		return (frret(ptr));
	if (char_n(ptr))
		ptr = get_and_clean(ptr, &line);
	else
	{
		line = ptr;
		ptr = 0;
	}
	//printf("ptr = %s\nline =%s\n",ptr, line);
	return (line);
}
