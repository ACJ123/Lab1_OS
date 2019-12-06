// list/list.c
// 
// Implementation for linked list.
//
// Amari Jones

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t *list_alloc() {
  printf("\nCreating memory for list.");
  list_t *l = (list_t*) malloc(sizeof(list_t));
  l->head = NULL;
  return l;
}

void list_free(list_t *l) {
  printf("\nFreeing used memory.");
  node_t *current = l->head;
  if (current == NULL) {
    printf("\nNo elements to remove.");
    free(l->head);
    free(l);
    return;
  }
  // Traverse list until last node.
  node_t *temp;
  while (current != NULL) {
    temp = current;
    current = current->next;
    // Free each node from left to right, iteratively.
    free(temp);
  }
  free(l);
}

void list_print(list_t *l) {
  node_t *current;
  
  // Check if list is empty.
  if (l->head == NULL) {
    printf("\n\nList is empty.");
    return;
  }
  // Traverse list and print each element.
  current = l->head;
  printf("\nList Items");
  while (current != NULL) {
    printf("\n%d", current->value);
    current = current->next;
  }      
  printf("\nEnd of List");
}

int list_length(list_t *l) {
  node_t *current = l->head;
  // Check if the list is empty
  if (current == NULL) {
    return 0;
  }
  // If list is not empty, count from head to tail.
  int count = 0;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *current = l->head;
  node_t *new_node = (node_t*) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  
  // Add to back of list if list has elements
  if (current != NULL) {
    printf("\nAdding element to back of list.");
    while (current->next != NULL) current = current->next;
    current->next = new_node;
  }
  // List has no elements, so just add.
  else {
    l->head = new_node;
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t *current = l->head;
  node_t *new_node = (node_t*) malloc(sizeof(node_t));
  new_node->value = value;
  
  // Add to front of list if list has elements
  if (current != NULL) {
    printf("\nAdding element to front of list.");
    new_node->next = l->head;
    l->head = new_node;
  }
  // List has no elements, so just add.
  else {
    new_node->next = NULL;
    l->head = new_node;
  }
}

void list_add_at_index(list_t *l, elem value, int index) {
  node_t *previous = l->head;
  
  int count = 0;
  if ((index > list_length(l)) || (index < 0)) {
    printf("\nInvalid index.");
    return;
  }
  if (previous == NULL) {
    l->head = (node_t*) malloc(sizeof(node_t));
    l->head->value = value;
    l->head->next = NULL;
    return;
  }
  // Index must be valid.
  else {
    while ((count < index - 1) && (previous->next != NULL)) {
      previous = previous->next;
      count++;
    }
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    new_node->next = previous->next;
    new_node->value = value;
    previous->next = new_node;
  }
}

elem list_remove_from_back(list_t *l) { 
  int value;
  node_t *current = l->head;
  
  if (current == NULL) {
    printf("\nNo elements to remove.");
    return -1;
  }
  else {
    if (list_length(l) < 2) {
      l->head = NULL;
      free(current);
    }
    else {
      while (current->next->next != NULL) current = current->next;
      node_t *temp = current->next;
      current->next = NULL;
      free(temp);
    }
  }
}

elem list_remove_from_front(list_t *l) { 
  node_t *current = l->head;
  if (current == NULL) {
    printf("\nNo elements to remove.");
    return -1;
  }
  int value = current->value;
  l->head = (list_length(l) < 2) ? NULL : current->next;
  free(current);
  return value;
}

elem list_remove_at_index(list_t *l, int index) {
  node_t *current = l->head;
  node_t *temp;
  int value, count = index;
  
  if ((index > list_length(l) + 1) || (index < 1)) {
    printf("\nInvalid index.");
    return -1;
  }
  // Index must be valid.
  else {
    while (count > 1) {
      current = current->next;
      count--;
    }
    // Remove the node at specified index.
    temp = current->next;
    current->next = NULL;
    value = temp->value;
    free(temp);
    printf("\nNode removed from index %d", index);
  }
  return value;
}

bool list_is_in(list_t *l, elem value) { 
  node_t *current = l->head;
  
  while (current != NULL) {
    if (current->value == value) return true;
     current = current->next;
  }
  return false; 
}

elem list_get_elem_at(list_t *l, int index) {
  node_t *current = l->head;
  if ((index > list_length(l) - 1) || (index < 0)) {
    printf("\nInvalid index.");
    return -1;
  }
  while (current->next != NULL && index >= 0) {
    current = current->next;
    index--;
  }
  return current->value;
}

int list_get_index_of(list_t *l, elem value) {
  node_t *current = l->head;
  int index = 0;
  
  while (current != NULL) {
    if (current->value == value) return index;
     current = current->next;
    index++;
  }
  return -1; 
}