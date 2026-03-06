/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:25 by hadrider          #+#    #+#             */
/*   Updated: 2026/03/03 09:32:48 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if nums contains any duplicate values. */
static int	has_dup(int *nums, int total)
{
	int	i;
	int	j;

	i = 0;
	while (i < total)
	{
		j = i + 1;
		while (j < total)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* Allocate stacks and load nums into stack_a (first arg goes to top). */
static void	load_stack_a(t_stack *stk, int *nums, int total)
{
	int	i;

	stk->stack_a = malloc(sizeof(int) * total);
	stk->stack_b = malloc(sizeof(int) * total);
	if (!stk->stack_a || !stk->stack_b)
		print_error_and_exit(stk);
	stk->size_a = total;
	stk->size_b = 0;
	i = 0;
	while (i < total)
	{
		stk->stack_a[total - 1 - i] = nums[i];
		i++;
	}
}

/* Count total whitespace-separated tokens across all argv strings. */
static int	count_total(int argc, char **argv, int *total)
{
	int		i;
	int		count;
	char	**words;

	i = 1;
	*total = 0;
	while (i < argc)
	{
		words = split_ws(argv[i], &count);
		if (!words || count == 0)
			return (free_split(words), 0);
		*total += count;
		free_split(words);
		i++;
	}
	return (1);
}

/* Parse all argv tokens into vals, validating each with atoi_strict. */
static int	fill_values(int argc, char **argv, int *vals)
{
	int		i;
	int		j;
	int		k;
	int		count;
	char	**words;

	i = 1;
	k = 0;
	while (i < argc)
	{
		words = split_ws(argv[i], &count);
		if (!words)
			return (0);
		j = 0;
		while (j < count)
		{
			if (!atoi_strict(words[j], &vals[k++]))
				return (free_split(words), 0);
			j++;
		}
		free_split(words);
		i++;
	}
	return (1);
}

/* Parse argv into stk, returning 0 on invalid input or duplicates. */
int	parse_input(t_stack *stk, int argc, char **argv)
{
	int	*vals;
	int	total;

	if (!count_total(argc, argv, &total) || total == 0)
		return (0);
	vals = malloc(sizeof(int) * total);
	if (!vals)
		return (0);
	if (!fill_values(argc, argv, vals))
		return (free(vals), 0);
	if (has_dup(vals, total))
		return (free(vals), 0);
	load_stack_a(stk, vals, total);
	free(vals);
	return (1);
}