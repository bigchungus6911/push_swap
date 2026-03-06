/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:45:25 by hadrider          #+#    #+#             */
/*   Updated: 2026/03/04 14:45:26 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	selection_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	min;
	int	tmp;

	i = 0;
	while (i < n)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min])
				min = j;
			j++;
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
		i++;
	}
}

static int	find_rank(int *arr, int n, int x)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == x)
			return (i);
		i++;
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
	selection_sort(tmp, d->size_a);
	i = 0;
	while (i < d->size_a)
	{
		d->stack_a[i] = find_rank(tmp, d->size_a, d->stack_a[i]);
		i++;
	}
	free(tmp);
}