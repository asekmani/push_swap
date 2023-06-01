/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:43:40 by asekmani          #+#    #+#             */
/*   Updated: 2023/04/26 15:00:17 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	up_by_rr(t_stack **stack_a, t_stack **stack_b, int *mvt_a,
		int *mvt_b)
{
	while ((*mvt_a) > 0 && (*mvt_b) > 0)
	{
		(*mvt_a)--;
		(*mvt_b)--;
		rr(stack_a, stack_b);
	}
}

static void	up_by_rrr(t_stack **stack_a, t_stack **stack_b, int *mvt_a,
		int *mvt_b)
{
	while ((*mvt_a) < 0 && (*mvt_b) < 0)
	{
		(*mvt_a)++;
		(*mvt_b)++;
		rrr(stack_a, stack_b);
	}
}

static void	up_by_ra(t_stack **stack_a, int *mvt_a)
{
	while (*mvt_a)
	{
		if ((*mvt_a) > 0)
		{
			ra(stack_a);
			(*mvt_a)--;
		}
		else if (*mvt_a < 0)
		{
			rra(stack_a);
			(*mvt_a)++;
		}
	}
}

static void	up_by_rb(t_stack **stack_b, int *mvt_b)
{
	while (*mvt_b)
	{
		if ((*mvt_b) > 0)
		{
			rb(stack_b);
			(*mvt_b)--;
		}
		else if (*mvt_b < 0)
		{
			rrb(stack_b);
			(*mvt_b)++;
		}
	}
}

void	put_up(t_stack **stack_a, t_stack **stack_b, int mvt_a, int mvt_b)
{
	if (mvt_a < 0 && mvt_b < 0)
		up_by_rrr(stack_a, stack_b, &mvt_a, &mvt_b);
	else if (mvt_a > 0 && mvt_b > 0)
		up_by_rr(stack_a, stack_b, &mvt_a, &mvt_b);
	up_by_ra(stack_a, &mvt_a);
	up_by_rb(stack_b, &mvt_b);
	pa(stack_b, stack_a);
}
