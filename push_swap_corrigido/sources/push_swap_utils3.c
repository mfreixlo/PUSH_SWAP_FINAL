/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfreixo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:24:43 by mfreixo-          #+#    #+#             */
/*   Updated: 2022/03/26 11:31:01 by mfreixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	mat_lst_clear(int **mat, int *t_stack, int row)
{
	int	i;

	if (t_stack)
		free(t_stack);
	i = 0;
	while (i < row)
	{
		if (mat[i])
			free(mat[i]);
		i++;
	}
	if (mat)
		free(mat);
}

//preencher todas as entradas da matriz "mat" com o valor "value"
void	change_mat(int **mat, int row, int col, int value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			mat[i][j++] = value;
		}
		i++;
	}
}

/*modificar os valores da stack para numeros seguidos, correspondentes*/
void	change_lst(t_stack **first, int *lstnbr, int size)
{
	t_stack	*aux;
	int		i;

	aux = *first;
	while (aux)
	{
		i = 0;
		while (i < size)
		{
			if (aux->pos == lstnbr[i])
			{
				aux->pos = i;
				break ;
			}
			i++;
		}
		aux = aux->next;
	}
}

void	set_lst(t_stack **first)
{
	int	size;
	int	**matrix;
	int	*lstnbr;
	int	n;

	size = lstsize(*first);
	lstnbr = ini_lst(*first, size);
	matrix = ini_matrix(-1, 10, size);
	n = 1;
	while (n < 10)
	{
		lst_to_mat(matrix, lstnbr, size, n);
		mat_to_lst(matrix, lstnbr, 10, size);
		change_mat(matrix, 10, size, -1);
		n++;
	}
	change_lst(first, lstnbr, size);
	mat_lst_clear(matrix, lstnbr, 10);
}

void	chunk_lim(int j, int *min, int *max, int height)
{
	int	n;

	if (height > 100)
		n = 11;
	else
		n = 5;
	*min = j * (height / n);
	if (j == n - 1)
		*max = height - 1;
	else
		*max = *min + height / n - 1;
}
