/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:24:26 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/25 13:25:27 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (*lst)
		(*lst)->prev = new;
	new->prev = NULL;
	*lst = new;
}

void	ra(t_list **head_a)
{
	rotate(head_a);
	ft_putstr_fd("ra\n", 1);
}

void	main_controller(t_list **head_a, t_list **head_b)
{
	int	size;

	if (!head_a || !*head_a || is_sorted(*head_a))
		return ;
	size = ft_lstsize(*head_a);
	if (size <= 5)
		sort_small(head_a, head_b);
	else
		radix_sort(head_a, head_b);
}

// void	push_swap(int *stacka[])
// {
// 	int	stackb[5];

// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("%d ", *stacka[i]);
// 	}
// 	printf("\n");
// }

void	print_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

// int	main(int argc, char *argv[])
// {
// 	int i = 1;
// 	int numbers[5] = {0, 1, 2, 3, 4};
// 	t_list *head;
// 	t_list *headb;
// 	// push_swap(argv);
// 	/* while (i < argc)
// 	{
// 		printf("%d \n",ft_atoi(argv[i]));
// 		i++;
// 	} */
// 	// printf("tworzenie glowy \n");
// 	head = ft_lstnew(0);
// 	headb = ft_lstnew(20);

// 	// printf("Tworzenie\n");
// 	// printList(head);
// 	// printf("nowe node'y\n");
// 	t_list *t_list1 = ft_lstnew(1);
// 	t_list *t_list2 = ft_lstnew(5);
// 	t_list *nodeb = ft_lstnew(100);
// 	ft_lstadd_front(&head, t_list1);
// 	ft_lstadd_front(&head, t_list2);
// 	ft_lstadd_front(&headb, nodeb);
// 	// printf("Stacka:\n");
// 	// printList(head);
// 	// printf("Stackb: \n");
// 	// printList(headb);

// 	/* printf("Swap\n");
// 	head = swap(head);
// 	printf("Wypisywanie 3\n");
// 	printList(head); */

// 	printf("Pushing a first argument to b \n");
// 	push(&head, &headb);
// 	printf("Stack A: ");
// 	printList(head);
// 	printf("Stack B: ");
// 	printList(headb);

// 	printf("Rotate B: ");
// 	rotate(&headb);
// 	printList(headb);
// 	// radix(argv,argc);
// 	printf("Reverse Rotate B: ");
// 	reverse_rotate(&headb);
// 	printList(headb);
// 	printf("One more: ");
// 	reverse_rotate(&headb);
// 	printList(headb);

// 	return (0);
// }
