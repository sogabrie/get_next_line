/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:06:29 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/26 22:22:08 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	frret(char *a)
{
	if (!a)
		free(a);
	return (0)
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

char	*get_and_clean(char *ptr)
{
	char	*lin;
	int		i;
	int		j;

	i = 0;
	j = char_n(ptr) + 1;
	if (j == 1)
		return (frret(ptr));
	line = malloc(j * sizeof(char));
	if (!line)
		return (frret(ptr));

