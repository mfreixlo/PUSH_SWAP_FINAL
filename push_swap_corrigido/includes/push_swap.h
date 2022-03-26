/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfreixo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:44:20 by mfreixo-          #+#    #+#             */
/*   Updated: 2022/03/26 15:27:58 by mfreixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct t_stack
{
	int				value;
	int				pos;
	struct t_stack	*next;
	struct t_stack	*prev;
}	t_stack;

typedef struct t_lst
{
	int				value;
	struct t_lst	*next;
}	t_lst;

/*push_swap.c*/
int			main(int argc, char **argv);
int			print_erro(t_stack **first);

/*push_swap_lst.c*/
t_stack		*lstnew(int value);
t_stack		*lstlast(t_stack *first);
void		lstclear(t_stack **first);
void		lstadd(t_stack **first, int value);
int			lstsize(t_stack *first);

/*push_swap_lst2.c*/
int			lstmax(t_stack *first);
int			lstmin(t_stack *first);
int			lstmin_pos(t_stack *first);
t_stack		*node_dup(t_stack *node);
int			lstmax_pos(t_stack *first);

/*push_swap_utils.c*/
int			ischar(char c);
int			ft_isspace(char c);
long int			chartonbr(char **str);
int			find_pos(t_stack *first, int min, int max);
void		put_top(t_stack **first, int min, int max, char stack);

/*push_swap_utils2.c*/
int			alg_pos(int nbr, int pos);
int			**ini_matrix(int value, int row, int col);
int			*ini_lst(t_stack *first, int size);
void		mat_to_lst(int **mat, int*lst, int row, int col);
void		lst_to_mat(int **mat, int*lst, int lst_size, int pos);

/*push_swap_utils3.c*/
void		mat_lst_clear(int **mat, int *t_stack, int row);
void		change_mat(int **mat, int row, int col, int value);
void		change_lst(t_stack **first, int *lstnbr, int size);
void		set_lst(t_stack **first);
void		chunk_lim(int j, int *min, int *max, int height);

/*push_swap_stack.c*/
int			create_stack(t_stack **first, char *str);
void		check_stack(t_stack **first);
void		stackadd_front(t_stack **first, t_stack *new);
void		stackadd_back(t_stack **first, t_stack *new);

/*push_swap_moves.c*/
void		swap(t_stack **first);
void		push(t_stack **first_1, t_stack **first_2);
void		rotate(t_stack **first);
void		revrotate(t_stack **first);

/*push_swap_order.c*/
int			is_ordered(t_stack *first);
void		order_3(t_stack **first);
void		order_5(t_stack **first_a, t_stack **first_b);
void		order(t_stack **first_a);

void		order_x00(t_stack **first_a, t_stack **first_b, int chunk_num);

/*push_swap_print.c*/
void		print_fun(t_stack **first, char *str,
				void (*f)(t_stack **), int times);
void		print_push(t_stack **first_1, t_stack **first_2,
				int times, char stack);

#endif
