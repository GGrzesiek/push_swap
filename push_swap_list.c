/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:45:46 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/25 07:01:48 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!lst || !f)
		return ;
	tmp = lst;
	while (tmp)
	{
		f(tmp->val);
		tmp = tmp->next;
	}
}

/*
void	printList(t_list *head)
{
	while (head != NULL)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
} */

t_list	*ft_lstnew(void *val)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(1 * sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->val = val;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	if(*lst)
		(*lst)->prev = new;
	new->prev = NULL;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int lng;
	t_list *tmp;

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

t_list	*ft_prevlstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	if (!node)
		return (NULL);
	while (node->next->next)
		node = node->next;
	return (node);
}

t_list find_node(t_list *head, int value)
{
	t_list *current = head;
	while (current != NULL)
	{
		if (current->val == value)
			return *current;
		current = current->next;
	}	
	return (t_list){NULL, NULL, NULL};
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		(*del)(&(lst->val));
	free(lst);
}