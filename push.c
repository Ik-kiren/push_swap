#include "push_swap.h"

void	push(t_pile **src, t_pile **dest)
{
	t_pile	*tmp;

	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	pa(t_pile **pile_b, t_pile **pile_a)
{
	push(pile_b, pile_a);
	printf("pa\n");
}

void	pb(t_pile **pile_a, t_pile **pile_b)
{
	push(pile_a, pile_b);
	printf("pb\n");
}
