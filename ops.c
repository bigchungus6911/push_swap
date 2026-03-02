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

void	put_op(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	swap_raw(int *s, int n)
{
	int	t;

	if (n < 2)
		return ;
	t = s[n - 1];
	s[n - 1] = s[n - 2];
	s[n - 2] = t;
}

void	rotate_raw(int *s, int n)
{
	int	i;
	int	top;

	if (n < 2)
		return ;
	top = s[n - 1];
	i = n - 1;
	while (i > 0)
	{
		s[i] = s[i - 1];
		i--;
	}
	s[0] = top;
}

void	rev_rotate_raw(int *s, int n)
{
	int	i;
	int	bot;

	if (n < 2)
		return ;
	bot = s[0];
	i = 0;
	while (i + 1 < n)
	{
		s[i] = s[i + 1];
		i++;
	}
	s[n - 1] = bot;
}
