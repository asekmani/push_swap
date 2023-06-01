/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:28:52 by asekmani          #+#    #+#             */
/*   Updated: 2023/04/26 15:17:10 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pos_in_a(t_stack **stack_a, t_stack **stack_b)
{
	int		s;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	set_index(stack_a);
	set_index(stack_b);
	(*stack_b)->pos_in_a = 0;
	while (tmp_b)
	{
		tmp_a = *stack_a;
		s = get_max_rank(*stack_a);
		while (tmp_a)
		{
			if (tmp_a->rank > tmp_b->rank && tmp_a->rank < s)
			{
				s = tmp_a->rank;
				tmp_b->pos_in_a = tmp_a->index;
			}
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}

void	movement_in_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_stack_ln(tmp_a);
	size_b = ft_stack_ln(tmp_b);
	while (tmp_b)
	{
		if (tmp_b->index <= (size_b) / 2 + (size_b % 2))
			tmp_b->mvt_b = tmp_b->index - 1;
		else
			tmp_b->mvt_b = (size_b - tmp_b->index + 1) * (-1);
		if (tmp_b->pos_in_a <= size_a / 2 + (size_a % 2))
			tmp_b->mvt_a = tmp_b->pos_in_a - 1;
		else
			tmp_b->mvt_a = (size_a - tmp_b->pos_in_a + 1) * (-1);
		tmp_b = tmp_b->next;
	}
}

int	sum_mvt(t_stack *stack)
{
	int	mvt_a;
	int	mvt_b;

	mvt_a = stack->mvt_a;
	if (stack->mvt_a < 0)
		mvt_a = mvt_a * (-1);
	mvt_b = stack->mvt_b;
	if (stack->mvt_b < 0)
		mvt_b = mvt_b * (-1);
	return (mvt_a + mvt_b);
}

void	find_less_mvt(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		min;
	int		mvt;
	int		mvt_a;
	int		mvt_b;

	tmp = *stack_b;
	min = INT_MAX;
	while (tmp)
	{
		mvt = sum_mvt(tmp);
		if (min > mvt)
		{
			min = mvt;
			mvt_a = tmp->mvt_a;
			mvt_b = tmp->mvt_b;
		}
		tmp = tmp->next;
	}
	put_up(stack_a, stack_b, mvt_a, mvt_b);
}
