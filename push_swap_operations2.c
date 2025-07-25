/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:57:13 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/25 13:26:01 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **head_b)
{
	rotate(head_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **head_a, t_list **head_b)
{
	rotate(head_a);
	rotate(head_b);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_list **head_a)
{
	reverse_rotate(head_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **head_b)
{
	reverse_rotate(head_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **head_a, t_list **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	ft_putstr_fd("rrr\n", 1);
}
