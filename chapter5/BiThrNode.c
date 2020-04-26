#include <stdio.h>
typedef int ElemType;

typedef struct BiThrNode
{
    ElemType data;
    struct BiThrNode *lchild, *rchild;
    int lTag, rTag;
} BiThrNode, *BiThrTree;

static BiThrNode *pre;

void preOrderThread(BiThrNode *T) //先序遍历线索
{
    BiThrNode *p = T;
    while (p != NULL)
    {
        visit(p) if (p->lTag == 0) //是左孩子
            p = p->lchild;
        else //是前驱，访问后继
            p = p->rchild;
    }
}

//中序线索化
void InThreading(BiThrTree p)
{
    if (p)
    {
        InThreading(p->lchild);
        if (p->lchild == NULL)
        {
            p->lTag = 1;
            p->lchild = pre;
        }
        else
        {
            p->lTag = 0;
        }
        if (p->rchild == NULL)
        {
            p->rTag = 1;
            pre->rchild = p;
        }
        else
        {
            p->rTag = 0;
        }
        pre = p;
        InThreading(p->rchild);
    }
}
//带头节点二叉树中序线索化
void inOrderThreading(BiThrTree Thrt, BiThrTree T)
{
    Thrt->lTag = 0;
    Thrt->rTag = 1;
    Thrt->rchild = Thrt; //初始右指针指向自己
    if (!T)              //空树
    {
        Thrt->lchild = Thrt;
    }
    else
    {
        Thrt->lchild = T;
        pre = Thrt;
        InThreading(T);
        pre->rTag = 1;
        pre->rchild = Thrt; //最后节点指向头节点
        Thrt->rchild = pre; //头节点右指针指向最后节点
    }
}

//遍历中序线索二叉树
void InOrderTraverseThr(BiThrTree T)
{
    BiThrNode *p = T->lchild;
    //非空树或遍历结束
    while (p != T)
    {
        //最左下节点为中序遍历1节点
        while (p->lTag == 0)
        {
            p = p->lchild;
        }
        printf("%d", p->data);
        //一直访问后继
        while (p->rTag == 1 && p->rchild != T)
        {
            p = p->rchild;
            printf("%d", p->data);
        }

        //遇到右指针=0  找右子树第一节点，即中序遍历它之后的第一个节点
        p = p->rchild;
    }
}