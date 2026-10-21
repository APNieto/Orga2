#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>



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


typedef struct linked_list {
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

size_t get_size_of_linked_list(linked_list *list){
    return list->size;
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
        printf("* * *Attempted to print linked list, but it is empty.* * *\n");
    size_t i = 1;
    printf("- - - - - -Start of linked list- - - - - -\n");
    while (node != NULL) {
        printf("---Position %zu\n", i);
        printf("Address %p\n", (void *)node);
        printf("Value %d\n", *(int *)(node->data));
        node = node->next;
        i++;
    }
    printf("- - - - - -End of linked list- - - - - -\n");
}


node *append_int_node(int data, linked_list* list) {
    // A: save data in a new location in the heap
    int *new_int_pointer = malloc(sizeof(int));
    *new_int_pointer = data;
    // B: Create new node
    node *new_node = malloc(sizeof(node));
    new_node->data = new_int_pointer;
    new_node->next = NULL;
    // C: find last node, whose 'next' member points to NULL
    node *last_node = find_last_node(list);
    // D: replace this last node's 'next' with the pointer generated in B
    list->size++;
    if (last_node == NULL) {
        list->first_node = new_node;
        return new_node;
    }    
    last_node->next = new_node;
    return new_node;
}


node *insert_node(linked_list *list, int value, size_t position){
    // A: create new node
    int *new_data = malloc(sizeof(int));
    *new_data = value;
    node *new_node = malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = NULL;

    // B1: insert at position one
    if (position == 1) {
        if (list->first_node != NULL)
            new_node->next = list->first_node;
        list->first_node = new_node;
        list->size++;
        return new_node;
    }

    // B2: insert at any other position
    if (list->first_node == NULL)
        return NULL;
    node *current_node = list->first_node;
    for (int i = 1; i < position + 1; i++) {
        if (i == position - 1) {
            new_node->next = current_node->next;
            current_node->next = new_node;
        } else {
            current_node = current_node->next;
        }
    }
    list->size++;
    return new_node;
}


void delete_linked_list(linked_list* lista){

    if (lista->first_node != NULL) {
        node *current_node = lista->first_node;
        node *next_node = current_node->next;
        while(next_node != NULL) {
            free(current_node);
            current_node = next_node;
            next_node = current_node->next;
        }
        free(current_node);
    }
    free(lista);

}


int get_int_node(linked_list *list, size_t position){

    // if (list->first_node == NULL)
    //     return NULL;
    if (position == 1)
        return *(int *)(list->first_node->data);
    
    node *temp_node = list->first_node;
    for (size_t i = 1; i < position + 1; i++) {
        if (i == position) {
            return *(int *)(temp_node->data);
        }
        temp_node = temp_node->next;
    }

}


int remove_int_node(linked_list *list, size_t position){

    // Removes item at the given position and returns it.
    // Assumes the given linked list is non-empty.
    
    if (position == 1){
        node *node_to_remove = list->first_node;
        list->first_node = list->first_node->next;
        int removed_value = *(int *)(node_to_remove->data);
        free(node_to_remove);
        return removed_value;
    }

    node *i_node = list->first_node;
    for (size_t i = 1; i < position; i++) {
        if (i == position - 1){
            node *node_to_remove = i_node->next;
            i_node->next = i_node->next->next;
            int removed_value = *(int *)(node_to_remove->data);
            free(node_to_remove);
            list->size--;
            return removed_value;
        }
        i_node = i_node->next;
    }

}


size_t find_int_item(linked_list *list, int value) {

    // Returns position of searched value in the given 1-indexed linked list.
    // If value is not found, a zero is returned.
    // Assumes the list is non-empty.

    node *current_node = list->first_node;
    size_t size_list = list->size;
    int value_in_node;
    for(size_t i = 1; i < size_list + 1; i++){
        value_in_node = *(int *)(current_node->data);
        if(value_in_node == value)
            return i;        
        current_node = current_node->next;
    }
    return 0;

}


void swap_positions(linked_list *l, uint8_t pos1, uint8_t pos2) {

    // Swaps the nodes in positions pos1 and pos2 of the linked list in l

    if (l->first_node == NULL)
        return;
    if (l->first_node->next == NULL)
        return;
    
    node *tmp_pos1 = NULL;
    node *tmp_pos2 = NULL;
    node *prior_to_pos1 = NULL;
    node *prior_to_pos2 = NULL;
    node *tmp_node = l->first_node;

    // Get a hold of the nodes prior to the ones to be swapped
    for (uint8_t i = 1; i < pos2; i++){
        if (i == pos1 - 1)
            prior_to_pos1 = tmp_node;
        else if (i == pos2 - 1)
            prior_to_pos2 = tmp_node;
        tmp_node = tmp_node->next;
    }
    // Get a hold of the nodes to be swapped
    tmp_pos1 = prior_to_pos1->next;
    tmp_pos2 = prior_to_pos2->next;

    // Save the next of node pos2
    node *tmp_next = tmp_pos2->next;

    // Assign to pos2 the next of pos1
    tmp_pos2->next = tmp_pos1->next;

    // Make prior of pos1 point to pos2
    prior_to_pos1->next = tmp_pos2;

    // Repeat with node po1
    tmp_pos1->next = tmp_next;
    prior_to_pos2->next = tmp_pos1;


}



//////////////////////////////////////////////////////////

int main(){

    linked_list *lista = create_linked_list(TYPE_INT);
    printf("Linked list created in address %p\n", lista);
    printf("\n");
    
    // Appends
    append_int_node(10, lista);
    printf("Appended one node.\n");
    append_int_node(20, lista);
    printf("Appended one node.\n");
    append_int_node(30, lista);
    printf("Appended one node.\n");
    append_int_node(40, lista);
    printf("Appended one node.\n");
    append_int_node(50, lista);
    printf("Appended one node.\n");
    printf("Size of lista: %zu\n", get_size_of_linked_list(lista));
    
    print_linked_list(lista);
    printf("\n");
    
    // Swaps position 2 with 4; prints
    printf("Swapped positions 2 and 4.\n");
    swap_positions(lista, 2, 4);
    print_linked_list(lista);
    printf("\n");
    
}


