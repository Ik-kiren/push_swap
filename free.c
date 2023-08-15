/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:35:28 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/15 17:36:03 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_tab(char **tab)
{
	int	i;

	i = 1;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
