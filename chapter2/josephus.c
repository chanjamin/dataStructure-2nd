#include <stdio.h>
#include <stdlib.h>

void Josephus(LinkList head,int n,int m){
    LinkList p=head,q;
    int count=1,k=n;
    while (k>1)
    {
        if (count==m-1)
        {
            q=p->next;p->next=q->next;
            printf("%s",p->data);
            free(q);
            count=0;
            --k;
        }
        else
        {
            count++;p=p->next;
        }
    }
    printf("the winner is %d",p->data);
}