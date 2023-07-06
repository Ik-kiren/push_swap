#include "push_swap.h"

void print_pile(t_pile *pile)
{
    int i;

    i = 0;
    while (pile)
    {
        printf("%d", pile->nbr);
        pile = pile->next;
        i++;
    }
}

t_pile *get_pile_bottom(t_pile *pile)
{
    while (pile && pile->next != NULL)
    {
        pile = pile->next;
    }
    return pile;
    
}

void add_bottom_pile(t_pile *pile_a, t_pile *new)
{
    t_pile *bottom;
    bottom = get_pile_bottom(pile_a);
    bottom->next = new;
}

t_pile *init_pile(int nbr)
{
    t_pile *new;

    new = malloc(sizeof(t_pile));
    new->nbr = nbr;
    return new;
}

t_pile *fill_pile(int argc, char **argv)
{
    t_pile *pile_a;
    int i;

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
    return pile_a;
}

void push(t_pile **src, t_pile **dest)
{
    t_pile *tmp;

    tmp = (*src)->next;
    (*src)->next = *dest;
    *dest = *src;
    *src = tmp;
}

void rotate(t_pile **pile)
{
    t_pile *tmp;
    t_pile *last;

    last = get_pile_bottom(*pile);
    tmp = *pile;
    *pile = (*pile)->next;
    last->next = tmp;
    last->next->next = NULL;
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
    rotate(&pile_a);
    /*print_pile(pile_a);
    printf("\n");
    print_pile(pile_b);
    printf("\n");*/

    return 0;
}
