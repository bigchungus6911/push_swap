/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:28 by hadrider          #+#    #+#             */
/*   Updated: 2026/03/02 15:54:01 by hadrider         ###   ########.fr       */
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

int		parse_input(t_stack *stk, int argc, char **argv);

void	print_error_and_exit(t_stack *stk);

void	put_op(char *s);
void	swap_raw(int *arr, int size);
void	rotate_raw(int *arr, int size);
void	rev_rotate_raw(int *arr, int size);
int		is_sorted(t_stack *stk);

int		atoi_strict(char *s, int *out);
char	**split_ws(char *s, int *count);
void	free_split(char **t);
int		sp_is_space(char c);
int		sp_count_words(char *s);
char	*sp_dup_word(char *s, int start, int end);
char	**sp_alloc_split(char *s, int *count);
int		sp_fill_split(char **t, char *s);

void	sa(t_stack *stk);
void	sb(t_stack *stk);
void	ss(t_stack *stk);

void	pa(t_stack *stk);
void	pb(t_stack *stk);

void	ra(t_stack *stk);
void	rb(t_stack *stk);
void	rr(t_stack *stk);

void	rra(t_stack *stk);
void	rrb(t_stack *stk);
void	rrr(t_stack *stk);

void	assign_indexes(t_stack *stk);
void	sort_small(t_stack *stk);
void	chunk_sort(t_stack *stk);

void	bs_rotate_b_to_max(t_stack *stk);
void	bs_pull_back_to_a(t_stack *stk);

#endif
