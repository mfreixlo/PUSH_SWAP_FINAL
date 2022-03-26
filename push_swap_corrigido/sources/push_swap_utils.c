/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfreixo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:53:32 by mfreixo-          #+#    #+#             */
/*   Updated: 2022/03/26 15:31:34 by mfreixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	ischar(char c)
{
	if (!ft_isdigit(c))
	{
		if (c != '+' && c != '-' && !ft_isspace(c))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

long int	chartonbr(char **str)
{
	long int	num;
	int			sign;

	num = 0;
	sign = 1;
	if ((**str) == '+')
		(*str)++;
	else if ((**str) == '-')
	{
		sign = -1;
		(*str)++;
	}
	while (ft_isdigit(**str))
	{
		num = num * 10 + (**str) - '0';
		(*str)++;
	}
	return (sign * num);
}

int	find_pos(t_stack *first, int min, int max)
{
	t_stack	*aux;
	int		i;
	int		size;

	if (!first)
		return (-1);
	aux = lstlast(first);
	i = 0;
	size = lstsize(first);
	while (i <= size)
	{
		if (first->pos >= min && first->pos <= max)
			return (i);
		if (aux->pos >= min && aux->pos <= max)
			return (size - i);
		i++;
		aux = aux->prev;
		first = first->next;
	}
	return (i);
}

void	put_top(t_stack **first, int min, int max, char stack)
{
	int	pos;
	int	size;

	if (!first)
		return ;
	size = lstsize(*first);
	pos = find_pos(*first, min, max);
	if (pos <= size / 2)
	{
		if (stack == 'a')
			print_fun(first, "ra\n", rotate, pos);
		else
			print_fun(first, "rb\n", rotate, pos);
	}
	else
	{
		if (stack == 'a')
			print_fun(first, "rra\n", revrotate, size - pos + 1);
		else
			print_fun(first, "rrb\n", revrotate, size - pos + 1);
	}
}
