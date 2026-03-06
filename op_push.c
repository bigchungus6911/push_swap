/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:20:00 by hadrider          #+#    #+#             */
/*   Updated: 2026/02/28 14:16:24 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push the top of stack A onto stack B and print "pb". */
void	pb(t_stack *stk)
{
	if (stk->size_a == 0)
		return ;
	stk->stack_b[stk->size_b++] = stk->stack_a[--stk->size_a];
	put_op("pb\n");
}

/* Push the top of stack B onto stack A and print "pa". */
void	pa(t_stack *stk)
{
	if (stk->size_b == 0)
		return ;
	stk->stack_a[stk->size_a++] = stk->stack_b[--stk->size_b];
	put_op("pa\n");
}
