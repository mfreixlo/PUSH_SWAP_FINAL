/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap_utils2.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mfreixo- <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/18 18:24:08 by mfreixo-		  #+#	#+#			 */
/*   Updated: 2022/03/23 16:56:58 by mfreixo-         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/*determina qual o algarismo na posicao pos, a posicao 1 e o ultimo algarismo*/
int	alg_pos(int nbr, int pos)
{
	pos -= 1;
	while (pos--)
		nbr /= 10;
	return (nbr % 10);
}

int	**ini_matrix(int value, int row, int col)
{
	int	**matrix;
	int	i;
	int	j;

	i = 0;
	j = 0;
	matrix = malloc(sizeof(int *) * (row + 1));
	while (i < row)
	{
		j = 0;
		matrix[i] = (int *)malloc(sizeof(int) * (col + 1));
		while (j < col)
			matrix[i][j++] = value;
		i++;
	}
	return (matrix);
}

int	*ini_lst(t_stack *first, int size)
{
	int	*lst;
	int	i;

	i = 0;
	lst = malloc(sizeof(int) * (size + 1));
	while (i <= size && first)
	{
		lst[i] = first->pos;
		i++;
		first = first->next;
	}
	return (lst);
}

void	mat_to_lst(int **mat, int*lst, int row, int col)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	j = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (mat[i][j] != -1)
			{
				lst[k++] = mat[i][j++];
				continue ;
			}
			j++;
		}
		i++;
	}
}

void	lst_to_mat(int **mat, int*lst, int lst_size, int pos)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (k < lst_size)
	{
		i = 0;
		while (mat[alg_pos(lst[k], pos)][i] != -1)
			i++;
		mat[alg_pos(lst[k], pos)][i] = lst[k];
		k++;
	}
}
