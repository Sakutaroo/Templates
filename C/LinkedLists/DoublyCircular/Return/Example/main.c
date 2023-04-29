#include <stdio.h>
#include "list.h"

int main(void) {
    list_t *head = NULL;

    head = create_head(head);
    head = create_node_front(head, 0);
    for (int i = 1; i < 3; i += 1)
        head = create_node_back(head, i);
    head = create_node_back(head, 9);
    for (int i = 3; i < 6; i += 1)
        head = create_node_back(head, i);
    printf("List before:\n");
    display_list(head);
    for (list_t *temp = head->next; head != temp; temp = temp->next) {
        if (temp->number == 9) {
            head = delete_node_here(head, temp);
            break;
        }
    }
    printf("List after:\n");
    display_list(head);
    delete_list(head);
    return 0;
}
