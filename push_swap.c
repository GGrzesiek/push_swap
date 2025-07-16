/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:24:26 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/16 14:35:46 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *stacka[])
{
	int	stackb[5];

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", *stacka[i]);
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	int i = 1;
	int numbers[5] = {0, 1, 2, 3, 4};
	t_list *head;
	t_list *headb;
	// push_swap(argv);
	/* while (i < argc)
	{
		printf("%d \n",ft_atoi(argv[i]));
		i++;
	} */
	// printf("tworzenie glowy \n");
	head = ft_lstnew(0);
	headb = ft_lstnew(20);

	// printf("Tworzenie\n");
	// printList(head);
	// printf("nowe node'y\n");
	t_list *t_list1 = ft_lstnew(1);
	t_list *t_list2 = ft_lstnew(5);
	t_list *nodeb = ft_lstnew(100);
	ft_lstadd_front(&head, t_list1);
	ft_lstadd_front(&head, t_list2);
	ft_lstadd_front(&headb, nodeb);
	// printf("Stacka:\n");
	// printList(head);
	// printf("Stackb: \n");
	// printList(headb);
	
	/* printf("Swap\n");
	head = swap(head);
	printf("Wypisywanie 3\n");
	printList(head); */
	
	printf("Pushing a first argument to b \n");
	push(&head,&headb);
	printf("Stack A: ");
	printList(head);
	printf("Stack B: ");
	printList(headb);

	printf("Rotate B: ");
	rotate(&headb);
	printList(headb);
	// radix(argv,argc);
	printf("Reverse Rotate B: ");
	reverse_rotate(&headb);
	printList(headb);
	printf("One more: ");
	reverse_rotate(&headb);
	printList(headb);

	return (0);
}