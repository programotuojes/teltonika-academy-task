//#include "library.h"
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <pthread.h>
//#include <string.h>
//
//typedef struct node {
//    void *item;
//    size_t value_size;
//    struct node *next;
//} node_t;
//
//typedef struct linked_list {
//
//} linked_list;
//
//node_t *first = NULL;
//pthread_mutex_t linked_list_lock = PTHREAD_MUTEX_INITIALIZER;
//
//
//void push(void *p_item, size_t value_size) {
//    pthread_mutex_lock(&linked_list_lock);
//
//    node_t *new_node = (node_t *) malloc(sizeof(node_t));
//    new_node->item = malloc(value_size);
//    memcpy(new_node->item, p_item, value_size);
////    new_node->item = item;
//    new_node->value_size = value_size;
//
//    if (first == NULL) {
//        first = new_node;
//
//        pthread_mutex_unlock(&linked_list_lock);
//        return;
//    }
//
//    node_t *current = first;
//
//    while (current->next != NULL)
//        current = current->next;
//
//    current->next = new_node;
//
//    pthread_mutex_unlock(&linked_list_lock);
//}
//
//void pop(void *buffer) {
//    pthread_mutex_lock(&linked_list_lock);
//
//    void *popped = NULL;
//
//    // Empty
//    if (first == NULL) {
//        buffer = NULL;
//
//        pthread_mutex_unlock(&linked_list_lock);
//        return;
//    }
//
//    // One element
//    if (first->next == NULL) {
//        memcpy(buffer, first->item, first->value_size);
////        popped = first->item;
////        first = NULL;
//        free(first->item);
//        free(first);
//
//        pthread_mutex_unlock(&linked_list_lock);
//        return;
//    }
//
//    // Two and more
//    node_t *current = first;
//
//    while (current->next->next != NULL)
//        current = current->next;
//
////    popped = current->next->item;
////    current->next = NULL;
//    memcpy(buffer, current->next->item, current->next->value_size);
//    free(current->next->item);
//    free(current->next);
//
//    pthread_mutex_unlock(&linked_list_lock);
//}
//
//int main() {
//    printf("Hello world\n");
//
//    int test1 = 699;
//    float test2 = 5.0f;
//    double test3 = 99.9;
//    char *test4 = "pls";
//
//    push(&test1, sizeof(test1));
//    push(&test2, sizeof(test2));
//    push(&test3, sizeof(test3));
//    push(&test4, strlen(test4));
//
//    char pop_test4[10];
//    pop(pop_test4);
//
//    double pop_test3;
//    pop(&pop_test3);
//
//    float pop_test2;
//    pop(&pop_test2);
//
//    int pop_test1;
//    pop(&pop_test1);
//
//    printf("%i\n", pop_test1);
//    printf("%f\n", pop_test2);
//    printf("%f\n", pop_test3);
//    printf("%s\n", pop_test4);
//
//    return 0;
//}
