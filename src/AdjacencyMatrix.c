#include "AdjacencyMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

AdjMatrix *CreateAdjMatrix(int n)
{
    AdjMatrix * matrix_ptr = malloc(sizeof(AdjMatrix));
    char **matrix_src = malloc(n * sizeof(char*) + n*n*sizeof(char));
    assert(matrix_ptr != NULL);
    assert(matrix_src != NULL);
    char *p = (char *) (matrix_src + n);
    for (int i = 0; i < n; i++) {
        matrix_src[i] = p;
        for (int j = 0; j < n; j++) {
            matrix_src[i][j] = 0;
        }
        p = p + n;
    }
    matrix_ptr->n = n;
    matrix_ptr->matrix_src = matrix_src;
    return matrix_ptr;
}

void AddMatrixValue(AdjMatrix *matrix, int node_1, int node_2)
{
    matrix->matrix_src[node_1][node_2] =  1;
}

void DestroyMatrix(AdjMatrix *matrix){
    free(matrix->matrix_src);
    free(matrix);
}
