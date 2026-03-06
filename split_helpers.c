/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:50:00 by hadrider          #+#    #+#             */
/*   Updated: 2026/02/24 08:50:00 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Return 1 if c is a whitespace character, else 0. */
int	sp_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

/* Count the number of whitespace-separated words in s. */
int	sp_count_words(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		while (s[i] && sp_is_space(s[i]))
			i++;
		if (s[i])
			c++;
		while (s[i] && !sp_is_space(s[i]))
			i++;
	}
	return (c);
}

/* Duplicate the substring s[start..end-1] into a new null-terminated string. */
char	*sp_dup_word(char *s, int start, int end)
{
	char	*t;
	int		i;

	t = (char *)malloc((end - start + 1) * sizeof(char));
	if (!t)
		return (NULL);
	i = 0;
	while (start < end)
		t[i++] = s[start++];
	t[i] = '\0';
	return (t);
}

/* Allocate a NULL-terminated array sized for all words in s. */
char	**sp_alloc_split(char *s, int *count)
{
	char	**t;

	*count = sp_count_words(s);
	t = (char **)malloc(sizeof(char *) * (*count + 1));
	return (t);
}

/* Fill the pre-allocated array t with words extracted from s. */
int	sp_fill_split(char **t, char *s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && sp_is_space(s[i]))
			i++;
		if (!s[i])
			break ;
		k = i;
		while (s[i] && !sp_is_space(s[i]))
			i++;
		t[j] = sp_dup_word(s, k, i);
		if (!t[j])
			return (0);
		j++;
	}
	t[j] = NULL;
	return (1);
}
