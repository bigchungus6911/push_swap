/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:49 by hadrider          #+#    #+#             */
/*   Updated: 2026/02/24 08:50:00 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Free each string in words[] and then the array itself. */
void	free_split(char **words)
{
	int	i;

	if (!words)
		return ;
	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}

/* Split s on whitespace, set *count, and return the array; NULL on error. */
char	**split_ws(char *s, int *count)
{
	char	**words;

	words = sp_alloc_split(s, count);
	if (!words)
		return (NULL);
	if (!sp_fill_split(words, s))
	{
		free_split(words);
		return (NULL);
	}
	return (words);
}
