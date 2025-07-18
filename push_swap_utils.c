/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:24:29 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/16 14:35:00 by gkryszcz         ###   ########.fr       */
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

void	radix(char **stack, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		printf("%s \n", stack[i]);
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

t_list	*swap(t_list **head)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (head == NULL || (*head)->next == NULL)
		return NULL;
	tmp1 = (*head);
	tmp2 = (*head)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	return (tmp2);
}

void	push(t_list **head_a, t_list **head_b)
{
	t_list *tmp;

	if (!head_a || !*head_a)
		return;
	tmp = *head_a;
	*head_a = (*head_a)->next;
	tmp->next = NULL;
	ft_lstadd_front(head_b, tmp);

	printf("Stack A after push: ");
	printList(*head_a);
	printf("Stack B after push: ");
	printList(*head_b);
}

void	rotate(t_list **head)
{
	t_list *lst;
	t_list *new_head;
	if (!head || !*head || !(*head)->next)
		return;
	lst = ft_lstlast(*head);
	new_head = (*head)->next;
	(*head)->next = NULL;
	lst->next = *head;
	*head = new_head;
}

void	reverse_rotate(t_list **head)
{
	t_list *prev_lst;
	t_list *last;

	if (!head || !*head || !(*head)->next)
		return;
	prev_lst = ft_prevlstlast(*head);
	last = prev_lst->next;
	prev_lst->next = NULL;
	last->next = *head;
	*head = last;
}