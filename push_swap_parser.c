/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 07:32:43 by ggrzesiek         #+#    #+#             */
/*   Updated: 2025/07/28 07:50:15 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	w_num(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
				count++;
		}
		i++;
	}
	return (count);
}

static char	*get_word(char const *str, int i, int w_len)
{
	int		k;
	char	*word;

	k = 0;
	word = (char *)malloc(sizeof(char) * (w_len + 1));
	if (!word)
		return (NULL);
	while (k < w_len)
	{
		word[k] = str[(i + 1) - w_len + k];
		k++;
	}
	word[k] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		w_len;

	i = -1;
	j = 0;
	w_len = 0;
	arr = (char **)ft_calloc((w_num(s, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[++i] != 0)
	{
		if (s[i] != c)
		{
			w_len++;
			if (s[i + 1] == c || s[i + 1] == 0)
			{
				arr[j++] = get_word(s, i, w_len);
				w_len = 0;
			}
		}
	}
	return (arr);
}

void free_split(char **split)
{
	int i;
	
	if(!split)
		return;
	i=0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	parse_arg(char *arg, t_list **head_a)
{
	char **numbers;
	int	i;
	int	num;
	t_list	*new_node;

	numbers = ft_split(arg, ' ');
	if(!numbers)
		print_error();
	
	i = 0;
	while (numbers[i])
	{
		if(!is_num(numbers[i]))
		{
			free_split(numbers);
			print_error();
		}
		num = ft_atoi(numbers[i]);
		new_node = ft_lstnew(&num);
		if(!new_node)
		{
			free_split(numbers);
			print_error();
		}
		ft_lstadd_back(head_a,new_node);
		i++;
	}
	free_split(numbers);	
}

t_list *create_stack(int argc, char **argv)
{
	t_list *head_a;
	int i;

	head_a = NULL;
	i = 1;
	while(i < argc)
	{
		parse_arg(argv[i], &head_a);
		i++;
	}
	
	if(has_duplicates(head_a))
	{
		free_list(&head_a);
		print_error();
	}

	return (head_a);
}
