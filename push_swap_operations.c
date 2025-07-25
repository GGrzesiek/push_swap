
#include "push_swap.h"

t_list	*swap(t_list **head)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!head || !*head || !(*head)->next)
		return *head;
	tmp1 = (*head);
	tmp2 = (*head)->next;

	tmp1->next = tmp2->next;
	if (tmp2 ->next)
		tmp2 ->next->prev = tmp1;

	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	tmp2->prev = NULL;

	*head = tmp2;
	return (*head);
}

void	push(t_list **head_a, t_list **head_b)
{
	t_list *tmp;

	if (!head_a || !*head_a)
		return;
	tmp = *head_a;
	*head_a = (*head_a)->next;
	if (*head_a)
		(*head_a)->prev = NULL;

	tmp->next = *head_b;
	tmp->prev = NULL;
	if (*head_b)
		(*head_b)->prev = tmp;
	ft_lstadd_front(head_b, tmp);
}

void	rotate(t_list **head)
{
	t_list *last;
	t_list *first;
	if (!head || !*head || !(*head)->next)
		return;
	first = *head;
	last = ft_lstlast(*head);

	*head = first ->next;
	(*head)->prev = NULL;
	
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	reverse_rotate(t_list **head)
{
	t_list *prev_last;
	t_list *last;

	if (!head || !*head || !(*head)->next)
		return;
	
	last = ft_lstlast(*head);
	prev_last = last->prev;

	if (prev_last)
		prev_last->next = NULL;
	
	last->next = *head;
	last->prev = NULL;
	(*head)->prev = last;
	*head = last;
}

void sa(t_list **head_a)
{
	swap(head_a);
	ft_putstr_fd("sa\n", 1);
}

void sb(t_list **head_b)
{
	swap(head_b);
	ft_putstr_fd("sb\n", 1);
}

void ss(t_list **head_a, t_list **head_b)
{
	swap(head_a);
	swap(head_b);
	ft_putstr_fd("ss\n", 1);
}

void pa(t_list **head_a, t_list **head_b)
{
	push(head_a,head_b);
	ft_putstr_fd("pa\n",1);
}

void pa(t_list **head_a, t_list **head_b)
{
	push(head_b,head_a);
	ft_putstr_fd("pb\n",1);
}

void ra(t_list **head_a)
{
	rotate(head_a);
	ft_putstr_fd("ra\n",1);
}

void rb(t_list **head_b)
{
	rotate(head_b);
	ft_putstr_fd("rb\n",1);
}

void rr(t_list **head_a,t_list **head_b)
{
	rotate(head_a);
	rotate(head_b);
	ft_putstr_fd("rr\n",1);
}

void rra(t_list **head_a)
{
	reverse_rotate(head_a);
	ft_putstr_fd("rra\n",1);
}

void rrb(t_list **head_b)
{
	reverse_rotate(head_b);
	ft_putstr_fd("rrb\n",1);
}

void rrr(t_list **head_a,t_list **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	ft_putstr_fd("rrr\n",1);
}