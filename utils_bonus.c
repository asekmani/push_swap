/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:49:17 by asekmani          #+#    #+#             */
/*   Updated: 2023/04/26 15:09:55 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_is_number(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if ((s[i] == '-' || s[i] == '+') && s[i + 1] != '\0')
		i++;
	while (s[i] != '\0' && ft_is_digit(s[i]) == 1)
		i++;
	if (s[i] != '\0' && ft_is_digit(s[i]) == 0)
		return (0);
	return (1);
}

int	ft_stack_ln(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

long long	ft_long_atoi(const char *str)
{
	int			i;
	int			j;
	long long	nb;

	i = 0;
	j = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	if (j < 0)
		nb = -nb;
	return (nb);
}
