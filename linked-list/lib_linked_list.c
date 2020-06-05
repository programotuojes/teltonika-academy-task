#include "lib_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void init(linked_list *list) {
    list->first = NULL;
    list->length = 0;
//    list->linked_list_lock = PTHREAD_MUTEX_INITIALIZER;
}

void push(linked_list *list, int value) {
    pthread_mutex_lock(&list->linked_list_lock);

    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->item = value;

    if (list->first == NULL) {
        list->first = new_node;

        pthread_mutex_unlock(&list->linked_list_lock);
        list->length++;
        return;
    }

    node_t *current = list->first;

    while (current->next != NULL)
        current = current->next;

    current->next = new_node;

    pthread_mutex_unlock(&list->linked_list_lock);
    list->length++;
}

int get(linked_list *list, int index) {
    if (index > list->length)
        abort();

//    for (node_t *current = list->first; current->next != NULL; current = current->next)

//    node_t *current = list->first;
//    for (int i = 0; i < index; i++, current = current->next) {
//        while (current->next != NULL)
//
//
//    }
}

int main() {
    printf("Hello world\n");
}
