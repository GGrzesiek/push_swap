/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:24:26 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/15 13:03:12 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(int *stacka[])
{
	int stackb[5];
	for(int i=0; i<5; i++){
		printf("%d ", *stacka[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int i = 1;
	int numbers[5] = {0,1,2,3,4};
	t_list *head;
	// push_swap(argv);
	/* while (i < argc)
	{
		printf("%d \n",ft_atoi(argv[i]));
		i++;
	} */
	printf("tworzenie glowy \n");
	head = ft_lstnew(0);
	printf("Wypisywanie\n");
	printList(head);
	printf("nowe node'y\n");
	t_list *t_list1 = ft_lstnew(1);
	t_list *t_list2 = ft_lstnew(5);
	ft_lstadd_back(&head,t_list1);
	ft_lstadd_back(&head,t_list2);
	printf("Wypisywanie 2\n");
	printList(head);
	printf("swap\n");
	swap(head);
	printf("Wypisywanie 3\n");
	printList(head);

	radix(argv,argc);
	return 0;
}