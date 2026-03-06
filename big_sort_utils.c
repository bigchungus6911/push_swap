/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:50:00 by hadrider          #+#    #+#             */
/*   Updated: 2026/02/24 08:50:00 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Return the index of val in arr[0..n-1], or -1 if not found. */
static int	find_pos(int *arr, int n, int val)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

/* Rotate stack B (rb/rrb) until its current maximum element is on top. */
void	bs_rotate_b_to_max(t_stack *stk)
{
	int	max_idx;
	int	pos;
	int	rot_up;
	int	rot_down;

	max_idx = stk->size_b - 1;
	pos = find_pos(stk->stack_b, stk->size_b, max_idx);
	rot_up = stk->size_b - 1 - pos;
	rot_down = pos + 1;
	if (rot_up <= rot_down)
		while (rot_up-- > 0)
			rb(stk);
	else
		while (rot_down-- > 0)
			rrb(stk);
}

/* Repeatedly pull the max of B to the top and push it to A until B is empty. */
void	bs_pull_back_to_a(t_stack *stk)
{
	while (stk->size_b)
	{
		bs_rotate_b_to_max(stk);
		pa(stk);
	}
}
