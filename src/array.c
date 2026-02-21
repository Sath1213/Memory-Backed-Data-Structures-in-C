/*
Name: Sathursan Rasatheepan
Date September 26, 2025
*/

#include <stdlib.h>
#include "array.h"
#include "mem.h"

struct array *array_new(int size) {

  // allocate memory for the struct
  struct array *arr = malloc(sizeof(struct array));

  if(arr == NULL) {
    return NULL; // malloc failed
  }

  // allocate space for integers in mem
  int addr = mem_alloc(size);
  if(arr == NULL) {
    free(arr); // if mem_alloc fails
    return NULL;
  }

  // initialize all elements to 0
  for(int i = 0; i<size; i++) {
    set_value(addr + i, 0);
  }

  arr->elements = 0;
  arr->addr = addr;

  return arr;

}

int array_get(struct array *ptr, int index) {

  if(ptr == NULL) {
    return 0;
  }

  // fing the memory slot for this index
  int addr = ptr->addr + index;

  // get the value
  return get_value(addr);

}

void array_push(struct array *ptr, int value) {

  if(ptr == NULL) {
    return;
  }

  // shift elements down by 1
  for(int i = ptr->elements - 1; i>=0; i--) {
    int val = get_value(ptr->addr + i);
    set_value(ptr->addr + i + 1, val);
  }

  // insert the new value
  set_value(ptr->addr, value);

  // increment element count
  ptr->elements++;

}

void array_append(struct array *ptr, int value) {

  if(ptr == NULL) {
    return;
  }

  // write the value at the end of the array
  set_value(ptr->addr + ptr->elements, value);

  // increment element count
  ptr->elements++;

}

void array_pop(struct array *ptr) {

  if(ptr == NULL || ptr->elements == 0) {
    return;
  }

  // shift elements up by 1
  for(int i = 1; i < ptr->elements; i++) {
    int val = get_value(ptr->addr + i);
    set_value(ptr->addr + i - 1, val);
  }

  // decrement element count
  ptr->elements--;

}

void array_truncate(struct array *ptr) {

  if(ptr == NULL  || ptr->elements == 0) {
    return;
  }

  // reduce active element by 1
  ptr->elements--;

}

void array_free(struct array *ptr) {

  if(ptr == NULL) {
    return;
  }

  // free memory
  mem_free(ptr->addr);

  // free the struct
  free(ptr);

}
