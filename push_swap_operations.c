/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:29:24 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/09/23 13:37:42 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head_a)
{
	swap(head_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **head_b)
{
	swap(head_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **head_a, t_list **head_b)
{
	swap(head_a);
	swap(head_b);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_list **head_a, t_list **head_b)
{
	push(head_b, head_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **head_a, t_list **head_b)
{
	push(head_a, head_b);
	ft_putstr_fd("pb\n", 1);
}
