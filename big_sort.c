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

/*
** Chunk sort strategy (for > 5 elements):
** 1. Push all numbers from A to B in ascending chunks so that larger numbers
**    go deeper in B (each new chunk goes below the previous via rb).
** 2. Pull everything back to A by always rotating B so its maximum is on top,
**    then pushing to A. This yields a sorted A in O(n) passes.
*/

/* Choose chunk size: bigger chunks mean fewer rotations for large inputs. */
static int	choose_chunk(int n)
{
	if (n <= 100)
		return (20);
	return (35);
}

/* Push all of A to B in ascending chunks; larger elements sink to B's bottom. */
static void	push_chunks_to_b(t_stack *stk, int chunk)
{
	int	i;
	int	top;

	i = 0;
	while (stk->size_a)
	{
		top = stk->stack_a[stk->size_a - 1];
		if (top <= i)
		{
			pb(stk);
			rb(stk);
			i++;
		}
		else if (top <= i + chunk)
		{
			pb(stk);
			i++;
		}
		else
			ra(stk);
	}
}

/* Sort stack A using chunk sort: push to B in ranges, pull back by max. */
void	chunk_sort(t_stack *stk)
{
	int	chunk;

	chunk = choose_chunk(stk->size_a);
	push_chunks_to_b(stk, chunk);
	bs_pull_back_to_a(stk);
}
