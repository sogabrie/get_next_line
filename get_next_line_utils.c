/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:06:29 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/28 19:16:48 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*frret(char *a)
{
	if (!a)
		free(a);
	//a = 0;
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
	int	j;

	i = 1;
	j = 0;
	if (!ptr)
		return (0);
	while (ptr[j])
	{
		//printf("ptr = %d\nn",ptr[j]);
		if (ptr[j] == '\n')
			return (i);
		++i;
		++j;
	}
	return (0);
}

char	*s_cp(char *s1, char *s2, int i)
{
	int	j;

	j = -1;
	while (i > ++j && s2[j] != 0)
		s1[j] = s2[j];
	s1[j] = 0;
	return (s1);
}

char	*get_and_clean(char *ptr)
{
	char	*lin;
	int		i;
	int		j;

	i = s_len(ptr);
	j = char_n(ptr);
	if (!i)
		return ((char *)frret(ptr));
	lin = malloc((j + 1) * sizeof(char));
	if (!lin)
	{
		if (!ptr)
			free(ptr);
		return (0);
	}
	if (!j)
	{
		lin = s_cp(lin, ptr, i + 1);
		if (!ptr)
			free(ptr);
		return (lin);
	}
	lin = s_cp(lin, ptr, j);
	return (lin);
}

char	*get_and_clean_ptr(char *ptr)
{
	int	i;
	char	*ptr2;

	i = char_n(ptr);
	ptr2 = malloc((s_len(ptr) - i + 1) * sizeof(char));
	if (!ptr2)
		return (frret(ptr));
	ptr2 = s_cp(ptr2,(ptr + i), (s_len(ptr) - i));
	if (!ptr)
		free(ptr);
	return (ptr2);
}
