
#define MaxVerNum 20

#define MaxValue 10000

typedef int adjmatrix[MaxVerNum][MaxVerNum];     //?????????

 

typedef struct Node

{

    int adjvex;

    struct Node * next;

}edgenode;        //