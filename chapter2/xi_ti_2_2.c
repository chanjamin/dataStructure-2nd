#include <stdio.h>
#include "./lnode.c"
#include <stdlib.h>
LinkList MergeList(LinkList a, LinkList b);
int main(void)
{
    LinkList A;
    // LinkList LA = CreateList_R(3);
    LinkList B=CreateList_H(3); 
    // CreateList_R(B,4);
    // LinkList Lc=MergeList(A,B);
    printfList(B);
}
LinkList MergeList(LinkList a, LinkList b)
{
    //初始化 Lc,*pc->a
    Lnode *pc = a;
    LinkList Lc = pc;

    Lnode *pa = a->next;
    Lnode *pb = b->next;
    while (a != NULL || b != NULL)
    {
        if (pa->data < pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else if (pa->data > pb->data)
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
        else
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(pb);
    return Lc;
}