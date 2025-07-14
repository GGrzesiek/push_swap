/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:24:26 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/07/14 14:06:31 by gkryszcz         ###   ########.fr       */
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
	// push_swap(argv);
	/* while (i < argc)
	{
		printf("%d \n",ft_atoi(argv[i]));
		i++;
	} */
	radix(argv,argc);
	return 0;
}