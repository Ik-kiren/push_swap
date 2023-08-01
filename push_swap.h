#ifndef PUSH_SWAP_H
# define    PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

#define INT_MAX 2147483647

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

//instructions.c
void	push(t_pile **src, t_pile **dest);
void	rotate(t_pile **pile);
void	rrotate(t_pile **pile);
void	swap(t_pile **pile);

// pile.c
void	print_pile(t_pile *pile);
int get_pile_size(t_pile *pile)
t_pile	*get_pile_bottom(t_pile *pile);
t_pile	*get_pile_bbottom(t_pile *pile);
void	add_bottom_pile(t_pile *pile_a, t_pile *new);
t_pile	*init_pile(int nbr);
t_pile	*fill_pile(int argc, char **argv);
void sort(t_pile **pile_a, t_pile **pile_b, int size);
void three_sort(t_pile **pile);
void big_sort(t_pile **pile_a, t_pile **pile_b, int size);
void get_target_position(t_pile **pile_a, t_pile **pile_b);
void do_move(t_pile **pile_a, t_pile **pile_b, int cost_a, int cost_b);

#endif