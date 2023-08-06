/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:52:06 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/06 18:09:04 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_printf("rra\n");
}

void	rrb(t_pile **pile_b)
{
	rrotate(pile_b);
	ft_printf("rrb\n");
}

void	rrr(t_pile **pile_a, t_pile **pile_b)
{
	rrotate(pile_a);
	rrotate(pile_b);
	ft_printf("rra\n");
}
