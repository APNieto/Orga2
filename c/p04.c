#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// First implementation of Linked list, without looking at the examples

typedef enum {
    TYPE_INT,
    TYPE_CHAR,
    TYPE_FLOAT,
    TYPE_STRING
} type_t;


typedef struct node {
    void *data;
    struct node *next;
} node;


typedef struct l{
    type_t type;
    size_t size;
    node *first_node;
} linked_list;


linked_list *create_linked_list(type_t type) {
    linked_list *lista = malloc(sizeof(linked_list));
    lista->type = type;
    lista->size = 0;
    lista->first_node = NULL;
    return lista;
}


node *find_last_node(linked_list *list) {
    node *current_node = list->first_node;
    if (current_node == NULL)
        return NULL;
    while (current_node->next != NULL)
        current_node = current_node->next;
    return current_node;
}


void print_linked_list(linked_list *list){
    node *node = list->first_node;
    if (node == NULL)
        return;
    size_t i = 0;
    while (node != NULL) {
        printf("Position %zu\n", i);
        printf("Address %p\n", (void *)node);
        printf("Value %d\n", *(int *)(node->data));
        node = node->next;
        i++;
    }
}


node *append_int_node(int data, linked_list* list) {
    // A: save data in a new location in the heap
    node *new_node = malloc(sizeof(node));
    int *new_int_pointer = malloc(sizeof(int));
    *new_int_pointer = data;
    new_node->data = new_int_pointer;
    new_node->next = NULL;
    // B: find last node, whose 'next' member points to NULL; use another function for this
    node *last_node = find_last_node(list);
    if (last_node == NULL) {
        list->first_node = new_node;
        return new_node;
    }    
    // C: replace the last node's 'next' with the pointer generated in A
    last_node->next = new_node;
    return new_node;
}


int main(){

    linked_list *lista = create_linked_list(TYPE_INT);
    printf("Linked list on address %p\n", lista);
    append_int_node(20, lista);
    append_int_node(42, lista);
    print_linked_list(lista);

}


