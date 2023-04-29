#include <stdlib.h>
#include "list.h"

int create_head(list_t **head)
{
    if (head == NULL || *head != NULL)
        return 84;
    *head = malloc(sizeof(list_t));
    if (*head == NULL)
        return 84;
    (*head)->next = *head;
    (*head)->prev = *head;
    return 0;
}

int create_node_back(list_t **head, int nb)
{
    list_t *node = NULL;

    if (head == NULL || *head == NULL)
        return 84;
    node = malloc(sizeof(list_t));
    if (node == NULL)
        return 84;
    node->number = nb;
    node->next = *head;
    node->prev = (*head)->prev;
    (*head)->prev->next = node;
    (*head)->prev = node;
    return 0;
}

int create_node_front(list_t **head, int nb)
{
    list_t *node = NULL;

    if (head == NULL || *head == NULL)
        return 84;
    node = malloc(sizeof(list_t));
    if (node == NULL)
        return 84;
    node->number = nb;
    node->next = (*head)->next;
    node->prev = *head;
    (*head)->next->prev = node;
    (*head)->next = node;
    return 0;
}
