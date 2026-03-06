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

/*
** Small sort strategy:
** - 2 elements: one swap if needed.
** - 3 elements: find where the max is, rotate it to the bottom, then fix top 2.
** - 4-5 elements: push the minimum(s) to B, sort the remaining 3, pull back.
*/

/* Sort the top 3 elements of stack A (smallest on top).
** Move the max to the bottom with ra/rra, then fix the top 2 with sa if needed. */
static void	sort_3(t_stack *stk)
{
	int	top;
	int	mid;
	int	bot;

	top = stk->stack_a[stk->size_a - 1];
	mid = stk->stack_a[stk->size_a - 2];
	bot = stk->stack_a[stk->size_a - 3];
	if (top > mid && top > bot)
		ra(stk);
	else if (mid > top && mid > bot)
		rra(stk);
	if (stk->stack_a[stk->size_a - 1] > stk->stack_a[stk->size_a - 2])
		sa(stk);
}

/* Return the index (array position) of the minimum element in stack A. */
static int	min_pos(t_stack *stk)
{
	int	i;
	int	pos;
	int	min;

	min = stk->stack_a[0];
	pos = 0;
	i = 1;
	while (i < stk->size_a)
	{
		if (stk->stack_a[i] < min)
		{
			min = stk->stack_a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

/* Rotate stack A so that the element at position pos becomes the top. */
static void	bring_a_pos_to_top(t_stack *stk, int pos)
{
	int	rot_up;
	int	rot_down;

	rot_up = stk->size_a - 1 - pos;
	rot_down = pos + 1;
	if (rot_up <= rot_down)
		while (rot_up-- > 0)
			ra(stk);
	else
		while (rot_down-- > 0)
			rra(stk);
}

/* Find the minimum in stack A, bring it to the top, and push it to B. */
static void	push_min_to_b(t_stack *stk)
{
	int	pos;

	pos = min_pos(stk);
	bring_a_pos_to_top(stk, pos);
	pb(stk);
}

/* Sort 2-5 elements in stack A using sort_3 + push-min-to-B strategy. */
void	sort_small(t_stack *stk)
{
	if (stk->size_a == 2)
	{
		if (stk->stack_a[stk->size_a - 1] > stk->stack_a[stk->size_a - 2])
			sa(stk);
	}
	else if (stk->size_a == 3)
		sort_3(stk);
	else
	{
		while (stk->size_a > 3)
			push_min_to_b(stk);
		sort_3(stk);
		while (stk->size_b)
			pa(stk);
	}
}
