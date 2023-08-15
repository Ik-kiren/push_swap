/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 23:08:58 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/15 23:12:54 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	drr(t_pile **pile_a, t_pile **pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
}

void	drrr(t_pile **pile_a, t_pile **pile_b)
{
	rrotate(pile_a);
	rrotate(pile_b);
}

void	dss(t_pile **pile_a, t_pile **pile_b)
{
	swap(pile_a);
	swap(pile_b);
}
