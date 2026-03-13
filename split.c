/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:49 by hadrider          #+#    #+#             */
/*   Updated: 2026/03/09 15:57:36 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **t)
{
	int	i;

	if (!t)
		return ;
	i = 0;
	while (t[i])
		free(t[i++]);
	free(t);
}

char	**split_ws(char *s, int *count)
{
	char	**t;

	t = sp_alloc_split(s, count);
	if (!t)
		return (NULL);
	if (!sp_fill_split(t, s))
	{
		free_split(t);
		return (NULL);
	}
	return (t);
}
