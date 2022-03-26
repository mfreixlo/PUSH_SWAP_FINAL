/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfreixo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:38:38 by mfreixo-          #+#    #+#             */
/*   Updated: 2022/03/23 11:02:06 by mfreixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	lstmax(t_stack *first)
{
	int	max;

	if (!first)
		return (0);
	else
		max = first->value;
	while (first)
	{
		if (first->value > max)
			max = first->value;
		first = first->next;
	}
	return (max);
}

int	lstmin(t_stack *first)
{
	int	min;

	if (!first)
		return (0);
	else
		min = first->value;
	while (first)
	{
		if (first->value < min)
			min = first->value;
		first = first->next;
	}
	return (min);
}

t_stack	*node_dup(t_stack *node)
{
	t_stack	*new;

	if (!node)
		return (NULL);
	new = lstnew(node->value);
	new->pos = node->pos;
	return (new);
}

int	lstmin_pos(t_stack *first)
{
	int	min;

	if (!first)
		return (0);
	else
		min = first->pos;
	while (first)
	{
		if (first->pos < min)
			min = first->pos;
		first = first->next;
	}
	return (min);
}

int	lstmax_pos(t_stack *first)
{
	int	max;

	if (!first)
		return (0);
	else
		max = first->pos;
	while (first)
	{
		if (first->pos > max)
			max = first->pos;
		first = first->next;
	}
	return (max);
}
