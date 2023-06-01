/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:24:30 by asekmani          #+#    #+#             */
/*   Updated: 2023/04/21 12:27:58 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_index(t_stack **stack)
{
	t_stack	*tmp;
	int		s_index;
	int		s_rank;

	tmp = *stack;
	s_rank = INT_MAX;
	set_index(stack);
	s_index = tmp->index;
	while (tmp)
	{
		if (tmp->rank < s_rank)
		{
			s_rank = tmp->rank;
			s_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (s_index);
}

void	put_up_element(t_stack **stack_a)
{
	int	size;
	int	index;

	size = ft_stack_ln(*stack_a);
	index = smallest_index(stack_a);
	if (index <= (size + 1) / 2)
	{
		while (index > 1)
		{
			ra(stack_a);
			index--;
		}
	}
	else
	{
		while (index <= size)
		{
			rra(stack_a);
			index++;
		}
	}
}

int	check_if_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_to_b(stack_a, stack_b);
	sort_two_three(stack_a);
	while (*stack_b)
	{
		find_pos_in_a(stack_a, stack_b);
		movement_in_stack(stack_a, stack_b);
		find_less_mvt(stack_a, stack_b);
	}
	if (check_if_sorted(*stack_a) == 0)
		put_up_element(stack_a);
}
