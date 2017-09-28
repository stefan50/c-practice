//------------------------------------------------------------------------
// NAME: Stefan Angelov
// CLASS: XIa
// NUMBER: 24
// PROBLEM: #6
// FILE NAME: stack.c
// FILE PURPOSE:
// Creating a stack i C with functions initialise,destroy,push,top,pop
//------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int capacity;
    int *elements;
} stack;

void stack_init( stack * );
void stack_destroy( stack * );
int stack_empty( stack * );
void stack_push( stack *, int );
int stack_top( stack * );
void stack_pop( stack * );

int main()
{
	stack st;
	stack_init(&st);
	stack_push(&st,2);
	stack_pop(&st);
	if(stack_empty(&st))
	{
		printf("Empty!\n");
	}
	else
	{
		printf("Not empty!\n");
		printf("%d\n",stack_top(&st));
	}
	stack_destroy(&st);
	return 0;
}

void stack_init(stack* st)
{
//------------------------------------------------------------------------
// FUNCTION: stack_init
// initialise an empty stack (using dynamic memory)
// PARAMETERS:
// stack* st => That's our stack. It's a pointer because we want to keep the values after the end
// of the function 
//------------------------------------------------------------------------
	st->capacity = 10;
	st->elements = malloc(st->capacity*sizeof(int));
	st->size = 0;
}
void stack_destroy(stack* st)
{
//------------------------------------------------------------------------
// FUNCTION: stack_destroy
// destroying the stack (freeing the memory we gave to it)
// PARAMETERS:
// stack* st => That's our stack. It's a pointer because we want to keep the values after the end
// of the function
//------------------------------------------------------------------------
	free(st->elements);
	st->elements = NULL; //no double free possible
}
int stack_empty(stack* st)
{
//------------------------------------------------------------------------
// FUNCTION: stack_empty
// checks if a stack is empty - returns 1 if it is and 0 if it isn't
// PARAMETERS:
// stack* st => That's our stack. It's a pointer because we want to keep the values after the end
// of the function
//------------------------------------------------------------------------
	if(st->size == 0) return 1;
	else return 0; 	
}
void stack_push (stack* st, int val)
{
//------------------------------------------------------------------------
// FUNCTION: stack_push
// "pushes" an element into the stack
// PARAMETERS:
// stack* st => That's our stack. It's a pointer because we want to keep the values after the end
// of the function
// int val => the element we "push"
//------------------------------------------------------------------------
	*(st->elements+st->size) = val;
	st->size++;
}
int stack_top(stack* st)
{
//------------------------------------------------------------------------
// FUNCTION: stack_top
// returns the last element we "pushed"
// PARAMETERS:
// stack* st => That's our stack. It's a pointer because we want to keep the values after the end
// of the function
//------------------------------------------------------------------------
	return *(st->elements+st->size-1); //size is always +1
}
void stack_pop(stack* st)
{
//------------------------------------------------------------------------
// FUNCTION: stack_pop
// deletes the last element in the stack
// PARAMETERS:
// stack* st => That's our stack. It's a pointer because we want to keep the values after the end
// of the function
//------------------------------------------------------------------------
	if(stack_empty(st))
	{
		printf("Error!\n");
		return;
	}
	else
	{
		st->size--;
	}
}
