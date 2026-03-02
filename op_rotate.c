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

void	ra(t_stack *d)
{
	rotate_raw(d->stack_a, d->size_a);
	put_op("ra\n");
}

void	rb(t_stack *d)
{
	rotate_raw(d->stack_b, d->size_b);
	put_op("rb\n");
}

void	rr(t_stack *d)
{
	rotate_raw(d->stack_a, d->size_a);
	rotate_raw(d->stack_b, d->size_b);
	put_op("rr\n");
}
