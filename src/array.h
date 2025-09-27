/*
Name: Sathursan Rasatheepan
login: srasathe
Student ID: 1343472
Date September 26, 2025
*/

#ifndef ARRAY_H
#define ARRAY_H

struct array
{
  int elements;
  int addr;
};

struct array *array_new( int size );
int array_get( struct array *ptr, int index );
void array_push( struct array *ptr, int value );
void array_append( struct array *ptr, int value );
void array_pop( struct array *ptr );
void array_truncate( struct array *ptr );
void array_free( struct array *ptr );

#endif
