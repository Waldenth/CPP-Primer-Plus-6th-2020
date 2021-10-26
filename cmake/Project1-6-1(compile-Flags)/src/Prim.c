#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

int AdjMatrix[N][N] = {
    {0, 28, MAX, MAX, MAX, 10, MAX},
    {28, 0, 16, MAX, MAX, MAX, 14},
    {MAX, 16, 0, 12, MAX, MAX, MAX},
    {MAX, MAX, 12, 0, 22, MAX, 18},
    {MAX, MAX, MAX, 22, 0, 25, 24},
    {10, MAX, MAX, MAX, 25, 0, MAX},
    {MAX, 14, MAX, 18, 24, MAX, 0}};

/* 写死,可修改 */
void InitGraph(MatGraph *G) {
    G->edges = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
        G->edges[i] = (int *)malloc(sizeof(int) * N);
    G->n = N;  //顶点数
    G->e = E;  //边数
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            G->edges[i][j] = AdjMatrix[i][j];
    }
}

/* start是起点 */
void Prim(MatGraph G, int start) {
    printf("+---------------------------+\n");
    printf("|        Prim算法开始       |\n");
    printf("+---------------------------+\n\n");

    int *lowcost = (int *)malloc(sizeof(int) * G.n);  //lowcost[i]:未生成区中顶点i到达已生成区顶点的最小距离
    int *closet = (int *)malloc(sizeof(int) * G.n);   //closet[i]:未生成区中顶点i到达已生成区最小距离的已生成区顶点
    //初始只有起点start在已生成区
    for (int i = 0; i < G.n; i++) {
        lowcost[i] = G.edges[start][i];
        closet[i] = start;
    }

    int currentMin = MAX;
    int k = -1;

    for (int i = 1; i < G.n; i++) {  //找出剩下的n-1个顶点
        currentMin = MAX;
        for (int j = 0; j < G.n; j++) {
            if (lowcost[j] != 0 && lowcost[j] < currentMin) {
                currentMin = lowcost[j];
                k = j;  //记录从未生成区找到的顶点
            }
        }
        printf("\t 找到最小生成树边: (%d , %d),边权重为: %d\n", closet[k], k, currentMin);
        lowcost[k] = 0;  //顶点k进入已生成区

        for (int j = 0; j < G.n; j++) {  //由于已生成区加入了新顶点,刷新所有未生成区顶点的数据
            if (lowcost[j] != 0 && G.edges[k][j] < lowcost[j]) {
                lowcost[j] = G.edges[k][j];
                closet[j] = k;
            }
        }
    }

    printf("\n+---------------------------+\n");
    printf("|        Prim算法结束       |\n");
    printf("+---------------------------+\n");
}
