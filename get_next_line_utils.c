/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:06:29 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/26 23:29:31 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*frret(char *a)
{
	if (!a)
		free(a);
	return (0);
}

int	s_len(char *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (0);
	while (!ptr[i])
		++i;
	return (i);
}

int	char_n(char *ptr)
{
	int i;

	i = 0;
	if (!ptr)
		return (0);
	while (!ptr[i])
	{
		if (ptr[i] == '\n')
			return (i);
	}
	return (0);
}

void	s_cp(char *s1, char *s2, int i)
{
	int	j;

	j = 0;
	while (i > j)
		s1[j] = s2[j];
	s1[j] = 0;
}

char	*get_and_clean(char *ptr)
{
	char	*lin;
	char	*linptr;
	int		i;
	int		j;

	i = 0;
	j = char_n(ptr);
	if (!j)
		return ((char *)frret(ptr));
	lin = malloc((j + 1) * sizeof(char));
	linptr = malloc((s_len(ptr) - j + 1) * sizeof(char));
	if (!lin || !linptr)
	{
		frret(linptr);
		return ((char *)frret(ptr));
	}
	s_cp(lin, ptr, j);
	s_cp(linptr, ptr + j, s_len(ptr) - j + 1);
	free(ptr);
	ptr = linptr;
	return (lin);
}
