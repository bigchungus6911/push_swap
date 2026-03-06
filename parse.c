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

static int	has_dup(int *v, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (v[i] == v[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	load_stack_a(t_stack *d, int *v, int n)
{
	int	i;

	d->stack_a = malloc(sizeof(int) * n);
	d->stack_b = malloc(sizeof(int) * n);
	if (!d->stack_a || !d->stack_b)
		print_error_and_exit(d);
	d->size_a = n;
	d->size_b = 0;
	i = 0;
	while (i < n)
	{
		d->stack_a[n - 1 - i] = v[i];
		i++;
	}
}

static int	count_total(int argc, char **argv, int *total)
{
	int		i;
	int		count;
	char	**p;

	i = 1;
	*total = 0;
	while (i < argc)
	{
		p = split_ws(argv[i], &count);
		if (!p || count == 0)
			return (free_split(p), 0);
		*total += count;
		free_split(p);
		i++;
	}
	return (1);
}

static int	fill_values(int argc, char **argv, int *vals)
{
	int		i;
	int		j;
	int		k;
	int		count;
	char	**p;

	i = 1;
	k = 0;
	while (i < argc)
	{
		p = split_ws(argv[i], &count);
		if (!p)
			return (0);
		j = 0;
		while (j < count)
		{
			if (!atoi_strict(p[j], &vals[k++]))
				return (free_split(p), 0);
			j++;
		}
		free_split(p);
		i++;
	}
	return (1);
}

int	parse_input(t_stack *d, int argc, char **argv)
{
	int	*vals;
	int	n;

	if (!count_total(argc, argv, &n) || n == 0)
		return (0);
	vals = malloc(sizeof(int) * n);
	if (!vals)
		return (0);
	if (!fill_values(argc, argv, vals))
		return (free(vals), 0);
	if (has_dup(vals, n))
		return (free(vals), 0);
	load_stack_a(d, vals, n);
	free(vals);
	return (1);
}