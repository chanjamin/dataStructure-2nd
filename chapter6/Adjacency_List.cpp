#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <queue>
#define MVNum 100

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
    cout << "请输入总顶点数，总边数，以空格隔开:";
    cin >>G.vexnum>>G.arcnum;
    cout << endl;
    cout << "输入点的名称，如a" << endl;

    for (int i = 0; i < G.vexnum; i++)
    {
        cout << "请输入第" << (i + 1) << "个点的名称:";
        cin >> G.vertices[i].info;
        G.vertices[i].firstArc = NULL;
    }
    cout << endl;
    cout << "输入边依附的顶点，如a b" << endl;
    for (int k = 0; k < G.arcnum; k++)
    {
        NodeInfo v1, v2;
        int i, j;
        cout << "请输入第" << (k + 1) << "条边依附的顶点:";
        cin >> v1 >> v2; //输入一条边依附的两个顶点
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

        cout << "输入此边信息:";
        // cin>>p1->info>>p2->info;
        scanf("%d", &p1->info, &p2->info);
    }
    return 1;
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
int main()
{
    cout << "************算法6.6　采用邻接表表示图的深度优先搜索遍历**************" << endl
         << endl;
    ALGraph G;
    createUDG(G);
    cout << endl;
    cout << "无向连通图G创建完成！" << endl
         << endl;

    cout <<"请输入遍历连通图的起始点：";
    NodeInfo c;
    cin >> c;

    int i;
    for (i = 0; i < G.vexnum; ++i) 
    {
        if (c == G.vertices[i].info)
            break;
        cout <<i<<endl;
    }
    cout << endl;

    while (i >= G.vexnum)
    {
        cout << "该点不存在，请重新输入！" << endl;
        cout << "请输入遍历连通图的起始点：";
        cin >> c;
        for (i = 0; i < G.vexnum; ++i)
        {
            if (c == G.vertices[i].info)
                break;
        cout <<i<<endl;
        }
    }

    cout << "深度优先搜索遍历图结果：" << endl;
    DFS(G, i);

    cout << endl;
    return 0;
} //main
  // bool BFS(ALGraph *G, int v)
  // {
  //     for (int i = 0; i < MVNum; i++)
  //     {
  //         visited[i] = 0;
  //     }

//     printf("%d", v);
//     queue q=new queue();
//     EnQueue(Q, v);
//     whiile(!QueueEmpty(Q))
//     {
//         DeQueue(G, u);
//         for (w = FirstAdjBex(G, u); w >= 0; w = NextAdjVex(G, u, w))
//         {
//             if (!visited[w])
//             {
//                 printf("%d", w);
//                 visited[w] = 1;
//                 EnQueue(Q, w);
//             }
//         }
//     }

// }

// 尾插法不便
// int createUDG(ALGraph *G){
//     scanf("%d %d",&G->vexnum,G->arcnum);
//     for (int i = 0; i < G->vexnum; i++)
//     {
//         scanf("%c",&G->list[i].data);
//         G->list[i]->firstArc=NULL;
//     }
//     for (int i = 0; i < G->arcnum; i++)
//     {
//         int i,j;
//         ArcNode p1,p2;
//         char c1,c2;
//         scanf("%c",c1);scanf("%c",c2);
//         i=locateVex(*G,c1);
//         j=locateVex(*G,c2);

//         if (i!=-1&&j!=-1)
//         {
//             scanf("%d",p1.info);
//             p1.adjvex=j;
//             p1.nextArc=NULL;
//             if (G->list[i]->firstArc==NULL)
//             {
//                 G->list[i]->firstArc=p1;
//             }else
//             {
//                 ArcNode * tmp=G->list[i]->firstArc;
//                 while (tmp->nextArc!=NULL)
//                 {
//                     tmp=tmp->nextArc;
//                 }
//                 tmp->nextArc=p1;

//             }
//             //j同理

//         }

//     }

// }