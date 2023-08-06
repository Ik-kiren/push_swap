/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:51:56 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/06 18:34:11 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf/ft_printf.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_pile
{
	int				nbr;
	int				index;
	int				position;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_pile	*next;
}				t_pile;

//instructions
void		pa(t_pile **pile_b, t_pile **pile_a);
void		pb(t_pile **pile_a, t_pile **pile_b);
void		sa(t_pile **pile_a);
void		sb(t_pile **pile_b);
void		ss(t_pile **pile_a, t_pile **pile_b);
void		ra(t_pile **pile_a);
void		rb(t_pile **pile_b);
void		rr(t_pile **pile_a, t_pile **pile_b);
void		rra(t_pile **pile_a);
void		rrb(t_pile **pile_b);
void		rrr(t_pile **pile_a, t_pile **pile_b);

// pile
int			get_pile_size(t_pile *pile);
t_pile		*get_pile_bottom(t_pile *pile);
void		add_bottom_pile(t_pile *pile_a, t_pile *new);
t_pile		*init_pile(int nbr);
t_pile		*fill_pile(int argc, char **argv);
int			is_sorted(t_pile *pile);
void		sort(t_pile **pile_a, t_pile **pile_b, int size);
void		three_sort(t_pile **pile);
void		big_sort(t_pile **pile_a, t_pile **pile_b, int size);
void		get_target_position(t_pile **pile_a, t_pile **pile_b);
void		get_position(t_pile **pile);
int			get_lowest_index(t_pile **pile);
void		do_move(t_pile **pile_a, t_pile **pile_b, int cost_a, int cost_b);
int			verifs(char **argv);

//utils
void		print_pile(t_pile *pile);
int			nb_abs(int nb);
long int	ft_atoi(const char *str);
void		shift_stack(t_pile **pile);

#endif