/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:41 by hadrider          #+#    #+#             */
/*   Updated: 2026/03/07 09:56:00 by hadrider         ###   ########.fr       */
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

static int	find_min_pos(t_stack *d)
{
	int	i;
	int	pos;

	pos = 0;
	i = 1;
	while (i < d->size_a)
	{
		if (d->stack_a[i] < d->stack_a[pos])
			pos = i;
		i++;
	}
	return (pos);
}

static void	bring_to_top(t_stack *d, int pos)
{
	int	forward;
	int	backward;
	int	count;

	forward = d->size_a - 1 - pos;
	backward = pos + 1;
	if (forward <= backward)
	{
		count = forward;
		while (count > 0)
		{
			ra(d);
			count--;
		}
	}
	else
	{
		count = backward;
		while (count > 0)
		{
			rra(d);
			count--;
		}
	}
}

void	sort_small(t_stack *d)
{
	int	pos;

	if (d->size_a == 2)
	{
		if (d->stack_a[1] > d->stack_a[0])
			sa(d);
		return ;
	}
	while (d->size_a > 3)
	{
		pos = find_min_pos(d);
		bring_to_top(d, pos);
		pb(d);
	}
	sort_3(d);
	while (d->size_b > 0)
		pa(d);
}
