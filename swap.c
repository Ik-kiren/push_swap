#include "push_swap.h"

void	swap(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	t_pile	*second;

	second = (*pile)->next;
	tmp = *pile;
	tmp2 = second->next;
	*pile = second;
	second->next = tmp;
	(*pile)->next->next = tmp2;
}

void	sa(t_pile **pile_a)
{
	swap(pile_a);
	printf("sa\n");
}

void	sb(t_pile **pile_b)
{
	swap(pile_b);
	printf("sb\n");
}

void	ss(t_pile **pile_a, t_pile **pile_b)
{
	swap(pile_a);
	swap(pile_b);
	printf("ss\n");
}
