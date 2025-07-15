/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:24:29 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/15 07:46:55 by ggrzesiek        ###   ########.fr       */
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

node_t	*ft_lstnew(void *val)
{
	node_t	*new_node;

	new_node = (node_t *)malloc(sizeof(node_t));
	if (!new_node)
		return (NULL);
	new_node->val = val;
	new_node->next = NULL;
	return (new_node);
}

void swap(node_t *head, int size)
{
	if (head == NULL || size < 2)
		return;
	node_t *temp;
	temp = head->next->next;
	
	head->next->next = head;
	printf("swap %s %s\n", head->val, head->val);
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