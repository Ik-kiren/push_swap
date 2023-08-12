/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:52:03 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/12 10:19:50 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_printf("ra\n");
}

void	rb(t_pile **pile_b)
{
	rotate(pile_b);
	ft_printf("rb\n");
}

void	rr(t_pile **pile_a, t_pile **pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
	ft_printf("rr\n");
}
