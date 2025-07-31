/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:24:29 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/30 18:28:04 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nptr)
{
	long	res;
	int	count;

	res = 0;
	count = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			count++;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	if (count % 2 != 0)
		res = -res;
	return (res);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	is_sorted(t_list *head)
{
	while (head && head->next)
	{
		if (head->val > head->next->val)
			return (0);
		head = head->next;
	}
	return (1);
}

int	find_min(t_list *head)
{
	int	min;

	if (!head)
		return (0);
	min = head->val;
	while (head)
	{
		if (head->val < min)
			min = head->val;
		head = head->next;
	}
	return (min);
}

int	find_max(t_list *head)
{
	int	max;

	if (!head)
		return (0);
	max = head->rank;
	while (head)
	{
		if (head->rank > max)
			max = head->rank;
		head = head->next;
	}
	return (max);
}
