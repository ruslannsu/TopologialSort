#include "Stack.h"
#include <stdlib.h>
#include <assert.h>


#define N 10

Stack *CreateStack()
{
    Stack *st = malloc(sizeof(Stack));
    assert(st != NULL);
    st->data = malloc(sizeof(Data) * N);
    assert(st->data != NULL); 
    st->n = 0;
    st->size = N;
    return st;
}

bool IsFull(Stack *st)
{
    return (st->n == st->size);
}

bool IsEmpty(Stack *st)
{
    return (st->n == 0);
}

void Push(Stack *st, Data data)
{
    if (IsFull(st))
    {
        st->size += N;
        st->data = realloc(st->data, sizeof(Data) * st->size);
    }
    st->data[st->n] = data;
    (st->n)++;
}

Data Pop(Stack *st)
{
    Data temp = st->data[st->n - 1];
    (st->n)--;
    if (st->size - st->n == N)
    {
        st->data = realloc(st->data, sizeof(Data) * st->size);
    }
    return temp;
}
void DestroyStack(Stack *st)
{
    free(st->data);
    free(st);
}
