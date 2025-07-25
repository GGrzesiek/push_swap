#include "push_swap.h"

int	is_sorted(t_list *head)
{
	while(head && head ->next)
	{
		if(head->val > head->next->val)
			return 0;
		head = head ->next;
	}
	return 1;
}

int find_min(t_list *head)
{
	int min;

	if(!head)
		return 0;
	min = head->val;
	while (head)
	{
		if (head ->val < min)
			min = head->val;
		head = head -> next;
	}
	return (min);
}

int find_max(t_list *head)
{
	int max;

	if(!head)
		return 0;
	max = head->val;
	while (head)
	{
		if (head ->val > max)
			max = head->val;
		head = head -> next;
	}
	return (max);
}

int get_position(t_list *head, int value)
{
	int pos = 0;

	while (head)
	{
		if (head ->val == value)
			return (pos);
		head = head->next;
		pos++;
	}

	return -1;
}
void	sort_three(t_list **head_a)
{
	int first;
	int second;
	int third;

	if (!head_a || !*head_a || ft_lst_size(*head_a) != 3)
		return;
	first = (*head_a)->val;
	second = (*head_a)->next->val;
	third = (*head_a)->next->next->val;

	if (first > second && second < third && first < third)
		sa(head_a);
	else if (first > second && second > third)
	{
		sa(head_a);
		rra(head_a);
	}
	else if (first > second && second < third && first > third)
		ra(head_a);
	else if (first < second && second > third && first < third)
	{
		sa(head_a);
		ra(head_a);
	}
	else if(first < second && second > third && first > third)
		rra(head_a);
}

void sort_small_loop(t_list **head_a, t_list **head_b)
{
	int pos;
	int min;

	while(ft_lstsize(*head_a > 3))
	{
		min = find_min(*head_a);
		pos = get_position(*head_a, min);

		if (pos <= ft_lstsize(*head_a) / 2)
		{
			while((*head_a)->val != min)
				ra(head_a);
		}
		else
		{
			while((*head_a)->val != min)
				rra(head_b);
		}
		pb(head_a,head_b);
	}
}

void sort_small(t_list **head_a, t_list **head_b)
{
	int size = ft_lstsize(*head_a);

	if (size <= 1 || is_sorted(*head_a))
		return;

	if(size == 2)
	{
		if((*head_a) ->val > (*head_a) ->next->val)
			sa(head_a);
		return;
	}

	if(size == 3)
	{
		sort_three(head_a);
		return;
	}

	sort_small_loop(head_a,head_b);
	sort_three(head_a);

	while (head_b)
		pa(head_a,head_b);
}

void radix_sort(t_list **head_a, t_list **head_b)
{
	int max_bits = 0;
	int max_num = find_max(*head_a);
	int size = ft_lstsize(*head_a);
	int bit = 0;
	int i;

	while ((max_num >> max_bits) != 0)
		max_bits++;

	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if((((*head_a)->val >> bit) & 1) == 1)
				ra(head_a);
			else
				pb(head_a,head_b);
			i++;
		}
		while (*head_b)
			pa(head_a,head_b);
		
		bit++;
	}
}

void main_controller(t_list **head_a, t_list **head_b)
{
	int size;

	if(!head_a || !*head_a || is_sorted(*head_a))
		return;

	size = ft_lstsize(*head_a);

	if(size <= 5)
		sort_small(head_a,head_b);
	else
		radix_sort(head_a,head_b);
}