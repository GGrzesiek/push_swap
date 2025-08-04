/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:43:19 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/08/04 09:43:47 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;

	if (argc < 2)
		return (0);
	head_a = create_stack(argc, argv);
	if (!head_a)
		return (0);
	head_b = NULL;
	main_controller(&head_a, &head_b);
	free_list(&head_a);
	free_list(&head_b);
	return (0);
}
