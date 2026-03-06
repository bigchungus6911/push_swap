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

/* Count the number of whitespace-delimited words in s. */
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

/* Duplicate the substring s[start..end) into a newly allocated string. */
char	*sp_dup_word(char *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

/* Allocate a NULL-terminated array sized for the words in s. */
char	**sp_alloc_split(char *s, int *count)
{
	char	**words;

	*count = sp_count_words(s);
	words = (char **)malloc(sizeof(char *) * (*count + 1));
	return (words);
}

/* Fill words[] with duplicated word strings from s; return 0 on error. */
int	sp_fill_split(char **words, char *s)
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
		words[j] = sp_dup_word(s, k, i);
		if (!words[j])
			return (0);
		j++;
	}
	words[j] = NULL;
	return (1);
}
