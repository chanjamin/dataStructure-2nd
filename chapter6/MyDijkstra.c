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

int main(void)
{
    AMGraph *G;
    int arr[MVNum + 1];
    Dijkstra(G, 0, 0, arr);
}
int route[MVNum + 1][MVNum];

int *Dijkstra(AMGraph *G, int i, int v, int arr[MVNum])
{
    int i;
    for (i = 0; i < G->vexnum; i++)
    {
        if (G->arcs[v][i] < MaxInt && NotExist(v, arr))
        {
            int newArr[MVNum + 1];
            arrCpy(arr, newArr);
            newArr = Dijkstra(G, ++i, G->arcs[v][i], newArr);
        }
    }
    arr[i] = v;
    arr[MVNum + 1] += G->arcs[v][i];
    return newArr;
}