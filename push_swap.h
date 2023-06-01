/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:04:14 by asekmani          #+#    #+#             */
/*   Updated: 2023/03/29 11:04:30 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				rank;
	int				pos_in_a;
	int				mvt_a;
	int				mvt_b;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_init(int arc, char **arv);
long long			ft_long_atoi(const char *str);

int					ft_is_digit(char c);
int					error_cases(char **s);
int					ft_is_number(char *s);
int					sumMvt(t_stack *stack);
int					ft_stack_ln(t_stack *stack);
int					get_max_rank(t_stack *stack_a);
int					smallest_index(t_stack **stack);
int					check_if_sorted(t_stack *stack);

void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				set_index(t_stack **stack);
void				show_stack_a(t_stack *stack);
void				show_stack_b(t_stack *stack);
void				put_up_element(t_stack **stack_a);
void				sort_two_three(t_stack **stack_a);
void				set_rank(t_stack *stack_a, int size);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_b, t_stack **stack_a);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				sort(t_stack **stack_a, t_stack **stack_b);
void				push_to_b(t_stack **stack_a, t_stack **stack_b);
void				find_pos_in_a(t_stack **stack_a, t_stack **stack_b);
void				find_less_mvt(t_stack **stack_a, t_stack **stack_b);
void				movement_in_stack(t_stack **stack_a, t_stack **stack_b);
void				put_up(t_stack **stack_a, t_stack **stack_b, int mvt_a,
						int mvt_b);

#endif