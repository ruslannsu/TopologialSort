#pragma once

typedef struct AdjMatrix
{
    int n;
    char **matrix_src;
} AdjMatrix;

AdjMatrix *CreateAdjMatrix(int n);

void AddMatrixValue(AdjMatrix *matrix, int node_1, int node_2);

void DestroyMatrix(AdjMatrix *matrix);


