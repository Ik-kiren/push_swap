/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:58:01 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/06 18:31:10 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(const char *str)
{
	long int	res;
	long int	i;
	long int	n;

	res = 0;
	i = 0;
	n = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == '\r')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n = n * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * n);
}

int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	print_pile(t_pile *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		ft_printf("%d\n", pile->nbr);
		pile = pile->next;
		i++;
	}
}

void	shift_stack(t_pile **pile)
{
	int	lowest_pos;
	int	size;

	size = get_pile_size(*pile);
	lowest_pos = get_lowest_index(pile);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rra(pile);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(pile);
			lowest_pos--;
		}
	}
}
