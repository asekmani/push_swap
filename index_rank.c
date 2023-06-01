/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:41:04 by asekmani          #+#    #+#             */
/*   Updated: 2023/04/06 13:41:27 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 1;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

static t_stack	*get_first_rank(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL && tmp->rank != 0)
		tmp = tmp->next;
	return (tmp);
}

static void	max_value(t_stack *stack_a, int rank)
{
	t_stack	*max;
	t_stack	*tmp;

	max = get_first_rank(stack_a);
	tmp = max;
	while (tmp)
	{
		if (tmp->rank == 0 && tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	if (max != NULL)
		max->rank = rank;
}

void	set_rank(t_stack *stack_a, int size)
{
	while (size > 0)
	{
		max_value(stack_a, size);
		size--;
	}
}
