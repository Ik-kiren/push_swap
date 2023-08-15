/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:28:36 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/15 23:14:30 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "push_swap.h"

void	push(t_pile **src, t_pile **dest);
void	rotate(t_pile **pile);
void	rrotate(t_pile **pile);
void	swap(t_pile **pile);
void	drr(t_pile **pile_a, t_pile **pile_b);
void	drrr(t_pile **pile_a, t_pile **pile_b);
void	dss(t_pile **pile_a, t_pile **pile_b);