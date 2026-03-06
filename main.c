/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:13 by hadrider          #+#    #+#             */
/*   Updated: 2026/03/02 15:12:48 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push_swap: Sort a stack of integers using a limited set of operations.
**
** FLOW:
** 1. Parse input arguments into stack_a
** 2. Replace values with their sorted rank (0, 1, 2, ...)
** 3. If <= 5 numbers: use simple sort (sort_3 + push min to B)
** 4. If > 5 numbers: use chunk sort (push to B in ranges, pull back by max)
*/

/* Entry point: initialise stk, parse input, pick sort strategy, clean up. */
int	main(int argc, char **argv)
{
	t_stack	stk;

	stk.stack_a = NULL;
	stk.stack_b = NULL;
	stk.size_a = 0;
	stk.size_b = 0;
	if (argc < 2)
		return (0);
	if (!parse_input(&stk, argc, argv))
		print_error_and_exit(&stk);
	if (stk.size_a <= 1 || is_sorted(&stk))
		return (free(stk.stack_a), free(stk.stack_b), 0);
	assign_indexes(&stk);
	if (stk.size_a <= 5)
		sort_small(&stk);
	else
		chunk_sort(&stk);
	free(stk.stack_a);
	free(stk.stack_b);
	return (0);
}
