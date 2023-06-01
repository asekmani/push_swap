/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:42:33 by asekmani          #+#    #+#             */
/*   Updated: 2023/04/26 15:07:40 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_free(t_stack **stack_a, t_stack **stack_b, char *l)
{
	write(1, "Error\n", 6);
	get_next_line(1, 1);
	free_stack(stack_a);
	free_stack(stack_b);
	free(l);
	exit(0);
}

static void	error_message(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	ft_check(t_stack **stack_a, t_stack **stack_b, char *l)
{
	if (l[0] == 's' && l[1] == 'a' && l[2] == '\n')
		sa(stack_a);
	else if (l[0] == 's' && l[1] == 'b' && l[2] == '\n')
		sb(stack_b);
	else if (l[0] == 'p' && l[1] == 'a' && l[2] == '\n')
		pa(stack_b, stack_a);
	else if (l[0] == 'p' && l[1] == 'b' && l[2] == '\n')
		pb(stack_a, stack_b);
	else if (l[0] == 'r' && l[1] == 'a' && l[2] == '\n')
		ra(stack_a);
	else if (l[0] == 'r' && l[1] == 'b' && l[2] == '\n')
		rb(stack_b);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == '\n')
		rr(stack_a, stack_b);
	else if (l[0] == 's' && l[1] == 's' && l[2] == '\n')
		ss(stack_a, stack_b);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'a' && l[3] == '\n')
		rra(stack_a);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'b' && l[3] == '\n')
		rrb(stack_b);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'r' && l[3] == '\n')
		rrr(stack_a, stack_b);
	else
		ft_free(stack_a, stack_b, l);
}

int	main(int arc, char **arv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (arc < 2)
		return (0);
	if (error_cases(arv) == 1)
		error_message();
	stack_a = ft_init(arc, arv);
	stack_b = NULL;
	line = (char *)malloc(sizeof(char) * 1);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(0, 0);
		if (!line)
			break ;
		ft_check(&stack_a, &stack_b, line);
	}
	if (check_if_sorted(stack_a, stack_b) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(& stack_a);
	free_stack(& stack_b);
}
