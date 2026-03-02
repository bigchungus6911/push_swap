/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:11 by hadrider          #+#    #+#             */
/*   Updated: 2026/02/23 14:55:12 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static void	quick_sort(int *arr, int l, int r)
{
	int	i;
	int	j;
	int	p;

	i = l;
	j = r;
	p = arr[(l + r) / 2];
	while (i <= j)
	{
		while (arr[i] < p)
			i++;
		while (arr[j] > p)
			j--;
		if (i <= j)
		{
			swap_int(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	if (l < j)
		quick_sort(arr, l, j);
	if (i < r)
		quick_sort(arr, i, r);
}

static int	bin_find(int *arr, int n, int x)
{
	int	l;
	int	r;
	int	m;

	l = 0;
	r = n - 1;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (arr[m] == x)
			return (m);
		if (arr[m] < x)
			l = m + 1;
		else
			r = m - 1;
	}
	return (0);
}

void	assign_indexes(t_stack *d)
{
	int	*tmp;
	int	i;

	tmp = (int *)malloc(sizeof(int) * d->size_a);
	if (!tmp)
		print_error_and_exit(d);
	i = 0;
	while (i < d->size_a)
	{
		tmp[i] = d->stack_a[i];
		i++;
	}
	quick_sort(tmp, 0, d->size_a - 1);
	i = 0;
	while (i < d->size_a)
	{
		d->stack_a[i] = bin_find(tmp, d->size_a, d->stack_a[i]);
		i++;
	}
	free(tmp);
}
