#ifndef PUSH_SWAP_H
# define    PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_pile
{
	int				nbr;
	int				index;
	struct s_pile	*next;
}				t_pile;

//instructions.c
void	push(t_pile **src, t_pile **dest);
void	rotate(t_pile **pile);
void	rrotate(t_pile **pile);
void	swap(t_pile **pile);

// pile.c
void	print_pile(t_pile *pile);
t_pile	*get_pile_bottom(t_pile *pile);
t_pile	*get_pile_bbottom(t_pile *pile);
void	add_bottom_pile(t_pile *pile_a, t_pile *new);
t_pile	*init_pile(int nbr);
t_pile	*fill_pile(int argc, char **argv);

#endif