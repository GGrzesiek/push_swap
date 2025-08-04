/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:24:28 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/08/04 09:40:54 by gkryszcz         ###   ########.fr       */
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
	int				val;
	struct s_list	*next;
	struct s_list	*prev;
	int				rank;
}					t_list;

// char	*push_swap(int *stack);
long				ft_atoi(const char *nptr);
void				radix(char **stack, int size);
size_t				ft_strlen(const char *s);
t_list				*ft_lstnew(int *val);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				printList(t_list *head);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*swap(t_list **head);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				push(t_list **head_a, t_list **head_b);
void				rotate(t_list **head);
void				reverse_rotate(t_list **head);
t_list				*ft_prevlstlast(t_list *lst);
void				ft_putstr_fd(char *s, int fd);
int					ft_lstsize(t_list *lst);
void				ft_putstr_fd(char *s, int fd);
void				print_error(void);
int					is_sorted(t_list *head);
void				sort_small(t_list **head_a, t_list **head_b);
void				radix_sort(t_list **head_a, t_list **head_b);
void				sa(t_list **head_a);
void				sb(t_list **head_b);
void				ss(t_list **head_a, t_list **head_b);
void				pa(t_list **head_a, t_list **head_b);
void				pb(t_list **head_a, t_list **head_b);
void				ra(t_list **head_a);
void				rb(t_list **head_b);
void				rr(t_list **head_a, t_list **head_b);
void				rra(t_list **head_a);
void				rrb(t_list **head_b);
void				rrr(t_list **head_a, t_list **head_b);
int					find_min(t_list *head);
int					find_max(t_list *head);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					is_num(char *str);
int					has_duplicates(t_list *head);
void				free_list(t_list **head);
t_list				*create_stack(int argc, char **argv);
void				*ft_calloc(size_t nmemb, size_t size);
int					get_position(t_list *head, int value);
char				**ft_split(char const *s, char c);
void				radix_loop(int size, int bit, t_list **head_a,
						t_list **head_b);
#endif