/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfreixo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:42:00 by mfreixo-          #+#    #+#             */
/*   Updated: 2022/03/26 10:49:00 by mfreixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h> 

void	order(t_stack **first_a)
{
	t_stack	*first_b;
	int		size_a;

	if (!first_a)
		return ;
	first_b = NULL;
	size_a = lstsize(*first_a);
	if (size_a <= 3)
		order_3(first_a);
	else if (size_a <= 5)
		order_5(first_a, &first_b);
	else if (size_a <= 100)
		order_x00(first_a, &first_b, 5);
	else
		order_x00(first_a, &first_b, 11);
}

int	is_ordered(t_stack *first)
{
	int	n;

	if (!first)
		return (0);
	n = first->pos;
	while (first)
	{
		if (n != first->pos)
			return (0);
		n++;
		first = first->next;
	}
	return (1);
}

void	order_3(t_stack **first)
{
	t_stack	*second;
	int		size;

	if (!first)
		return ;
	size = lstsize(*first);
	if (size == 2)
		if (!is_ordered(*first))
			print_fun(first, "sa\n", swap, 1);
	if (size == 3)
	{
		while (!is_ordered(*first))
		{
			second = (*first)->next;
			if ((*first)->pos < second->pos)
				print_fun(first, "rra\n", revrotate, 1);
			else if (is_ordered(second))
				print_fun(first, "ra\n", rotate, 1);
			else
				print_fun(first, "sa\n", swap, 1);
		}
	}
}

void	order_5(t_stack **first_a, t_stack **first_b)
{
	int	min;
	int	size;

	if (!first_a || !first_b)
		return ;
	size = lstsize(*first_a);
	min = lstmin_pos(*first_a);
	while (!(is_ordered(*first_a)) && size >= 4)
	{
		put_top(first_a, min, min + 1, 'a');
		if (!is_ordered(*first_a))
		{
			print_push(first_a, first_b, 1, 'b');
			size -= 1;
		}
	}
	if (size <= 3)
		order_3(first_a);
	size = lstsize(*first_b);
	if (size > 0)
	{
		if (size == 2 && (*first_b)->pos < (*first_b)->next->pos)
			print_fun(first_b, "rb\n", rotate, 1);
		print_push(first_b, first_a, size, 'a');
	}
}

void	order_x00(t_stack **first_a, t_stack **first_b, int chunk_num)
{
	int	min;
	int	max;
	int	size_a;
	int	chunk;
	int	i;

	size_a = lstsize(*first_a);
	chunk = -1;
	while (++chunk < chunk_num)
	{
		i = 0;
		chunk_lim(chunk, &min, &max, size_a);
		while (i < max - min + 1)
		{
			put_top(first_a, min, max, 'a');
			print_push(first_a, first_b, 1, 'b');
			i++;
		}
	}
	max = lstmax_pos(*first_b) + 1;
	while (--max >= 0)
	{
		put_top(first_b, max, max, 'b');
		print_push(first_b, first_a, 1, 'a');
	}
}
