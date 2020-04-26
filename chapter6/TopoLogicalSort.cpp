#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <iostream>
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

typedef struct ALGraph
{
    AdjList vertices;
    int vexnum, arcnum; //方便
} ALGraph;

int locateVex(ALGraph G, NodeInfo v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].info == v)
            return i;
    }
    return -1;
}

int topoLogicalSort(ALGraph G,int topo[])
{
    int indegree[MVNum];
    stack<int> stk;

    for (int i = 0; i < G.vexnum; i++)
    {
        ArcNode * arcNode = G.vertices[i].firstArc;
        while (arcNode != 0)
        {
            indegree[arcNode->adjvex]++;
            arcNode = arcNode->nextArc;
        }
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        if(!indegree[i])
        {
            stk.push(i);
        }
    }
    int m=0;
    while (!stk.empty)
    {
        int i=stk.top();
        topo[m]=i;
        ++m;
        ArcNode *p=G.vertices[i].firstArc;
        while (p!=NULL)
        {
            int k=p->adjvex;
            indegree[k]--;
            if(!indegree[k])
                stk.push(k);
            p=p->nextArc;
        }
        
    }
    
    if (m< G.vexnum)
        return -1;
    else 
        return 1;
}

