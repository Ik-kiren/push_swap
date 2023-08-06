/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:52:11 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/06 18:09:15 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_printf("sa\n");
}

void	sb(t_pile **pile_b)
{
	swap(pile_b);
	ft_printf("sb\n");
}

void	ss(t_pile **pile_a, t_pile **pile_b)
{
	swap(pile_a);
	swap(pile_b);
	ft_printf("ss\n");
}
