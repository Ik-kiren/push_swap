#include "push_swap.h"

void	print_pile(t_pile *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		printf("%d ", pile->nbr);
		printf("%d ", pile->index);
		printf("%d ", pile->position);
		printf("%d\n", pile->target_pos);
		pile = pile->next;
		i++;
	}
}

t_pile	*get_pile_bottom(t_pile *pile)
{
	while (pile && pile->next != NULL)
	{
		pile = pile->next;
	}
	return (pile);
}

t_pile	*get_pile_bbottom(t_pile *pile)
{
	while (pile && pile->next->next != NULL)
	{
		pile = pile->next;
	}
	return (pile);
}

void	add_bottom_pile(t_pile *pile_a, t_pile *new)
{
	t_pile	*bottom;

	bottom = get_pile_bottom(pile_a);
	bottom->next = new;
}

t_pile	*init_pile(int nbr)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	new->nbr = nbr;
	return (new);
}

t_pile	*fill_pile(int argc, char **argv)
{
	t_pile	*pile_a;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (i == 1)
		{
			pile_a = init_pile(atoi(argv[i]));
		}
		else
		{
			add_bottom_pile(pile_a, init_pile(atoi(argv[i])));
		}
		i++;
	}
	return (pile_a);
}