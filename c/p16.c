// Ejercicio integrador, pg.49
// Liste um Funktionen einer doppelt verketteten Liste erweitert

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>


typedef struct node_t {
  int data;
  struct node_t *next;
} node_t;

typedef struct list_t {
  node_t *first;
  node_t *last;
  uint16_t size;
} list_t;

list_t *createList(){
  list_t *newList = malloc(sizeof(list_t));
  newList->first = NULL;
  newList->last = NULL;
  newList->size = 0;
  return newList;
}

node_t *createNode(int value){
  node_t *newNode = malloc(sizeof(node_t));
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}


void appendToList(list_t *list, int value){  
  // Create new node
  node_t *newNode = createNode(value);
  
  if (!(list->first)){    // List has no first node
    list->first = newNode;
    list->last = newNode;
  } else {    // Get the last node and assign to it the new node        
    // // Simply-linked list
    // node_t *currentNode = list->first;
    // while(currentNode->next) {
    //   currentNode = currentNode->next;
    // }
    // currentNode->next = newNode;
    
    // Doubly-linked list
    list->last->next = newNode;
    list->last = newNode;
  }
  list->size++;
}


int removeFirst(list_t *list){
  node_t *firstNode;
  firstNode = list->first;
  if (!firstNode)    // -> hat höhere Präzedenz als !
    return -1;
  list->first = NULL;
  free(firstNode);
  return 0;
}


void removeList(list_t *list){
  node_t *currentNode = list->first;
  while(currentNode) {
    node_t *tmpNode = currentNode;
    currentNode->data = 0;
    currentNode = currentNode->next;
    free(tmpNode);
  }
  free(list);
}


void printList(list_t *list) {
  if(!list->first) {
    printf("Empty list. Nothing to print.\n");
    return;
  }

  node_t *tmpNode = list->first;
  printf("---Printing list---\n");
  int i = 1;
  while(tmpNode) {
    printf("Position: %d, value: %d\n", i, tmpNode->data);
    tmpNode = tmpNode->next;
    i++;
  }
}


int removeNode(list_t *list, node_t *nodeToDelete){
  // If nodeToDelete is the first one in the list
  if(list->first == nodeToDelete) {
    list->first = nodeToDelete->next;
    free(nodeToDelete);
    return 0;
  }  
  // If nodeToDelete is somewhere within the list
  node_t *tmpNode = list->first;
  node_t *prevTmpNode = list->first;
  while(tmpNode && tmpNode != nodeToDelete){
    prevTmpNode = tmpNode;
    tmpNode = tmpNode->next;
  }
  if (tmpNode == nodeToDelete) {
    prevTmpNode->next = tmpNode->next;
    free(tmpNode);
    return 0;
  }
  return -1;
}


node_t *getNode(list_t *list, uint32_t index){  
  // Returns pointer to the node in the position given in 'index'. 
  // First index position is 1 (not 0)
  node_t *tmpNode = list->first;
  for (uint32_t i = 1; i < index; i++) {
    if (!tmpNode)
      return NULL;
    tmpNode = tmpNode->next;
  }
  return tmpNode;
}


int map(list_t *list, int (* callback)(int)) {
  if(!list->first)
    return -1;
  node_t *tmpNode = list->first;
  while(tmpNode){
    tmpNode->data = callback(tmpNode->data);
    tmpNode = tmpNode->next;
  }
  return 0;
}


int mul3(int val) {
  return val * 3;
}


int add3(int val) {
  return val + 3;
}


int filter(list_t *list, int (*callback)(int)) {
  node_t *tmpNode = list->first;
  node_t *delNode;
  while (tmpNode){
    if (!callback(tmpNode->data)) {
      delNode = tmpNode;
      tmpNode = tmpNode->next;
      removeNode(list, delNode);
    } else {
      tmpNode = tmpNode->next;
    }
  }
  return 0;
}

// void zfilterGuia(list_t *list, int (*callback)(int)){
//   node_t **tmpFirst = &list->first;
//   while(*tmpFirst != NULL) {
//     if (!criterio((*tmpFirst)->data)) {
//       node_t *toErase = *tmpFirst;
//       // SEGUIR
//     }
//   }
// }



void filterGuia(list_t *list, int (*callback)(int)) {
  node_t **dir_pntr_nxt_node = &list->first;
  while (*dir_pntr_nxt_node != NULL) {
    if (!callback((*dir_pntr_nxt_node)->data)) {
      node_t *nodeToErase = *dir_pntr_nxt_node;
      (*dir_pntr_nxt_node) = (*dir_pntr_nxt_node)->next;
      free(nodeToErase);
    } else {
      dir_pntr_nxt_node = &(*dir_pntr_nxt_node)->next;
    }
  }
}



int isOdd(int value){
  return value % 2;
}



int main(){

  // Create list and append a few values
  list_t *lista = createList();
  appendToList(lista, 4);
  appendToList(lista, 6);
  appendToList(lista, 7);
  appendToList(lista, 12);
  printList(lista);

  // Call map with mul3, reprint
  map(lista, mul3);
  printf("\nCalled map with mul3 on lista. Reprinting.\n");
  printList(lista);
  
  // Call map with add3, reprint
  map(lista, add3);
  printf("\nCalled map with add3 on lista. Reprinting.\n");
  printList(lista);
  
  // // Getting and removing a node
  // printf("\nGetting 3rd node and removing it.\n");
  // node_t *node = getNode(lista, 3);
  // printf("3rd node's value: %d. Removing and reprinting.\n", node->data);
  // removeNode(lista, node);
  // printList(lista);
  
  
  // Filtering odd numbers from the list
  printf("\nFiltering even numbers from the list. Reprinting.\n");
  // filter(lista, isOdd);
  filterGuia(lista, isOdd);
  printList(lista);


  removeList(lista);
}