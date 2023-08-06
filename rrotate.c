#include "push_swap.h"

void	rrotate(t_pile **pile)
{
	t_pile	*last;
	t_pile	*tmp;
	t_pile	*before;

	last = get_pile_bottom(*pile);
	before = get_pile_bbottom(*pile);
	tmp = *pile;
	*pile = last;
	(*pile)->next = tmp;
	before->next = NULL;
}

void	rra(t_pile **pile_a)
{
	rrotate(pile_a);
	printf("rra\n");
}

void	rrb(t_pile **pile_b)
{
	rrotate(pile_b);
	printf("rrb\n");
}

void	rrr(t_pile **pile_a, t_pile **pile_b)
{
	rrotate(pile_a);
	rrotate(pile_b);
	printf("rra\n");
}
