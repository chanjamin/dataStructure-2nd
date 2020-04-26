#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxInt 32767
#define MVNum 100 //最大顶点数
typedef char VerTexType;
typedef int ArcType;

typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} AMGraph;

int locateVex(AMGraph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}

int createUDN(AMGraph &G)
{
    printf("输入顶点个数：");
    scanf("%d", &G.vexnum);
    for (int i = 0; i < G.vexnum; i++)
    {
        printf("input the value of vertex %d:", i);
        scanf("%c", &G.vexs[i]);
    }
    printf("input the number of arc:");
    scanf("%d", &G.arcnum);
    for (int i = 0; i < G.arcnum; i++)
    {
        printf("input the vertex1,vertex2 of arc %d", i);
        int v1, v2, w;
        char v1v, v2v;
        scanf("%c %c %d", &v1v, &v2v, &w);
        v1 = locateVex(*G, v1v);
        v2 = locateVex(*G, v2v);
        if (v1 != -1 && v2 != -1)
        {
            G.arcs[v1][v2] = w;
            G.arcs[v2][v1] = w;
        }
    }
    return 1;
}

bool visited[MVNum];

//思想一致，严老师的比我好在先判断，再递归
void DFS_MY(AMGraph *G, int line, int col)
{
    if (!visited[line] && G->arcs[line][col] != NULL)
    {
        printf("%c", G->vexs[line]);
        visited[line] = 1;
        for (int i = 0; i < MVNum; i++)
        {
            DFS(G, col, i);
        }
    }
}

void DFS_AM(AMGraph *G, int v)
{
    printf("%d", G->vexs[v]);
    visited[v] = 1;
    for (int i = 0; i < G->vexnum; i++)
    {
        if (G->arcs[v][i] != NULL && !visited[i])
        {
            DFS_AM(G, i);
        }
    }
}

int S[MVNum];
int D[MVNum];
int Path[MVNum];
void ShortestPath_DIJ(AMGraph G, int v0)
{
    int n = G.vexnum;
    int v, w, min = MaxInt;
    for (int v = 0; v < n; v++) //初始化S=0,D=v0->Vx,Path==∞?infinite:Vx->V0;
    {
        S[v] = 0;
        D[v] = G.arcs[v0][v];
        if (D[v] < min)
        {
            Path[v] = v0;
        }
        else
        {
            Path[v] = -1; //不可达}
        }
    }
    S[v0] = 1;
    for (int i = 1; i < n; i++)
    {
        min = MaxInt;
        for (w = 0; w < n; w++)
        {
            if (!S[w] && D[w] < min)
            {
                v = w;
                min = D[w];
            }
        }
        S[v] = 1;
        for (w = 0; w < n; w++)
        {
            if (!S[w] && (D[v] + G.arcs[v][w]) < D[w])
            {
                D[w] = D[v] + G.arcs[v][w];
                Path[w] = v;
            }
        }
    }
}

void ShortestPath_Floyd(AMGraph G)
{
    int FD[MVNum][MVNum];
    int FPath[MVNum][MVNum];
    //初始化
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int w = 0; w < G.vexnum; w++)
        {
            FD[i][w] = G.arcs[i][w];
            if (FD[i][w] < MaxInt)
            {
                FPath[i][w] = i;
            }
        }
    }

    //
    for (int k = 0; k < G.vexnum; k++)
    {
        for (int i = 0; i < G.vexnum; i++)
        {
            for (int j = 0; j < G.vexnum; j++)
            {
                if ((FD[i][k] + FD[k][j]) < FD[i][j])
                {
                    FPath[i][j] = FPath[k][j];
                    FD[i][j] = FD[i][k] + FD[k][j];
                }
            }
        }
    }
}