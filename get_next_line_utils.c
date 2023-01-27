/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:06:29 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/27 20:17:59 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*frret(char *a)
{
	if (!a)
		free(a);
	a = 0;
	return (0);
}

int	s_len(char *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
		++i;
	return (i);
}

int	char_n(char *ptr)
{
	int i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
	{
		if (ptr[i] == '\n')
			return (i);
		++i;
	}
	return (0);
}

void	s_cp(char *s1, char *s2, int i)
{
	int	j;

	j = -1;
	while (i > ++j)
		s1[j] = s2[j];
	s1[j] = 0;
}

char	*get_and_clean(char *ptr, char **lin)
{
	char	*linptr;
	int		i;
	int		j;

	i = s_len(ptr);
	j = char_n(ptr);
	//printf("wwwwwwwwww\n");
	if (!i)
		return ((char *)frret(ptr));
	if (!j)
	{
		//printf("hhhhhhhhhhhhhhptr = %s\nlin =%s\n", ptr, *lin);
		*lin = ptr;
		return (0);
	}
	*lin = malloc((j + 2) * sizeof(char));
	linptr = malloc((i - j + 1) * sizeof(char));
	if (!*lin || !linptr)
	{
		frret(linptr);
		frret(*lin);
		return ((char *)frret(ptr));
	}
	s_cp(*lin, ptr, j + 1);
	s_cp(linptr, (ptr + j + 1), (s_len(ptr) - j + 1));
	//printf("linptr = %s\nlin =%s\n", linptr, *lin);
	frret(ptr);
	ptr = linptr;
	return (ptr);
}
