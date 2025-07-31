/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 07:32:43 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/30 18:28:22 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_list *head, int value)
{
	int	pos;

	pos = 0;
	while (head)
	{
		if (head->val == value)
			return (pos);
		head = head->next;
		pos++;
	}
	return (-1);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	parsing_error(char	**numbers)
{
	free_split(numbers);
	print_error();
}

void	parse_arg(char *arg, t_list **head_a)
{
	char	**numbers;
	int		i;
	int		num;
	t_list	*new_node;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		print_error();
	i = 0;
	while (numbers[i])
	{
		if (!is_num(numbers[i]))
			parsing_error(numbers);
		num = ft_atoi(numbers[i]);
		new_node = ft_lstnew(&num);
		if (!new_node)
			parsing_error(numbers);
		ft_lstadd_back(head_a, new_node);
		i++;
	}
	free_split(numbers);
}

t_list	*create_stack(int argc, char **argv)
{
	t_list	*head_a;
	int		i;

	head_a = NULL;
	i = 1;
	while (i < argc)
	{
		parse_arg(argv[i], &head_a);
		i++;
	}
	if (has_duplicates(head_a))
	{
		free_list(&head_a);
		print_error();
	}
	return (head_a);
}
