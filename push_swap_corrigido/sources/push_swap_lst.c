/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfreixo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:59:51 by mfreixo-          #+#    #+#             */
/*   Updated: 2022/03/26 11:00:01 by mfreixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

t_stack	*lstnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->pos = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*lstlast(t_stack *first)
{
	if (!first)
		return (0);
	while (first->next)
	{
		first = first->next;
	}
	return (first);
}

void	lstclear(t_stack **first)
{
	t_stack	*aux;

	if (!first || !(*first))
		return ;
	while (*first)
	{
		aux = (*first)->next;
		free(*first);
		*first = aux;
	}
	if (aux)
		free(aux);
	first = NULL;
}

void	lstadd(t_stack **first, int value)
{
	t_stack	*aux;
	t_stack	*last;

	last = lstnew(value);
	if (!last)
		return ;
	if (!(*first))
	{
		*first = last;
		return ;
	}
	aux = lstlast(*first);
	aux->next = last;
	last->prev = aux;
}

int	lstsize(t_stack *first)
{
	int	size;

	size = 0;
	while (first)
	{
		size++;
		first = first->next;
	}
	return (size);
}
