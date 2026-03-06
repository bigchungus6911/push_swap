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

/* Write operation name to stdout in a single write call. */
void	put_op(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

/* Swap the top two elements of an array-based stack. */
void	swap_raw(int *arr, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = arr[size - 1];
	arr[size - 1] = arr[size - 2];
	arr[size - 2] = tmp;
}

/* Rotate array left: top element goes to the bottom. */
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

/* Reverse-rotate array: bottom element goes to the top. */
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
