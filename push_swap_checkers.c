/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:25:32 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/08/04 09:41:17 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	has_duplicates(t_list *head)
{
	t_list	*current;
	t_list	*check;

	current = head;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->val == check->val)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

//actually not a checkers, just can't add more functions to push_swap_list.c :P

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast(*lst);
	node->next = new;
	new->prev = node;
}

t_list	*ft_lstnew(int *val)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(1 * sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->val = *val;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	if (*lst)
		(*lst)->prev = new;
	new->prev = NULL;
	*lst = new;
}
