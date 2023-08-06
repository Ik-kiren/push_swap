#include "push_swap.h"

int	is_sorted(t_pile *pile)
{
	while (pile->next)
	{
		if (pile->nbr > pile->next->nbr)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int	find_highest(t_pile *pile)
{
	int	index;

	index = pile->index;
	while (pile)
	{
		if (pile->index > index)
			index = pile->index;
		pile = pile->next;
	}
	return (index);
}

void	three_sort(t_pile **pile)
{
	int	highest;

	if (is_sorted(*pile))
		return ;
	highest = find_highest(*pile);
	if ((*pile)->index == highest)
		ra(pile);
	else if ((*pile)->next->index == highest)
		rra(pile);
	if ((*pile)->index > (*pile)->next->index)
		sa(pile);
}

void	sort(t_pile **pile_a, t_pile **pile_b, int size)
{
	if (size == 2 && !is_sorted(*pile_a))
		sa(pile_a);
	if (size == 3)
		three_sort(pile_a);
	if (size > 3 && !is_sorted(*pile_a))
		big_sort(pile_a, pile_b, size);
}
