/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:25 by hadrider          #+#    #+#             */
/*   Updated: 2026/03/02 08:21:33 by hadrider         ###   ########.fr       */
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

static int	parse_one(char *arg, int **vals, int *n)
{
	char	**p;
	int		i;

	p = split_ws(arg, n);
	if (!p || *n == 0)
		return (free_split(p), 0);
	*vals = (int *)malloc(sizeof(int) * (*n));
	if (!*vals)
		return (free_split(p), 0);
	i = 0;
	while (i < *n)
	{
		if (!atoi_strict(p[i], &(*vals)[i]))
			return (free(*vals), free_split(p), 0);
		i++;
	}
	free_split(p);
	return (1);
}

static int	parse_many(int argc, char **argv, int **vals, int *n)
{
	int	i;

	*n = argc - 1;
	*vals = (int *)malloc(sizeof(int) * (*n));
	if (!*vals)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!atoi_strict(argv[i], &(*vals)[i - 1]))
			return (free(*vals), 0);
		i++;
	}
	return (1);
}

int	parse_input(t_stack *d, int argc, char **argv)
{
	int	*vals;
	int	n;

	vals = NULL;
	n = 0;
	if (argc == 2)
	{
		if (!parse_one(argv[1], &vals, &n))
			return (0);
	}
	else if (!parse_many(argc, argv, &vals, &n))
		return (0);
	if (has_dup(vals, n))
		return (free(vals), 0);
	load_stack_a(d, vals, n);
	free(vals);
	return (1);
}
