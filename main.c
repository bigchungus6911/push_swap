/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:13 by hadrider          #+#    #+#             */
/*   Updated: 2026/03/02 15:12:48 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	d;

	d.stack_a = NULL;
	d.stack_b = NULL;
	d.size_a = 0;
	d.size_b = 0;
	if (argc < 2)
		return (0);
	if (!parse_input(&d, argc, argv))
		print_error_and_exit(&d);
	if (d.size_a <= 1 || is_sorted(&d))
		return (free(d.stack_a), free(d.stack_b), 0);
	assign_indexes(&d);
	if (d.size_a <= 5)
		sort_small(&d);
	else
		chunk_sort(&d);
	free(d.stack_a);
	free(d.stack_b);
	return (0);
}
