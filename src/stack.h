#ifndef __ZBLIB_STACK__
#define __ZBLIB_STACK__

#include <stdlib.h>

typedef struct queue_t
{
    struct stack_node* rear;
    int size;
} stack_t;

typedef struct stack_node
{
    void *data;
    struct stack_node *next;
} stack_node;

// Initialize the stack.
void init_stack(stack_t* stack);

// Push an item onto the stack
// O(1)
void stack_push(stack_t* stack, void* data);

// pop an item off of the stack
// O(1)
void stack_pop(stack_t* stack, void** data);

// Check if an item exists in the stack 
// O(n) runtime
void stack_exists(stack_t* stack, void* data, int (*func)(void*, void*));


#endif