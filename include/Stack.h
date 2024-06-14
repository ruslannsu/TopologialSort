#pragma once
#include <stdbool.h>

typedef int Data;
typedef struct Stack
{
    Data *data;
    unsigned int n;
    unsigned int size;
} Stack;

Stack *CreateStack();

void StackInit(Stack *st);

bool IsFull(Stack *st);

bool IsEmpty(Stack *st);

void Push(Stack *st, Data data);

Data Pop(Stack *st);

void DestroyStack(Stack *st);
