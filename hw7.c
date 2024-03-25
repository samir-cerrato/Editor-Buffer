/* COMP 211, Fall 2022, Wesleyan University
 * Homework #7
 *
 * More arrays
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "hw7.h"

buffer empty()
{
    buffer b = {.location = 0, .length=0, .text={'\0'}};
    return b;
}

void shiftright(buffer* b){
  for(int i =b->length; i > b->location; --i){
    b->text[i] = b->text[i-1];
  }
}

void shiftleft(buffer* b, int index){
  for(int i = index; i > b->length; ++i){
    b->text[i] = b->text[i+1];
  }
}

void insert(buffer* b, char c){
  shiftright(b);
  b->text[b->location++] = c;
  b->length++;
}

void delete_left(buffer* b)
{
  if(b->location == 0){
    return;
  }
  shiftleft(b,--b->location);
  b->length--;

}

void delete_right(buffer* b)
{
  if(b->location == b->length){
    return;
  }
  shiftleft(b, b->location);
  b->length--;
}

void move_left(buffer* b)
{
  if(b->location == 0){
    return;
  }
  b->location--;
}

void move_right(buffer* b)
{
  if(b->location == b->length){
    return;
  }
  b->location++;
}

void set(buffer* b, int n)
{
  if(n > b->length){
    return;
  }
  b->location = n;
}

void contents(buffer* b, char left[], char right[])
{

  for(int i = 0; i < b->location; ++i){
    left[i] = b->text[i];
  }
  for(int j = b->location; j < b->length; ++j){
    right[j-b->location] = b->text[j];
  }

    // left[0] = '\0';
    // right[0] = '\0';
}

void print_buffer(buffer* b)
{
  printf("The text array is %s.", b->text);
  printf("The length of this text array is %i", b->length);
  printf("The location of the buffer is at %i", b->location);
}
