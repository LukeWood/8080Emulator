#ifndef PROCESSOR_STACK_H
#define PROCESSOR_STACK_H

#include <stdlib.h>

void stack_push(unsigned char v);
unsigned char stack_pop();

typedef struct stack_node{
    struct stack_node* next;
    struct stack_node* prev;
    unsigned char value;
} stack_node;

stack_node* create_stack_node();
inline stack_node* create_stack_node(){
  stack_node *sn = malloc(sizeof(stack_node));
  sn->prev=NULL;
  return sn;
}

stack_node* stack_head = NULL;
void stack_push(unsigned char v){
  if(stack_head == NULL){
    stack_head = create_stack_node();
  }
  else{
    stack_node* temp = stack_head;
    stack_head=create_stack_node();
    stack_head->prev = temp;
  }
  stack_head->value = v;
}

unsigned char stack_pop(){
  //check if stack is empty
  if(stack_head == NULL)
    return (unsigned char)0;

  //reassign head & save top stack value
  unsigned char temp = stack_head->value;
  stack_node* temp_head = stack_head;
  stack_head = stack_head->prev;

  free(temp_head);

  return temp;
}

#endif
