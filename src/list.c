/*
Name: Sathursan Rasatheepan
Date September 26, 2025
*/

#include <stdlib.h>
#include "list.h"
#include "mem.h"

struct list *list_new(void) {

  // allocate memory for the list struct
  struct list *list = malloc(sizeof(struct list));

  if(list == NULL) {
    return NULL;
  }

  // initialize as an empty list
  list->head = 0;
  list->current = 0;

  return list;

}

void list_start(struct list *list) {

  // set current to the head of the list
  list->current = list->head;

}

void list_next(struct list *list) {

  if(list == NULL || list->current == 0) {
    return;
  }

  // move current to the next node in the list
  list->current = get_next(list->current);

}

int list_get(struct list *list) {

  if(list == NULL || list->current == 0) {
    return 0;
  }

  // return the value of the current node
  return get_value(list->current);

}

void list_push(struct list *list, int value) {

  if(list == NULL) {
    return;
  }

  // allocate a new node
  int new_node_addr = mem_alloc(2); // 1 for value, 1 for next ptr
  if(new_node_addr == 0) {
    return;
  }

  // store the value
  set_value(new_node_addr, value);

  // link the new node to the current head
  set_next(new_node_addr, list->head);

  // update head to point to the new node
  list->head = new_node_addr;

}

void list_append(struct list *list, int value) {

  if(list == NULL) {
    return;
  }

  // allocate new node
  int new_node_addr = mem_alloc(2);
  if(new_node_addr == 0) {
    return;
  }

  // set value and terminate node
  set_value(new_node_addr, value);
  set_next(new_node_addr, 0);

  if(list->head == 0) {
    // empty node
    list->head = new_node_addr;
    list->current = new_node_addr;
  } else {
      // non-empty node
      int curr = list->head;
      while(get_next(curr) != 0) {
        curr = get_next(curr);
      }

      // link last node to new node
      set_next(curr, new_node_addr);

  }

}

void list_pop(struct list *list) {

  if(list == NULL || list->head == 0) {
    return;
  }

  int old_head = list->head;

  // move head to the next node
  list->head = get_next(old_head);

  // free the old head
  mem_free(old_head);

}

void list_truncate(struct list *list) {

  if(list == NULL || list->head == 0) {
    return;
  }

  int curr = list->head;

  // if there is only one node
  if(get_next(curr) == 0) {
    mem_free(curr);
    list->head = 0;
    list->current = 0;
    return;
  }

  // traverse to the second-last node
  while(get_next(get_next(curr)) != 0) {
    curr = get_next(curr);
  }

  int last = get_next(curr);

  // free last node
  mem_free(last);
  set_next(curr, 0);

}

void list_free(struct list *list) {

  if(list == NULL) {
    return;
  }

  int curr = list->head;
  while(curr != 0) {
    int next = get_next(curr); // get next node address
    mem_free(curr); // free current node
    curr = next; // move forward
  }

  // free the struct
  free(list);

}
