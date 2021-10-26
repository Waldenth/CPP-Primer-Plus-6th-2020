#ifndef _GRAPH_H_
#define _GRAPH_H_
#define N 7
#define E 9
#define MAX 32767
#define MIN -32767
typedef struct {
    int **edges;  //边的li
    int n;        //图的顶点数
    int e;        //图的边数
} MatGraph;

extern int AdjMatrix[N][N];
void InitGraph(MatGraph *G);
void Prim(MatGraph G, int start);

#endif