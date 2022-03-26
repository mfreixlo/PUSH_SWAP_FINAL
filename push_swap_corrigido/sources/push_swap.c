/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfreixo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:01:45 by mfreixo-          #+#    #+#             */
/*   Updated: 2022/03/26 11:39:52 by mfreixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	print_erro(t_stack **first)
{
	lstclear(first);
	ft_putstr_fd("Erro\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*first_a;
	int		n;

	if (argc == 1)
		return (0);
	first_a = NULL;
	i = 1;
	n = 1;
	while (n != 0 && i < argc)
		n = create_stack(&first_a, argv[i++]);
	if (n == 0)
		return (print_erro(&first_a));
	if (first_a)
		check_stack(&first_a);
	if (first_a)
	{
		order(&first_a);
		lstclear(&first_a);
	}
	else if (!first_a)
		return (print_erro(&first_a));
	return (0);
}
