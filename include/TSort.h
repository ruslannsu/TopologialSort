#pragma once
#include "AdjacencyMatrix.h"
#include "Stack.h"

void TSort(AdjMatrix *matrix, int node_num, Stack *st);

bool TopSortFrom(AdjMatrix *matrix, int node_num, int *checked, Stack *st);
