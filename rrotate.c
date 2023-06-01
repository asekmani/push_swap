/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:48:43 by asekmani          #+#    #+#             */
/*   Updated: 2023/04/26 15:12:31 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	ft_rrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
	write(1, "rrr\n", 4);
}
