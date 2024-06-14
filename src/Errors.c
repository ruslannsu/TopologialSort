#include <stdio.h>
#include <stdbool.h>

bool VerticesError(int n)
{
    if ((n > 2000) || (n < 0))
    {
        printf("bad number of vertices");
        return false;
    }
    return true;
}

bool EdgeError(int n, int m)
{
    if ((m < 0) || (m > (n * (n + 1) / 2)))
    {
        printf("bad number of edges");
        return false;
    }
    return true;
}

bool VertexError(int node_1, int node_2, int n)
{
    if ((node_1 > n) || (node_1 < 1))
    {
        printf("bad vertex");
        return false;
    }
    if ((node_2 > n) || (node_2 < 1))
    {
        printf("bad vertex");
        return false;
    }
    return true;
}
