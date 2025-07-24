
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