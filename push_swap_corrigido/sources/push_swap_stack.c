/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap_stack.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mfreixo- <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/18 17:25:11 by mfreixo-		  #+#	#+#			 */
/*   Updated: 2022/03/26 15:31:22 by mfreixo-         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	lstadd_aux(t_stack **first, char **str)
{
	long int	num;

	num = chartonbr(str);
	if (num > 2147483647 || num < -2147483648)
	{
		return (0);
	}
	else
	{
		lstadd(first, num);
		return (1);
	}
}

int	create_stack(t_stack **first, char *str)
{
	while (*str)
	{
		while ((*str) && ft_isspace(*str))
			str++;
		if ((*str) && ischar(*str))
			return (0);
		else if (*str == '-' || *str == '+')
		{
			if (*(str + 1) && ft_isdigit(*(str + 1)))
			{
				if (lstadd_aux(first, &str))
					continue ;
				if (!lstadd_aux(first, &str))
					return (0);
			}
			else
				return (0);
		}
		else if (ft_isdigit(*str))
		{
			if (!lstadd_aux(first, &str))
				return (0);
		}
	}
	return (1);
}

void	check_stack(t_stack **first)
{
	int		*array;
	int		min;
	int		max;
	t_stack	*aux;

	min = lstmin(*first);
	max = lstmax(*first);
	array = malloc(sizeof(int) * (max - min + 1));
	aux = *first;
	while (aux)
	{
		aux->pos = aux->value + (-1 * min);
		aux = aux->next;
	}
	aux = *first;
	while (aux)
	{
		if (++array[aux->pos] > 1)
			lstclear(first);
		if (array[aux->pos] > 1)
			return ;
		aux = aux->next;
	}
	set_lst(first);
	free(array);
}

void	stackadd_front(t_stack **first, t_stack *new)
{
	if (!first)
		return ;
	if (!(*first))
		*first = new;
	else
	{
		(*first)->prev = new;
		new->next = (*first);
		new->prev = NULL;
		*first = new;
	}
}

void	stackadd_back(t_stack **first, t_stack *new)
{
	t_stack	*last;

	if (!first)
		return ;
	if (!(*first))
		*first = new;
	else
	{
		last = lstlast(*first);
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}
