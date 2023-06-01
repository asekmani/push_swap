/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:38:14 by asekmani          #+#    #+#             */
/*   Updated: 2023/04/26 15:01:49 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_rrotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*bottom;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	top = *stack;
	bottom = *stack;
	while (bottom->next != NULL)
	{
		top = bottom;
		bottom = bottom->next;
	}
	top->next = NULL;
	bottom->next = *stack;
	*stack = bottom;
}

void	rra(t_stack **stack_a)
{
	ft_rrotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	ft_rrotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
}
