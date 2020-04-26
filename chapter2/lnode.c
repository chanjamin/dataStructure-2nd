typedef int Elemtype;
#define FORMAT "%d\n"
#include <stdio.h>
#include <stdlib.h>
typedef struct Lnode
{
    Elemtype data;
    struct Lnode *next;
} Lnode, *LinkList;

//后插法
LinkList CreateList_R(int n)
{
    Lnode *head = (struct Lnode *)malloc(sizeof(struct Lnode)); //指向头节点的指针
    head->next = NULL;
    head->data = 0;
    // L = head; //指向头节点
    Lnode *r = head;
    for (int i = 1; i <= n; i++)
    {
        Lnode *this = (struct Lnode *)malloc(sizeof(struct Lnode));
        scanf(FORMAT, &this->data);
        this->next = NULL;
        r->next = this;
        r = this;
    }
    return head;
}
void printfList(LinkList L)
{
    Lnode *p = L;
    while (p != NULL)
    {
        printf(FORMAT, p->data);
        p = p->next;
    }
    int a;
    // free(p);
}
//前插法
LinkList CreateList_H(int n)
{
    Lnode *head = (struct Lnode *)malloc(sizeof(struct Lnode)); //指向头节点的指针
    head->next = NULL;
    head->data = 0;
    for (int i = 0; i < n; i++)
    {
        Lnode *p = (struct Lnode *)malloc(sizeof(struct Lnode));
        scanf(FORMAT,p->data);
        p->next=head->next;
        head->next=p;
    }
    return head;    
}