/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:24:28 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/15 13:52:31 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				*val;
	struct s_list	*next;
}					t_list;
// char	*push_swap(int *stack);
int					ft_atoi(const char *nptr);
void				radix(char **stack, int size);
size_t				ft_strlen(const char *s);
t_list				*ft_lstnew(void *val);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				printList(t_list *head);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*swap(t_list *head);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	push(t_list *head_a, t_list *head_b, char mode);

#endif