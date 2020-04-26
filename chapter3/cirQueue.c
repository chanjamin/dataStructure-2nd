#define MAX_STACK_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
typedef ElemType int;
//定义元素
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
} QNode;
//定义链队列
typedef struct LinkQueue
{
    struct QNode *front;
    struct QNode *rear;
} LinkQueue;

LinkQueue *init(void)
{
    LinkQueue *Q = (LinkQueue *)malloc(sizeof(LinkQueue));
    QNode *q = (QNode *)malloc(sizeof(LinkQueue));
    q->next = NULL;
    Q->front = Q->rear = q;
    return Q;
}

Status insert(LinkQueue *Q, ElemType e)
{
    QNode *p = (QNode *)malloc(sizeof(QNode));
    if (!p)
    {
        return ERROR;
    }
    p->data = e;
    p->next = NULL;
    //尾插
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}
Status delete (LinkQueue *Q, ElemType *x)
{
    QNode *p;
    //队空
    if (Q->front == Q->rear)
        return ERROR;
    //取第一元素
    p = Q->front->next;
    Q->front->next = p->next;
    //只有最后一元素
    if (p == Q.rear)
        Q.front = Q.rear;
    free(p);
    return OK;
}
Status destory(LinkQueue *Q)
{
    while (Q.front != NULL)
    {
        //rear直接front下一个元素
        Q->rear = Q->front->next;
        //释放头节点
        free(Q->front);
        Q->front=Q->rear;
    }
}