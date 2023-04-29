#ifndef LIST_H_
    #define LIST_H_

typedef struct list_s {
    int number;
    struct list_s *next;
    struct list_s *prev;
} list_t;

int display_list(list_t *head);
int display_list_rev(list_t *head);
list_t *create_head(list_t *head);
list_t *create_node_back(list_t *head, int nb);
list_t *create_node_front(list_t *head, int nb);
list_t *delete_node_back(list_t *head);
list_t *delete_node_front(list_t *head);
list_t *delete_node_here(list_t *head, list_t *element);
int delete_list(list_t *head);

#endif /* !LIST_H_ */
