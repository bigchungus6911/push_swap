/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:21 by hadrider          #+#    #+#             */
/*   Updated: 2026/02/24 07:33:36 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Write the operation name to stdout in a single syscall. */
void	put_op(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

/* Swap the top two elements of the array. */
void	swap_raw(int *arr, int size)
{
	int	t;

	if (size < 2)
		return ;
	t = arr[size - 1];
	arr[size - 1] = arr[size - 2];
	arr[size - 2] = t;
}

/* Move the top element to the bottom (rotate up). */
void	rotate_raw(int *arr, int size)
{
	int	i;
	int	top;

	if (size < 2)
		return ;
	top = arr[size - 1];
	i = size - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = top;
}

/* Move the bottom element to the top (reverse rotate). */
void	rev_rotate_raw(int *arr, int size)
{
	int	i;
	int	bot;

	if (size < 2)
		return ;
	bot = arr[0];
	i = 0;
	while (i + 1 < size)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[size - 1] = bot;
}
