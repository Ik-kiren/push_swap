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
				//ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

int get_pile_size(t_pile *pile)
{
	int size;

	size = 0;
	while (pile)
	{
		size++;
		pile = pile->next;
	}
	return(size);
}

int main(int argc, char **argv)
{
    t_pile *pile_a;
    t_pile *pile_b;
	int size;

    if (argc == 1)
    {
        printf("error\n");
        return 0;
    }
    pile_a = fill_pile(argc, argv);
    pile_b = NULL;
	size = get_pile_size(pile_a);
    assign_index(pile_a, size);
	sort(&pile_a, &pile_b, size);
    print_pile(pile_a);
    printf("\n");
    //print_pile(pile_b);
    //("\n");
    return 0;
}
