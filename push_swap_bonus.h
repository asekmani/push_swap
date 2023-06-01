/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:36:54 by asekmani          #+#    #+#             */
/*   Updated: 2023/04/26 15:19:08 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <limits.h>
# include <stddef.h>
# include <stdint.h>
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

size_t				ft_strlen(char *s);

int					ft_is_digit(char c);
int					ft_is_number(char *s);
int					error_cases(char **s);
int					ft_stack_ln(t_stack *stack);
int					check_if_sorted(t_stack *stack, t_stack *stackb);

char				*get_next_line(int fd, int val);
char				*ft_strjoin(char *s1, char *s2);

void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				free_stack(t_stack **stack);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_b, t_stack **stack_a);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

void				ft_check(t_stack **stack_a, t_stack **stack_b, char *line);

#endif
