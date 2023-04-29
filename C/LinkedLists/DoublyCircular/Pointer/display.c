#include <stdio.h>
#include "list.h"

int display_list(list_t *head)
{
    if (head == NULL)
        return 84;
    for (list_t *temp = head->next; head != temp; temp = temp->next)
        printf("%d\n", temp->number);
    return 0;
}

int display_list_rev(list_t *head)
{
    if (head == NULL)
        return 84;
    for (list_t *temp = head->prev; head != temp; temp = temp->prev)
        printf("%d\n", temp->number);
    return 0;
}
