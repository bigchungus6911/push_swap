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

void	bs_rotate_b_to_max(t_stack *d)
{
	int	maxv;
	int	pos;
	int	rot_up;
	int	rot_down;

	maxv = d->size_b - 1;
	pos = find_pos(d->stack_b, d->size_b, maxv);
	rot_up = d->size_b - 1 - pos;
	rot_down = pos + 1;
	if (rot_up <= rot_down)
		while (rot_up-- > 0)
			rb(d);
	else
		while (rot_down-- > 0)
			rrb(d);
}

void	bs_pull_back_to_a(t_stack *d)
{
	while (d->size_b)
	{
		bs_rotate_b_to_max(d);
		pa(d);
	}
}
