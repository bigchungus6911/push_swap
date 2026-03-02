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

void	rra(t_stack *d)
{
	rev_rotate_raw(d->stack_a, d->size_a);
	put_op("rra\n");
}

void	rrb(t_stack *d)
{
	rev_rotate_raw(d->stack_b, d->size_b);
	put_op("rrb\n");
}

void	rrr(t_stack *d)
{
	rev_rotate_raw(d->stack_a, d->size_a);
	rev_rotate_raw(d->stack_b, d->size_b);
	put_op("rrr\n");
}
