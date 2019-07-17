#include "Graph.h"
void InitMatrix(adjmatrix G)

{

    int  i, j;

    for(i = 0; i < MaxVerNum; i++)

       for(j = 0; j < MaxVerNum; j++)

           G[i][j] = MaxValue;

}