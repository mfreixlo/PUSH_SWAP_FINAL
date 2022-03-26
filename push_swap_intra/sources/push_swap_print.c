/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfreixo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:50:18 by mfreixo-          #+#    #+#             */
/*   Updated: 2022/03/23 15:52:43 by mfreixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	print_fun(t_stack **first, char *str, void (*f)(t_stack **), int times)
{
	if (!first)
		return ;
	while (times--)
	{
		f(first);
		ft_putstr_fd(str, 1);
	}
}

void	print_push(t_stack **first_1, t_stack **first_2, int times, char stack)
{
	if (!first_1 || !first_2)
		return ;
	while (times--)
	{
		push(first_1, first_2);
		if (stack == 'a')
			ft_putstr_fd("pa\n", 1);
		else
			ft_putstr_fd("pb\n", 1);
	}
}
