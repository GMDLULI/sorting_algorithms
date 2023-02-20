#include <stdio.h>
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *i, *j;
    int value;
    for (i = *list->next; i->next != NULL; i->next)
    {
        for (j = i->next; j != NULL; j->next)
        {
            if(i->n > j->n)
            {
                value = i->n;
                i->n = j->n;
                j->n = value;
            }
        }
    }
}


   
