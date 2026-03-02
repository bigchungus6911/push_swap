/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:02 by hadrider          #+#    #+#             */
/*   Updated: 2026/02/23 14:55:03 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

static char	*skip_spaces(char *s)
{
	while (*s && is_space(*s))
		s++;
	return (s);
}

static void	read_sign(char **s, int *sign)
{
	*sign = 1;
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			*sign = -1;
		(*s)++;
	}
}

static int	read_digits(char **s, int sign, long *n)
{
	*n = 0;
	while (**s >= '0' && **s <= '9')
	{
		*n = *n * 10 + (**s - '0');
		if (sign * (*n) > 2147483647L || sign * (*n) < -2147483648L)
			return (0);
		(*s)++;
	}
	return (1);
}

int	atoi_strict(char *s, int *out)
{
	long	n;
	int		sign;

	s = skip_spaces(s);
	read_sign(&s, &sign);
	if (*s < '0' || *s > '9')
		return (0);
	if (!read_digits(&s, sign, &n))
		return (0);
	s = skip_spaces(s);
	if (*s)
		return (0);
	*out = (int)(sign * n);
	return (1);
}
