/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:51:44 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/12 10:50:31 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_pile *stack_a, int stack_size)
{
	t_pile	*ptr;
	t_pile	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->nbr == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->nbr > value && ptr->index == 0)
			{
				value = ptr->nbr;
				highest = ptr;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

int	get_pile_size(t_pile *pile)
{
	int	size;

	size = 0;
	while (pile)
	{
		size++;
		pile = pile->next;
	}
	return (size);
}

void	free_pile(t_pile **pile)
{
	t_pile	*tmp;

	if (!pile || !(*pile))
		return ;
	while (*pile)
	{
		tmp = (*pile)->next;
		free(*pile);
		*pile = tmp;
	}
	*pile = NULL;
}

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	int		size;

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (argc == 1)
		return (0);
	if (verifs(argv) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	pile_a = fill_pile(argv);
	pile_b = NULL;
	size = get_pile_size(pile_a);
	assign_index(pile_a, size);
	sort(&pile_a, &pile_b, size);
	free_pile(&pile_a);
	free_pile(&pile_b);
	return (0);
}
