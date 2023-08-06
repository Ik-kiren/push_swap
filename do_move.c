#include "push_swap.h"

void	rrotate_both(t_pile **pile_a, t_pile **pile_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(pile_a, pile_b);
	}
}

void	rotate_both(t_pile **pile_a, t_pile **pile_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(pile_a, pile_b);
	}
}

void	rotate_pile_a(t_pile **pile_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(pile_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(pile_a);
			(*cost)++;
		}
	}
}

void rotate_pile_b(t_pile **pile_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(pile_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(pile_b);
			(*cost)++;
		}
	}
}

void	do_move(t_pile **pile_a, t_pile **pile_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rrotate_both(pile_a, pile_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(pile_a, pile_b, &cost_a, &cost_b);
	rotate_pile_a(pile_a, &cost_a);
	rotate_pile_b(pile_b, &cost_b);
	pa(pile_b, pile_a);
}
