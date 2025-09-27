/*
Name: Sathursan Rasatheepan
login: srasathe
Student ID: 1343472
Date September 26, 2025
*/

#ifndef LIST_H
#define LIST_H

struct list
{
  int head;
  int current;
};

struct list *list_new( void );
void list_start( struct list *list );
void list_next( struct list *list );
int list_get( struct list *list );
void list_push( struct list *list, int value );
void list_append( struct list *list, int value );
void list_pop( struct list *list );
void list_truncate( struct list *list );
void list_free( struct list *list );

#endif
