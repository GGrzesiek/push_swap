/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_templates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:43:58 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/30 12:29:12 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap(t_list **head)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!head || !*head || !(*head)->next)
		return (*head);
	tmp1 = (*head);
	tmp2 = (*head)->next;
	tmp1->next = tmp2->next;
	if (tmp2->next)
		tmp2->next->prev = tmp1;
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	tmp2->prev = NULL;
	*head = tmp2;
	return (*head);
}

void	push(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	if (!head_a || !*head_a)
		return ;
	tmp = *head_a;
	*head_a = (*head_a)->next;
	if (*head_a)
		(*head_a)->prev = NULL;
	tmp->next = *head_b;
	tmp->prev = NULL;
	if (*head_b)
		(*head_b)->prev = tmp;
	*head_b = tmp;
}

void	rotate(t_list **head)
{
	t_list	*last;
	t_list	*first;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = ft_lstlast(*head);
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	reverse_rotate(t_list **head)
{
	t_list	*prev_last;
	t_list	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	last = ft_lstlast(*head);
	prev_last = last->prev;
	if (prev_last)
		prev_last->next = NULL;
	last->next = *head;
	last->prev = NULL;
	(*head)->prev = last;
	*head = last;
}

void	radix_loop(int size, int bit, t_list **head_a, t_list **head_b)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((((*head_a)->rank >> bit) & 1) == 1)
			ra(head_a);
		else
			pb(head_a, head_b);
		i++;
	}
	while (*head_b)
		pa(head_a, head_b);
}
