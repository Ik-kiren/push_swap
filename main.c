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

int main(int argc, char **argv)
{
    t_pile *pile_a;
    t_pile *pile_b;

    if (argc == 1)
    {
        printf("error\n");
        return 0;
    }
    pile_a = fill_pile(argc, argv);
    pile_b = init_pile(9);
    assign_index(pile_a, 5);
    print_pile(pile_a);
    printf("\n");
    print_pile(pile_b);
    printf("\n");
    return 0;
}
