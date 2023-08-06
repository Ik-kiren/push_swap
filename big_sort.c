/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:51:32 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/06 18:20:49 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_pile **pile_a, t_pile **pile_b, int size)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*pile_a)->index <= size / 2)
		{
			pb(pile_a, pile_b);
			pushed++;
		}
		else
			ra(pile_a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(pile_a, pile_b);
		pushed++;
	}
}

void	get_cost(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp_a;
	t_pile	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *pile_a;
	tmp_b = *pile_b;
	size_a = get_pile_size(tmp_a);
	size_b = get_pile_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->position) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	do_cheapest(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *pile_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(pile_a, pile_b, cost_a, cost_b);
}

int	get_lowest_index(t_pile **pile)
{
	t_pile	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *pile;
	lowest_index = INT_MAX;
	get_position(pile);
	lowest_pos = tmp->position;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

void	big_sort(t_pile **pile_a, t_pile **pile_b, int size)
{
	push_b(pile_a, pile_b, size);
	three_sort(pile_a);
	while (*pile_b)
	{
		get_target_position(pile_a, pile_b);
		get_cost(pile_a, pile_b);
		do_cheapest(pile_a, pile_b);
	}
	if (!is_sorted(*pile_a))
		shift_stack(pile_a);
}
