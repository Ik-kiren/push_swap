#include "push_swap.h"
#include "limits.h"

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

int	verif_doublon(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (0);
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	verif_nbr(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j] != 45)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	verifs(char **argv)
{
	if (verif_nbr(argv) == 0)
		return (0);
	if (verif_doublon(argv) == 0)
		return (0);
	return (1);
}

void	free_pile(t_pile **pile)
{
	t_pile	*tmp;

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

	if (verifs(argv) == 0)
	{
		printf("error\n");
		return (0);
	}
	if (argc == 1)
		return (0);
	pile_a = fill_pile(argc, argv);
	pile_b = NULL;
	size = get_pile_size(pile_a);
	assign_index(pile_a, size);
	sort(&pile_a, &pile_b, size);
	print_pile(pile_a);
	free_pile(&pile_a);
	free_pile(&pile_b);
	return (0);
}
