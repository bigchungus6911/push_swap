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

/* Return 1 if c is an ASCII whitespace character, else 0. */
static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

/* Advance s past any leading whitespace characters. */
static char	*skip_spaces(char *s)
{
	while (*s && is_space(*s))
		s++;
	return (s);
}

/* Read an optional '+' or '-' sign and set *sign to 1 or -1. */
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

/* Read decimal digits into *n, checking for int overflow. */
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

/* Convert s to int, rejecting non-integers and out-of-range values.
** Stores result in *out and returns 1 on success, 0 on failure. */
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
