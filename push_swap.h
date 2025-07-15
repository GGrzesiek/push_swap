/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:24:28 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/15 10:56:50 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_list
{
	int			*val;
	struct s_list	*next;
}					t_list;
// char	*push_swap(int *stack);
int	ft_atoi(const char *nptr);
void radix(char **stack, int size);
size_t	ft_strlen(const char *s);
t_list	*ft_lstnew(void *val);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void printList(t_list* head);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void swap(t_list *head);



#endif