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

static void	put_err(char *s)
{
	while (*s)
		write(2, s++, 1);
}

void	print_error_and_exit(t_stack *d)
{
	if (d->stack_a)
		free(d->stack_a);
	if (d->stack_b)
		free(d->stack_b);
	put_err("Error\n");
	exit(1);
}

int	is_sorted(t_stack *d)
{
	int	i;

	i = d->size_a - 1;
	while (i > 0)
	{
		if (d->stack_a[i] > d->stack_a[i - 1])
			return (0);
		i--;
	}
	return (1);
}
