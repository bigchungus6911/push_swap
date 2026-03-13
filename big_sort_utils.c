/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:50:00 by hadrider          #+#    #+#             */
/*   Updated: 2026/03/10 09:42:36 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos(int *s, int n, int val)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (s[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

static void	rotate_to_pos(t_stack *d, int steps_forward, int steps_backward)
{
	int	count;

	if (steps_forward <= steps_backward)
	{
		count = steps_forward;
		while (count > 0)
		{
			rb(d);
			count--;
		}
	}
	else
	{
		count = steps_backward;
		while (count > 0)
		{
			rrb(d);
			count--;
		}
	}
}

void	bs_rotate_b_to_max(t_stack *d)
{
	int	max_rank;
	int	max_pos;
	int	steps_forward;
	int	steps_backward;

	max_rank = d->size_b - 1;
	max_pos = find_pos(d->stack_b, d->size_b, max_rank);
	steps_forward = d->size_b - 1 - max_pos;
	steps_backward = max_pos + 1;
	rotate_to_pos(d, steps_forward, steps_backward);
}

void	bs_pull_back_to_a(t_stack *d)
{
	while (d->size_b)
	{
		bs_rotate_b_to_max(d);
		pa(d);
	}
}
