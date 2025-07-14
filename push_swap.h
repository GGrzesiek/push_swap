/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:24:28 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/14 14:53:15 by gkryszcz         ###   ########.fr       */
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

// char	*push_swap(int *stack);
int	ft_atoi(const char *nptr);
void radix(char **stack, int size);
size_t	ft_strlen(const char *s);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

#endif