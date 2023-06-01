/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:34:54 by asekmani          #+#    #+#             */
/*   Updated: 2023/04/26 15:11:47 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stack_ln(*stack_a);
	set_rank(*stack_a, size);
	if ((size == 3 || size == 2) && check_if_sorted(*stack_a) == 0)
		sort_two_three(stack_a);
	else if (size > 3 && check_if_sorted(*stack_a) == 0)
		sort(stack_a, stack_b);
}

int	main(int arc, char **arv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (arc < 2)
		return (0);
	if (error_cases(arv) == 1)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	stack_a = ft_init(arc, arv);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
