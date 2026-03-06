/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:20:00 by hadrider          #+#    #+#             */
/*   Updated: 2026/02/24 08:20:00 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the top two elements of stack_a and print "sa". */
void	sa(t_stack *stk)
{
	swap_raw(stk->stack_a, stk->size_a);
	put_op("sa\n");
}

/* Swap the top two elements of stack_b and print "sb". */
void	sb(t_stack *stk)
{
	swap_raw(stk->stack_b, stk->size_b);
	put_op("sb\n");
}

/* Swap the top two elements of both stacks and print "ss". */
void	ss(t_stack *stk)
{
	swap_raw(stk->stack_a, stk->size_a);
	swap_raw(stk->stack_b, stk->size_b);
	put_op("ss\n");
}
