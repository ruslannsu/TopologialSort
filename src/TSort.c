#include "Stack.h"
#include "AdjacencyMatrix.h"
#include "TSort.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

enum {not_processed = 0, in_path = 1, processed = 2};

bool TopSortFrom(AdjMatrix *matrix, int node_num, int *checked, Stack *st)
{
    checked[node_num] = in_path;
    for (int j = 0; j < matrix->n; j++)
    {
        if (matrix->matrix_src[node_num][j] == 1) 
        {
            if (checked[j] == not_processed) 
            {
                if (!TopSortFrom(matrix, j, checked, st))
                {
                    return false;
                }
            }
            else
            {
                if (checked[j] == in_path)
                {
                    return false;
                }
            }
        }
    }
    checked[node_num] = processed;
    Push(st, node_num);
    return true;
}

void TSort(AdjMatrix *matrix, int node_num, Stack *st)
{
    int *checked = calloc(matrix->n, sizeof(int));
    assert(checked != NULL);
    if (!TopSortFrom(matrix, node_num, checked, st))
    {
        free(checked);
        printf("impossible to sort");
        return;
    }
    for (int i = 0; i < matrix->n; i++)
    {
        if (checked[i] == not_processed)
        {
            if (!TopSortFrom(matrix, i, checked, st))
            {
                free(checked);
                printf("impossible to sort");
                return;
            }
        }
    }
    while (IsEmpty(st) != true)
    {
        printf("%d ", Pop(st) + 1);
    }
    free(checked);
}
