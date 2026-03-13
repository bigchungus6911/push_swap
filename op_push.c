/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:20:00 by hadrider          #+#    #+#             */
/*   Updated: 2026/03/07 08:19:42 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *d)
{
	int	val;

	if (d->size_a == 0)
		return ;
	val = d->stack_a[d->size_a - 1];
	d->size_a--;
	d->stack_b[d->size_b] = val;
	d->size_b++;
	put_op("pb\n");
}

void	pa(t_stack *d)
{
	int	val;

	if (d->size_b == 0)
		return ;
	val = d->stack_b[d->size_b - 1];
	d->size_b--;
	d->stack_a[d->size_a] = val;
	d->size_a++;
	put_op("pa\n");
}
