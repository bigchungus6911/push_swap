/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:28 by hadrider          #+#    #+#             */
/*   Updated: 2026/02/28 14:16:58 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}	t_stack;

int		parse_input(t_stack *d, int argc, char **argv);

void	print_error_and_exit(t_stack *d);

void	put_op(char *s);
void	swap_raw(int *s, int n);
void	rotate_raw(int *s, int n);
void	rev_rotate_raw(int *s, int n);
int		is_sorted(t_stack *d);

int		atoi_strict(char *s, int *out);
char	**split_ws(char *s, int *count);
void	free_split(char **t);
int		sp_is_space(char c);
int		sp_count_words(char *s);
char	*sp_dup_word(char *s, int start, int end);
char	**sp_alloc_split(char *s, int *count);
int		sp_fill_split(char **t, char *s);

void	sa(t_stack *d);
void	sb(t_stack *d);
void	ss(t_stack *d);

void	pa(t_stack *d);
void	pb(t_stack *d);

void	ra(t_stack *d);
void	rb(t_stack *d);
void	rr(t_stack *d);

void	rra(t_stack *d);
void	rrb(t_stack *d);
void	rrr(t_stack *d);

void	assign_indexes(t_stack *d);
void	sort_small(t_stack *d);
void	chunk_sort(t_stack *d);

void	bs_rotate_b_to_max(t_stack *d);
void	bs_pull_back_to_a(t_stack *d);

#endif
