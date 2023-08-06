#include "push_swap.h"

void	get_position(t_pile **pile)
{
	t_pile	*tmp;
	int		i;

	tmp = *pile;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_target(t_pile **pile_a, int b_idx, int target_idx, int target_pos)
{
	t_pile	*tmp_a;

	tmp_a = *pile_a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *pile_a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	get_target_position(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp_b;
	int		target_pos;

	tmp_b = *pile_b;
	get_position(pile_a);
	get_position(pile_b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(pile_a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
