// stack.h

#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 3

void stack_init(void);
int stack_push(int val);
int stack_pop(int *pVal);
int stack_full(void);
int stack_empty(void);

#endif // STACK_H
