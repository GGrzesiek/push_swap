
#include "push_swap.h"

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

void decide(t_list **stacka, t_list **stackb)
{
	int size;
	size = ft_lstsize(*stacka);
	while(size > 3)
	{
		push(*stacka, *stackb);
		size = ft_lstsize(*stacka);
	}
	if(size == 3)
		sort_three(**stacka);
	if(size < 3)
	{
		if((*stacka)->val > (*stacka)->next->val)
			sa(stacka);
	}
}

void minmax(t_list **stackb)
{
	int min;
	int max;
	if((*stackb)->val > (*stackb)->next->val)
	{
		min = (*stackb)->next->val;
		max = (*stackb)->val;
	}
	else
	{
		max = (*stackb)->next->val;
		min = (*stackb)->val;
	}
}

t_list	*target_node(int value, t_list *stackb)
{
	int min;
	int i;
	int tmp;
	int min_index;
	t_list **current;

	i = 0;
	(*current)-> index = i;
	min = stackb->val - value;
	current = (*current)-> next;

	while((*current)->next)
	{	
		(*current)-> index = i;
		tmp = (*current)->val - value;
		if (tmp < min)
		{
			min = tmp;
			min_index = i;
		}
		i++;
		current = (*current)-> next;
	}
	while(stackb->next)
	{
		if(stackb->index == min_index)
			return stackb;
	}
}