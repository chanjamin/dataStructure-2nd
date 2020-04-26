#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <iostream>
#include <stack>
#define OK 1
#define ERROR 0
#define MVNum 9

using namespace std;
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
    AdjList converse_vertices; //逆邻接表
    int vexnum, arcnum;        //方便
} ALGraph;

//- - - - -顺序栈的定义- - - - -
typedef struct
{
    int *base;
    int *top;
    int stacksize;
} spStack;
//- - - - - - - - - - - - - - - -

int indegree[MVNum]; //数组indegree存放个顶点的入度
spStack S;

//------------栈的相关操作----------------------
void InitStack(spStack &S)
{
    //初始化栈
    S.base = new int[MVNum];
    if (!S.base)
        exit(1);
    S.top = S.base;
    S.stacksize = MVNum;
} //InitStack

void Push(spStack &S, int i)
{
    //进栈
    if (S.top - S.base == S.stacksize)
        return;
    *S.top++ = i;
} //Push

void Pop(spStack &S, int &i)
{
    //出栈
    if (S.top == S.base)
        return;
    i = *--S.top;
} //Pop

bool StackEmpty(spStack S)
{
    //判断栈是否为空
    if (S.top == S.base)
        return true;
    return false;
} //StackEmpty
//-------------------------------------------------

int locateVex(ALGraph G, NodeInfo v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].info == v)
            return i;
    }
    return -1;
}

int createUDG(ALGraph &G)
{

    // cout << "请输入总顶点数，总边数，以空格隔开:";
    // cout << endl;
    // cin >> G.vexnum >> G.arcnum;
    // cout << "输入点的名称，如a" << endl;

    FILE *fp = fopen("chapter6/PATH.txt", "r");
    if (fp != NULL)
    {
        fscanf(fp, "%d", &G.vexnum);
        fscanf(fp, "%d", &G.arcnum);
        for (int i = 0; i < G.vexnum; i++)
        {
            // cout << "请输入第" << (i + 1) << "个点的名称:"<<flush;
            int tmp = fscanf(fp, "%d", &G.vertices[i].info);
            G.converse_vertices[i].info = G.vertices[i].info;
            G.vertices[i].firstArc = NULL;
            G.converse_vertices[i].firstArc = NULL;
        }
        cout << endl;
        // cout << "输入边依附的顶点，如a b" << endl;
        for (int k = 0; k < G.arcnum; k++)
        {
            NodeInfo v1, v2;
            int i, j;
            fscanf(fp, "%d %d", &v1, &v2); // cout << "请输入第" << (k + 1) << "条边依附的顶点:"<<flush;
                                           //输入一条边依附的两个顶点
            i = locateVex(G, v1);
            j = locateVex(G, v2);
            //确定v1和v2在G中位置，即顶点在G.vertices中的序号

            ArcNode *p1 = new ArcNode; //生成一个新的边结点*p1
            p1->adjvex = j;            //邻接点序号为j
            p1->nextArc = G.vertices[i].firstArc;
            G.vertices[i].firstArc = p1;
            //将新结点*p1插入顶点vi的边表头部

            ArcNode *p2 = new ArcNode; //生成一个新的边结点*p1
            p2->adjvex = i;            //逆邻接点序号为i
            p2->nextArc = G.converse_vertices[j].firstArc;
            G.converse_vertices[j].firstArc = p2;
            //将新结点*p1插入顶点vi的边表头部

            // cout << "输入此边信息:" << flush;
            fscanf(fp, "%d", &p1->info);
            p2->info = p1->info;
            // scanf("%d", &p1->info, &p2->info);
        }
        return OK;
    }
    else
        return ERROR;
}

bool visited[MVNum];

void DFS(ALGraph G, int v)
{
    visited[v] = true;
    cout << G.vertices[v].info << " ";
    ArcNode *p = G.vertices[v].firstArc;
    while (p != NULL)
    {
        if (!visited[p->adjvex])
        {
            DFS(G, p->adjvex);
        }
        p = p->nextArc;
    }
}
void FindInDegree(ALGraph G)
{
    //求出各顶点的入度存入数组indegree中
    int i, count;

    for (i = 0; i < G.vexnum; i++)
    {
        count = 0;
        ArcNode *p = G.converse_vertices[i].firstArc;
        if (p)
        {
            while (p)
            {
                p = p->nextArc;
                count++;
            }
        }
        indegree[i] = count;
    }
} //FindInDegree

int TopologicalSort(ALGraph G, int topo[])
{
    //有向图G采用邻接表存储结构
    //若G无回路，则生成G的一个拓扑序列topo[]并返回OK，否则ERROR
    int i, m;
    FindInDegree(G); //求出各顶点的入度存入数组indegree中
    InitStack(S);    //栈S初始化为空
    for (i = 0; i < G.vexnum; ++i)
        if (!indegree[i])
            Push(S, i); //入度为0者进栈
    m = 0;              //对输出顶点计数，初始为0
    while (!StackEmpty(S))
    {                                        //栈S非空
        Pop(S, i);                           //将栈顶顶点vi出栈
        topo[m] = i;                         //将vi保存在拓扑序列数组topo中
        ++m;                                 //对输出顶点计数
        ArcNode *p = G.vertices[i].firstArc; //p指向vi的第一个邻接点
        while (p)
        {
            int k = p->adjvex; //vk为vi的邻接点
            --indegree[k];     //vi的每个邻接点的入度减1
            if (indegree[k] == 0)
                Push(S, k); //若入度减为0，则入栈
            p = p->nextArc; //p指向顶点vi下一个邻接结点
        }                   //while
    }                       //while

    if (m < G.vexnum)
        return ERROR; //该有向图有回路
    else
        return OK;
} //TopologicalSort

bool visitedInTopo[MVNum];

bool isBeforeVistedInTopo(ALGraph G, int v)
{
    bool finshed = 1;
    for (int i = 0; i < visitedInTopo[v]; i++)
    {
        if (!visitedInTopo[i])
            finshed = 0;
    }
    return finshed;
}
int findVisitedNoInTopo(ALGraph G, int v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (visitedInTopo[i] == v)
            return i;
    }
    return -1;
}
int criPath[MVNum];
int CriticalPath(ALGraph G, int ve, int v)
{
    int vl=ve;
    visitedInTopo[findVisitedNoInTopo(G, v)] = true; //更改访问过状态
    //
    ArcNode *p = G.vertices[v].firstArc;
    while (p != NULL)
    {
        if (!isBeforeVistedInTopo(G,p->adjvex))
        {
            //
             vl=CriticalPath(G,ve, p->adjvex);
             if(vl==ve){
                 cout<<v<<' ';
             }

        }
        p = p->nextArc;
    }
}
int main(void)
{
    cout << "************算法6.12　拓扑排序**************" << endl;
    ALGraph G;
    createUDG(G);
    DFS(G, 0);
    int *topo = new int[G.vexnum];
    cout << endl;
    cout << "有向图的邻接表、逆邻接表创建完成!" << endl
         << endl;

    if (TopologicalSort(G, topo))
    {
        cout << "该有向图的拓扑有序序列为：";
        for (int i = 0; i < G.vexnum; i++)
        {
            if (i != G.vexnum - 1)
                cout << G.vertices[topo[i]].info << ',';
            else
            {
                cout << G.vertices[topo[i]].info << endl;
            }
        }
    }
    else
        cout << "网中存在环，无法进行拓扑排序！" << endl
             << endl;
    return 1;
}