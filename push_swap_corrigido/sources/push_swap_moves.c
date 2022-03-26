/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfreixo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:39:06 by mfreixo-          #+#    #+#             */
/*   Updated: 2022/03/23 15:41:35 by mfreixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h> 

void	swap(t_stack **first)
{
	t_stack	*aux;

	if (!first || !(*first) || !((*first)->next))
		return ;
	if ((*first)->next)
	{
		aux = (*first)->next;
		if (aux->next)
		{
			(*first)->next = aux->next;
			aux->next->prev = (*first);
			(*first)->prev = aux;
			aux->next = (*first);
			aux->prev = NULL;
		}
		else
		{
			(*first)->prev = aux;
			(*first)->next = NULL;
			aux->next = (*first);
			aux->prev = NULL;
		}
		(*first) = aux;
	}
}

void	push(t_stack **first_1, t_stack **first_2)
{
	t_stack	*aux;

	if (!first_1 || !first_2)
		return ;
	if (!(*first_1))
		return ;
	aux = node_dup(*first_1);
	stackadd_front(first_2, aux);
	if ((*first_1)->next)
	{
		aux = (*first_1)->next;
		aux->prev = NULL;
		free(*first_1);
		(*first_1) = aux;
	}
	else
		lstclear(first_1);
}

void	rotate(t_stack **first)
{
	t_stack	*aux;

	if (!first)
		return ;
	if (!(*first) || !(*first)->next)
		return ;
	if ((*first)->next)
	{
		if (!((*first)->next->next))
			swap (first);
		else
		{
			aux = node_dup(*first);
			stackadd_back(first, aux);
			aux = (*first)->next;
			free(*first);
			*first = aux;
		}
	}
}

void	revrotate(t_stack **first)
{
	t_stack	*aux;

	if (!first)
		return ;
	if (!(*first) || !(*first)->next)
		return ;
	if ((*first)->next)
	{
		if (!((*first)->next->next))
			swap (first);
		else
		{
			aux = node_dup(lstlast(*first));
			stackadd_front(first, aux);
			aux = lstlast(*first);
			aux->prev->next = NULL;
			free(aux);
		}
	}
}
