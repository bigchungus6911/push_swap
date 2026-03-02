/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:05 by hadrider          #+#    #+#             */
/*   Updated: 2026/03/02 13:38:01 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_chunk(int n)
{
	if (n <= 100)
		return (20);
	return (35);
}

static void	push_chunks_to_b(t_stack *d, int chunk)
{
	int	i;
	int	top;

	i = 0;
	while (d->size_a)
	{
		top = d->stack_a[d->size_a - 1];
		if (top <= i)
		{
			pb(d);
			rb(d);
			i++;
		}
		else if (top <= i + chunk)
		{
			pb(d);
			i++;
		}
		else
			ra(d);
	}
}

void	chunk_sort(t_stack *d)
{
	int	chunk;

	chunk = choose_chunk(d->size_a);
	push_chunks_to_b(d, chunk);
	bs_pull_back_to_a(d);
}
