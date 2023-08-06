/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:52:01 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/06 18:08:49 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_pile **src, t_pile **dest)
{
	t_pile	*tmp;

	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	pa(t_pile **pile_b, t_pile **pile_a)
{
	push(pile_b, pile_a);
	ft_printf("pa\n");
}

void	pb(t_pile **pile_a, t_pile **pile_b)
{
	push(pile_a, pile_b);
	ft_printf("pb\n");
}
