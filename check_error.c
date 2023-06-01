/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:47:18 by asekmani          #+#    #+#             */
/*   Updated: 2023/04/26 15:05:56 by asekmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nbr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+' && s2[j] != '+')
		i++;
	if (s1[i] != '+' && s2[j] == '+')
		j++;
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

static int	ft_is_zero(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] && s[i] == '0')
		i++;
	if (s[i] != '\0')
		return (0);
	return (1);
}

static int	check_double(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (nbr_cmp(s[i], s[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_cases(char **s)
{
	int			i;
	int			zero;
	long long	nb;

	i = 1;
	zero = 0;
	while (s[i])
	{
		nb = ft_long_atoi(s[i]);
		if (ft_is_number(s[i]) == 0)
			return (1);
		if (nb > 2147483647 || nb < -2147483648)
			return (1);
		zero += ft_is_zero(s[i]);
		i++;
	}
	if (check_double(s) == 1)
		return (1);
	if (zero > 1)
		return (1);
	return (0);
}
