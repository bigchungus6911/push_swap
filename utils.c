/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:52 by hadrider          #+#    #+#             */
/*   Updated: 2026/03/02 15:09:49 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Write an error message string to stderr. */
static void	put_err(char *s)
{
	while (*s)
		write(2, s++, 1);
}

/* Free both stacks, print "Error" to stderr, and exit with status 1. */
void	print_error_and_exit(t_stack *stk)
{
	if (stk->stack_a)
		free(stk->stack_a);
	if (stk->stack_b)
		free(stk->stack_b);
	put_err("Error\n");
	exit(1);
}

/* Return 1 if stack_a is sorted (smallest on top, largest at bottom). */
int	is_sorted(t_stack *stk)
{
	int	i;

	i = stk->size_a - 1;
	while (i > 0)
	{
		if (stk->stack_a[i] > stk->stack_a[i - 1])
			return (0);
		i--;
	}
	return (1);
}
