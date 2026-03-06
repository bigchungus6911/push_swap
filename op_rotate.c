/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:20:00 by hadrider          #+#    #+#             */
/*   Updated: 2026/02/28 14:16:33 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotate stack A: top element goes to the bottom; print "ra". */
void	ra(t_stack *stk)
{
	rotate_raw(stk->stack_a, stk->size_a);
	put_op("ra\n");
}

/* Rotate stack B: top element goes to the bottom; print "rb". */
void	rb(t_stack *stk)
{
	rotate_raw(stk->stack_b, stk->size_b);
	put_op("rb\n");
}

/* Rotate both stacks simultaneously and print "rr". */
void	rr(t_stack *stk)
{
	rotate_raw(stk->stack_a, stk->size_a);
	rotate_raw(stk->stack_b, stk->size_b);
	put_op("rr\n");
}
