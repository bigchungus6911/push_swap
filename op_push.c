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

void	pb(t_stack *d)
{
	if (d->size_a == 0)
		return ;
	d->stack_b[d->size_b++] = d->stack_a[--d->size_a];
	put_op("pb\n");
}

void	pa(t_stack *d)
{
	if (d->size_b == 0)
		return ;
	d->stack_a[d->size_a++] = d->stack_b[--d->size_b];
	put_op("pa\n");
}
