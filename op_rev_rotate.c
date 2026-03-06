/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:20:00 by hadrider          #+#    #+#             */
/*   Updated: 2026/02/28 14:16:29 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Reverse-rotate stack A: bottom element goes to the top; print "rra". */
void	rra(t_stack *stk)
{
	rev_rotate_raw(stk->stack_a, stk->size_a);
	put_op("rra\n");
}

/* Reverse-rotate stack B: bottom element goes to the top; print "rrb". */
void	rrb(t_stack *stk)
{
	rev_rotate_raw(stk->stack_b, stk->size_b);
	put_op("rrb\n");
}

/* Reverse-rotate both stacks simultaneously and print "rrr". */
void	rrr(t_stack *stk)
{
	rev_rotate_raw(stk->stack_a, stk->size_a);
	rev_rotate_raw(stk->stack_b, stk->size_b);
	put_op("rrr\n");
}
