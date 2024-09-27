/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:01:48 by terussar          #+#    #+#             */
/*   Updated: 2023/05/04 17:02:06 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_pars
{
	int	nb_arg;
	int	*tab_int;
	int	*sort_tab;
}	t_pars;

typedef struct s_pile
{
	int				nb;
	int				rank;
	struct s_pile	*prev;
	struct s_pile	*next;
}	t_pile;

typedef struct s_push
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	t_pars	pars;
}	t_push;

int		check_rank(t_push	*push);
int		ft_abs(int nb);
void	*ft_error(char *str);
void	*ft_instruction(char *str);
void	swap_tab(int *a, int *b);
int		*ft_nbdup(t_pars *pars);
int		*sort_list(t_pars *pars, int first, int last);

int		check_double(t_pars *pars);
int		find_rank(int nb, t_pars *pars);
int		check_argument(char **arg, int ac, t_pars *pars);
int		*create_list_int(char **arg, int ac, t_pars *pars);

t_pile	*t_pile_new(int i, t_push *push);
int		t_pile_append(t_push *push);
void	clean(t_pile **pile);

int		create_boucle(t_push *push);
void	vizualize_a(t_push *push);
void	vizualize_b(t_push *push);
void	print_pile(t_pile *pile);
t_pile	*t_pile_new(int nbr, t_push *push);

int		ft_rotate(t_pile	**top, char *inst);
int		ft_reverse_rotate(t_pile	**top, char *inst);
int		ft_swap(t_pile	*top, char *inst);
void	erase_first(t_pile	**from);
int		ft_push(t_pile **from, t_pile **to, char *inst);
int		ft_rotate_rr(t_push *push, char *inst);
int		ft_reverse_rotate_rrr(t_push *push, char *inst);
int		ft_swap_ss(t_push *push, char *inst);

int		parsing(int i, char **av, int ac, t_push *push);
int		lenght_pile_a(t_push	*push);
int		lenght_pile_b(t_push	*push);
int		check_rank(t_push	*push);
int		max_rank_pile(t_push *push);
int		min_rank_pile(t_push *push);
int		ft_max(int a, int b);
int		*ft_min(int a, int b, int c, int d);
void	algo_3(t_push	*push);
void	algo_4(t_push *push);
void	algo_5(t_push *push);

void	first_sort(t_push *push, int nb_arg);
void	final_rotation(t_push *push, int nb_arg);
int		**move_cost(t_push *push);
int		find_min_cost(int **tab, t_push *push);
void	choose_case(t_push *push, int **tab, int index);
void	algo_100(t_push *push);

#endif