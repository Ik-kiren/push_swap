#include "push_swap.h"

void push_b(t_pile **pile_a, t_pile **pile_b, int size)
{
    int pushed;
    int i;

    pushed = 0;
    i = 0;
    while (size > 6 && i < size && pushed < size / 2)
    {
        if ((*pile_a)->index <= size / 2)
        {
            push(pile_a, pile_b);
            pushed++;
        }
        else
            rotate(pile_a);
        i++;
    }
    while (size - pushed > 3)
    {
        push(pile_a, pile_b);
        pushed++;
    }
    
}

void get_cost(t_pile **pile_a, t_pile **pile_b)
{
    t_pile  *tmp_a;
    t_pile  *tmp_b;
    int     size_a;
    int     size_b;

    tmp_a = *pile_a;
    tmp_b = *pile_b;
    size_a = get_pile_size(tmp_a);
    size_b = get_pile_size(tmp_b);
    while (tmp_b)
    {
        tmp_b->cost_b = tmp_b->position;
        if (tmp_b->position > size_b / 2)
            tmp_b->cost_b = (size_b - tmp_b->position) * -1;
        tmp_b->cost_a = tmp_b->target_pos;
        if (tmp_b->target_pos > size_a / 2)
            tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
        tmp_b = tmp_b->next;
    }
}

int nb_abs(int nb)
{
    if (nb < 0)
        return (nb * -1);
    return (nb);
}

void do_cheapest(t_pile **pile_a, t_pile **pile_b)
{
    t_pile *tmp;
    int cheapest;
    int cost_a;
    int cost_b;

    tmp = *pile_b;
    cheapest = INT_MAX;
    while (tmp)
    {
        if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
        {
            cheapest = nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b);
            cost_a = tmp->cost_a;
            cost_b = tmp->cost_b;
        }
        tmp = tmp->next;
    }
    do_move(pile_a, pile_b, cost_a, cost_b);
}

void big_sort(t_pile **pile_a, t_pile **pile_b, int size)
{
    push_b(pile_a, pile_b, size);
    three_sort(pile_a);
    //while (*pile_b)
    //{
        get_target_position(pile_a, pile_b);
        get_cost(pile_a, pile_b);
        do_cheapest(pile_a, pile_b);
    //}
    
}