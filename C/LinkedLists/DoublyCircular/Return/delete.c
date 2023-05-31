#include <stdlib.h>
#include "list.h"

list_t *delete_node_back(list_t *head)
{
    list_t *node = NULL;

    if (head == NULL || head->prev == head)
        return head;
    node = head->prev;
    head->prev = node->prev;
    node->prev->next = head;
    free(node);
    node = NULL;
    return head;
}

list_t *delete_node_front(list_t *head)
{
    list_t *node = head->next;

    if (head == NULL || head->next == NULL)
        return head;
    node = head->next;
    head->next = node->next;
    node->next->prev = head;
    free(node);
    node = NULL;
    return head;
}

list_t *delete_node_here(list_t *head, list_t *element)
{
    list_t *node = NULL;

    if (head == NULL || element == NULL)
        return NULL;
    for (list_t *temp = head->next; head != temp; temp = temp->next) {
        if (temp == element) {
            node = temp->prev;
            node->next = element->next;
            element->next->prev = node;
            break;
        }
    }
    free(element);
    element = NULL;
    return head;
}

int delete_list(list_t *head)
{
    size_t size = 0;

    if (head == NULL)
        return 0;
    for (list_t *temp = head->next; head != temp; temp = temp->next)
        size += 1;
    for (size_t i = 0; i < size; i += 1)
        head = delete_node_back(head);
    free(head);
    head = NULL;
    return 0;
}
