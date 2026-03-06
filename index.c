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

/* Sort arr[0..n-1] in ascending order using selection sort. */
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

/* Return the position (rank) of val in the sorted array arr[0..n-1]. */
static int	find_rank(int *arr, int n, int val)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == val)
			return (i);
		i++;
	}
	return (0);
}

/* Replace each value in stack_a with its sorted rank (0 = smallest). */
void	assign_indexes(t_stack *stk)
{
	int	*tmp;
	int	i;

	tmp = (int *)malloc(sizeof(int) * stk->size_a);
	if (!tmp)
		print_error_and_exit(stk);
	i = 0;
	while (i < stk->size_a)
	{
		tmp[i] = stk->stack_a[i];
		i++;
	}
	selection_sort(tmp, stk->size_a);
	i = 0;
	while (i < stk->size_a)
	{
		stk->stack_a[i] = find_rank(tmp, stk->size_a, stk->stack_a[i]);
		i++;
	}
	free(tmp);
}