#include "push_swap.h"

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

void rrotate(t_pile **pile)
{
    t_pile *last;
    t_pile *tmp;
    t_pile *before;

    last = get_pile_bottom(*pile);
    before = get_pile_bbottom(*pile);
    tmp = *pile;
    *pile = last;
    (*pile)->next = tmp;
    before->next = NULL;
}

void swap(t_pile **pile)
{
    t_pile *tmp;
	t_pile *tmp2;
	t_pile *second;

	second = (*pile)->next;
	tmp = *pile;
	tmp2 = second->next;
	*pile = second;
	second->next = tmp;
	(*pile)->next->next = tmp2;
}