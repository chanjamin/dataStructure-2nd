#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;
#define MVNum 100
typedef int ArcInfo;
typedef int NodeInfo;

typedef struct ArcNode
{
    int adjvex;              //节点
    struct ArcNode *nextArc; //下一边
    ArcInfo info;            //信息
} ArcNode;

typedef struct VNode
{
    NodeInfo info;
    struct ArcNode *firstArc;
} VNode, AdjList[MVNum];

typedef struct AMGraph
{
    AdjList list;
    int vexnum, arcnum; //方便
} AMGraph;

int locateVex(AMGraph G, NodeInfo v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.list[i].info == v)
            return i;
    }
    return -1;
}

void topoLogicalSort(AMGraph G)
{
    int indegree[MVNum];
    queue<int> que;
    int topo[MVNum];
    for (int i = 0; i < G.vexnum; i++)
    {
        ArcNode arcNode = G.list[i].firstArc;
        while (arcNode != 0)
        {
            indegree[arcNode.adjvex]++;
            arcNode = arcNode.nextArc;
        }
    }
    for (int i = 0; i < G.vexnum;) 
    {
        if (indegree[i] == 0&&que.nonexist(i))
        {
            que.push(i);
            ArcNode arcNode = G.list[i].firstArc;
            while (arcNode != NULL)
            {
                indegree[arcNode.adjvex]--;
                arcNode = arcNode.nextArc;
            }
            i = 0;//从头开始扫描
        }
        else
        {
            i++;
        }
    }
    if (que.size < G.vexnum)
    {
        cout << "not AOV-net";
    }
    if (que.size == G.vexnum)
    {
        while (!que.empty)
        {
            cout << que.front;
        }
    }
}