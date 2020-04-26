#include <stdio.h>
typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode, *LinkList;

int main(void){
    LinkList L;
    CreateList_R(L,8);
}
void CreateList_R(LinkList L,int n){
    Lnode lnode;
    L=&lnode;
    lnode.next=NULL;
    Lnode *r=L;
    for (int i = 0; i < n; i++)
    {
        Lnode this;
        scanf("%d",&this.data);
        this.next=NULL;
        r->next=&this;
        r=r->next;
    }
    
}
void Josephus(LinkList head,int n,int m){
    LinkList p=head,q;
    int count=1,k=n;
    while (k>1)
    {
        if (count==m-1)
        {
            q=p->next;p->next=q->next;
            printf("%d",p->data);
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