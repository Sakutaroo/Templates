#include <stdlib.h>
#include "list.h"

list_t *create_head(list_t *head)
{
    if (head != NULL)
        return head;
    head = malloc(sizeof(list_t));
    if (head == NULL)
        return head;
    head->next = head;
    head->prev = head;
    return head;
}

list_t *create_node_back(list_t *head, int nb)
{
    list_t *node = NULL;

    if (head == NULL)
        return head;
    node = malloc(sizeof(list_t));
    if (node == NULL)
        return head;
    node->number = nb;
    node->next = head;
    node->prev = head->prev;
    head->prev->next = node;
    head->prev = node;
    return head;
}

list_t *create_node_front(list_t *head, int nb)
{
    list_t *node = NULL;

    if (head == NULL)
        return head;
    node = malloc(sizeof(list_t));
    if (node == NULL)
        return head;
    node->number = nb;
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
    return head;
}
