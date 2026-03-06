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
** Chunk sort strategy:
** 1. Push all numbers from A to B in small value ranges (chunks).
**    Numbers whose rank falls in the lower half of the current chunk
**    are immediately rotated in B so larger values end up on top.
** 2. Pull everything back from B to A, always taking the current max.
**    Because we pull in descending order and the stack is top-to-bottom,
**    A ends up fully sorted (smallest on top, largest at bottom).
*/

/* Return the chunk width: 20 for up to 100 elements, 35 for more. */
static int	choose_chunk(int n)
{
	if (n <= 100)
		return (20);
	return (35);
}

/* Push every element of A to B in ascending chunks of size chunk. */
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

/* Sort stk using chunk sort: push A to B in ranges, pull back by max. */
void	chunk_sort(t_stack *stk)
{
	int	chunk;

	chunk = choose_chunk(stk->size_a);
	push_chunks_to_b(stk, chunk);
	bs_pull_back_to_a(stk);
}
