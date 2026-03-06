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
** - 2 elements: swap if out of order.
** - 3 elements: find the max, rotate it to the bottom, then fix top 2.
** - 4-5 elements: push minimums to B until 3 remain, sort_3, pull back.
*/

/*
** Sort exactly 3 elements (stk->size_a == 3).
** Step 1 - find where the maximum is and rotate it to the bottom:
**   max at top (index 2) -> ra moves it to index 0 (bottom)
**   max at mid (index 1) -> rra moves it to index 0 (bottom)
**   max at bot (index 0) -> already in place, no rotation needed
** Step 2 - if the top two are in wrong order, swap them with sa.
*/
static void	sort_3(t_stack *stk)
{
	int	max_pos;

	max_pos = 0;
	if (stk->stack_a[1] > stk->stack_a[max_pos])
		max_pos = 1;
	if (stk->stack_a[2] > stk->stack_a[max_pos])
		max_pos = 2;
	if (max_pos == 2)
		ra(stk);
	else if (max_pos == 1)
		rra(stk);
	if (stk->stack_a[2] > stk->stack_a[1])
		sa(stk);
}

/* Return the index of the minimum element in stack_a. */
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

/* Rotate stack_a so the element at pos ends up on top. */
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

/* Find the minimum in stack_a, bring it to the top, and push it to B. */
static void	push_min_to_b(t_stack *stk)
{
	int	pos;

	pos = min_pos(stk);
	bring_a_pos_to_top(stk, pos);
	pb(stk);
}

/* Sort 2-5 elements: push mins to B, sort remaining 3, pull back. */
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
