/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:45:46 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/28 11:03:59 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		lng;
	t_list	*tmp;

	lng = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		lng++;
	}
	return (lng);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	free_list(t_list **head)
{
	t_list	*temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

t_list	find_node(t_list *head, int value)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		if (current->val == value)
			return (*current);
		current = current->next;
	}
	return ((t_list){0, NULL, NULL});
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		(*del)(&(lst->val));
	free(lst);
}
