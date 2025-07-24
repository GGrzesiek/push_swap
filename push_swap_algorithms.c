#include "push_swap.h"

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