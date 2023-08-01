#include "push_swap.h"

void rrotate_both(t_pile **pile_a, t_pile **pile_b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        (*cost_a)++;
        (*cost_b)++;
        rrotate(pile_a);
        rrotate(pile_b);
    }
    
}

void rotate_both(t_pile **pile_a, t_pile **pile_b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        (*cost_a)--;
        (*cost_b)--;
        rotate(pile_a);
        rotate(pile_b);
    }
    
}

void rotate_pile(t_pile **pile, int *cost)
{
    while (*cost)
    {
        if(*cost > 0)
        {
            rotate(pile);
            (*cost)--;
        }
        else if(*cost < 0)
        {
            rrotate(pile);
            (*cost)++;
        }
    }
    
}

void do_move(t_pile **pile_a, t_pile **pile_b, int cost_a, int cost_b)
{
    if (cost_a < 0 && cost_b < 0)
        rrotate_both(pile_a, pile_b, &cost_a, &cost_b);
    else if (cost_a > 0 && cost_b > 0)
        rotate_both(pile_a, pile_b, &cost_a, &cost_b);
    rotate_pile(pile_a, &cost_a);
    rotate_pile(pile_b, &cost_b);
    push(pile_b, pile_a);
}