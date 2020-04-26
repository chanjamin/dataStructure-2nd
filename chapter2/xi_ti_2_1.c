#include <stdio.h>
#include "./lnode.c"
#include "stdlib.h"
int main(void)
{
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
            Lnode *q = pb->next;
            free(pb);
            pb = q;
        }
    }
    pc->next=pa?pa:pb;
    free(pb);
}