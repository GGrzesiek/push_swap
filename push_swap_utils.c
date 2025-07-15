/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:24:29 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/15 11:05:08 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	res;
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

void radix(char **stack, int size)
{
	int i = 1;
	while(i < size)
	{
		printf("%s \n",stack[i]);
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


void swap(t_list *head)
{
	t_list *tmp1;
	t_list *tmp2;
	if (head == NULL || head->next == NULL)
		return;
	tmp1 = head;
	tmp2 = head->next; 
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	
	printf("%d", tmp1->val);
	printf("%d", tmp2->val);
}

void push(char **src, char **dest, int *src_size, int *dest_size)
{
	if (*src_size == 0)
		return;
	char *temp = src[0];
	
}

void rotate(char **stack)
{
	
}

void reverse_rotate(char **stack)
{
	
}