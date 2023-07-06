#include <stdio.h>
#include <stdlib.h>

typedef struct s_pile
{
    int nbr;
    struct s_pile *next;
}       t_pile;
