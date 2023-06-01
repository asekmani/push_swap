/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:37:48 by asekmani          #+#    #+#             */
/*   Updated: 2023/04/25 12:37:51 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*bottom;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	top = *stack;
	bottom = *stack;
	while (bottom->next != NULL)
		bottom = bottom->next;
	*stack = top->next;
	top->next = NULL;
	bottom->next = top;
}

void	ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
