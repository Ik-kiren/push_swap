#include "push_swap.h"

void	rotate(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*last;

	last = get_pile_bottom(*pile);
	tmp = *pile;
	*pile = (*pile)->next;
	last->next = tmp;
	last->next->next = NULL;
}

void	ra(t_pile **pile_a)
{
	rotate(pile_a);
	printf("ra\n");
}

void	rb(t_pile **pile_b)
{
	rotate(pile_b);
	printf("rb\n");
}

void	rr(t_pile **pile_a, t_pile **pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
	printf("rr\n");
}
