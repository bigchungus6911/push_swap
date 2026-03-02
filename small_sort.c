/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:41 by hadrider          #+#    #+#             */
/*   Updated: 2026/02/23 14:55:46 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack *d)
{
	int	top;
	int	mid;
	int	bot;

	top = d->stack_a[d->size_a - 1];
	mid = d->stack_a[d->size_a - 2];
	bot = d->stack_a[d->size_a - 3];
	if (top < mid && mid < bot)
		return ;
	if (top > mid && mid < bot && top < bot)
		sa(d);
	else if (top > mid && mid > bot)
	{
		sa(d);
		rra(d);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(d);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(d);
		ra(d);
	}
	else
		rra(d);
}

static int	min_pos(t_stack *d)
{
	int	i;
	int	pos;
	int	min;

	min = d->stack_a[0];
	pos = 0;
	i = 1;
	while (i < d->size_a)
	{
		if (d->stack_a[i] < min)
		{
			min = d->stack_a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	bring_a_pos_to_top(t_stack *d, int pos)
{
	int	rot_up;
	int	rot_down;

	rot_up = d->size_a - 1 - pos;
	rot_down = pos + 1;
	if (rot_up <= rot_down)
		while (rot_up-- > 0)
			ra(d);
	else
		while (rot_down-- > 0)
			rra(d);
}

static void	push_min_to_b(t_stack *d)
{
	int	pos;

	pos = min_pos(d);
	bring_a_pos_to_top(d, pos);
	pb(d);
}

void	sort_small(t_stack *d)
{
	if (d->size_a == 2)
	{
		if (d->stack_a[d->size_a - 1] > d->stack_a[d->size_a - 2])
			sa(d);
	}
	else if (d->size_a == 3)
		sort_3(d);
	else
	{
		while (d->size_a > 3)
			push_min_to_b(d);
		sort_3(d);
		while (d->size_b)
			pa(d);
	}
}
