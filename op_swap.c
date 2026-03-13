/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:20:00 by hadrider          #+#    #+#             */
/*   Updated: 2026/03/07 09:58:00 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *d)
{
	swap_raw(d->stack_a, d->size_a);
	put_op("sa\n");
}

void	sb(t_stack *d)
{
	swap_raw(d->stack_b, d->size_b);
	put_op("sb\n");
}

void	ss(t_stack *d)
{
	swap_raw(d->stack_a, d->size_a);
	swap_raw(d->stack_b, d->size_b);
	put_op("ss\n");
}
