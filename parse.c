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

/* Return 1 if any two values in nums[0..total-1] are equal, else 0. */
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

/* Allocate both stacks and load nums[0..total-1] into stack_a (top = nums[0]). */
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

/* Count the total number of integer tokens across all argv strings. */
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

/* Parse each argv string into integer tokens and store them in vals[]. */
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

/* Parse all arguments: count tokens, validate, check duplicates, load stack. */
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