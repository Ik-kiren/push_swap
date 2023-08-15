/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:28:28 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/15 23:29:17 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_pile *pile)
{
	while (pile->next)
	{
		if (pile->nbr > pile->next->nbr)
			return (0);
		pile = pile->next;
	}
	return (1);
}

void	do_instructions(char *tab, t_pile **pile_a, t_pile **pile_b)
{
	if (tab[0] == 'p' && tab[1] == 'a')
		push(pile_b, pile_a);
	else if (tab[0] == 'p' && tab[1] == 'b')
		push(pile_a, pile_b);
	else if (tab[0] == 'r' && tab[1] == 'a')
		rotate(pile_a);
	else if (tab[0] == 'r' && tab[1] == 'b')
		rotate(pile_b);
	else if (tab[0] == 'r' && tab[1] == 'r' && tab[2] == '\n')
		drr(pile_a, pile_b);
	else if (tab[0] == 'r' && tab[1] == 'r' && tab[2] == 'a')
		rrotate(pile_a);
	else if (tab[0] == 'r' && tab[1] == 'r' && tab[2] == 'b')
		rrotate(pile_b);
	else if (tab[0] == 'r' && tab[1] == 'r' && tab[2] == 'r')
		drrr(pile_a, pile_b);
	else if (tab[0] == 's' && tab[1] == 'a')
		swap(pile_a);
	else if (tab[0] == 's' && tab[1] == 'b')
		swap(pile_b);
	else if (tab[0] == 's' && tab[1] == 's')
		dss(pile_a, pile_b);
	else
		ft_error(NULL, 0);
}

char	*do_check(char *tab, t_pile **pile_a, t_pile **pile_b)
{
	do_instructions(tab, pile_a, pile_b);
	free(tab);
	tab = get_next_line(0);
	return (tab);
}

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	char	*tab;

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (argc == 1)
		return (0);
	if (verifs(argv) == 0 || !argv[1])
		ft_error(argv, argc);
	pile_a = fill_pile(argv);
	pile_b = NULL;
	if (argc == 2)
		free_tab(argv);
	tab = get_next_line(0);
	while (tab != NULL)
		tab = do_check(tab, &pile_a, &pile_b);
	if (is_sorted(pile_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_pile(&pile_a);
	free_pile(&pile_b);
}
