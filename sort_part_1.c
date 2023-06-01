/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:08:46 by asekmani          #+#    #+#             */
/*   Updated: 2023/04/26 14:58:27 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_rank(t_stack *stack_a)
{
	int	max;

	max = 1;
	while (stack_a)
	{
		if (stack_a->rank > max)
			max = stack_a->rank;
		stack_a = stack_a->next;
	}
	return (max);
}

void	sort_two_three(t_stack **stack_a)
{
	int	max;
	int	size;

	size = ft_stack_ln(*stack_a);
	max = get_max_rank(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->rank == max)
			sa(stack_a);
	}
	if (size == 3)
	{
		if ((*stack_a)->rank == max)
			ra(stack_a);
		else if ((*stack_a)->next->rank == max)
			rra(stack_a);
		if ((*stack_a)->rank > (*stack_a)->next->rank)
			sa(stack_a);
	}
}

static int	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	p;
	int	i;

	size = ft_stack_ln(*stack_a);
	p = 0;
	i = 0;
	while (size > 6 && p < size / 2 && i++ < size)
	{
		if ((*stack_a)->rank < size / 2)
		{
			pb(stack_a, stack_b);
			p++;
		}
		else
			ra(stack_a);
	}
	return (p);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	p;
	int	i;

	size = ft_stack_ln(*stack_a);
	p = push_smallest_to_b(stack_a, stack_b);
	i = 0;
	while (size - p > 3 && i++ < size)
	{
		if ((*stack_a)->rank <= size - 3)
		{
			pb(stack_a, stack_b);
			p++;
		}
		else
			ra(stack_a);
	}
}
