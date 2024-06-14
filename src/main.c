#include "AdjacencyMatrix.h"
#include "Errors.h"
#include "Stack.h"
#include "TSort.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1)
    {
        printf("bad number of lines");
        return 0;
    }
    if (!VerticesError(n))
    {
        printf("bad number of vertices");
        return 0;
    }
    int m;
    if (scanf("%d", &m) != 1)
    {
        printf("bad number of lines");
        return 0;
    }
    if (!EdgeError(n,m))
    {
        printf("bad number of edges");
        return 0;
    }
    AdjMatrix *matrix = CreateAdjMatrix(n);
    int edge_counter = 0;
    for (int i = 0; i < m; ++i) 
    {
        int node_1, node_2;
        if (scanf("%d%d", &node_1, &node_2) == 2)
        {
            edge_counter++;
        }
        if (!VertexError(node_1, node_2, n))
        {
            DestroyMatrix(matrix);
            printf("bad vertex");
            return 0;
        }
        node_1--;
        node_2--;
        AddMatrixValue(matrix, node_1, node_2);
    }
    if (edge_counter != m)
    {
        DestroyMatrix(matrix);
        printf("bad number of lines");
        return 0;
    }
    Stack *st = CreateStack();
    TSort(matrix, 0, st);
    DestroyMatrix(matrix);
    DestroyStack(st);
    
}
