/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:51:50 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/07 15:25:35 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*get_pile_bottom(t_pile *pile)
{
	while (pile && pile->next != NULL)
		pile = pile->next;
	return (pile);
}

t_pile	*get_pile_bbottom(t_pile *pile)
{
	while (pile && pile->next->next != NULL)
		pile = pile->next;
	return (pile);
}

void	add_bottom_pile(t_pile **pile_a, t_pile *new)
{
	t_pile	*bottom;

	if (!new)
		return ;
	if (!*pile_a)
	{
		*pile_a = new;
		return ;
	}
	bottom = get_pile_bottom(*pile_a);
	bottom->next = new;
}

t_pile	*init_pile(int nbr)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index = 0;
	new->position = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_pile	*fill_pile(int argc, char **argv)
{
	t_pile	*pile_a;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (i == 1)
			pile_a = init_pile(ft_atoi(argv[i]));
		else
			add_bottom_pile(&pile_a, init_pile(atoi(argv[i])));
		i++;
	}
	return (pile_a);
}
