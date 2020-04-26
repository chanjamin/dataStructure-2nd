#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stud_node
{
    int num;
    char name[20];
    int score;
    struct stud_node *next;
};
struct stud_node *create_stu_doc()
{
    struct stud_node *head, *p;
    int num, score;
    char name[20];
    int size = sizeof(struct stud_node);

    head = NULL;
    printf("input num,name and score:");
    scanf("%d%s%d", &num, name, &score);
    while (num != 0)
    {
        p = (struct stud_node *)malloc(size);
        p->num = num;
        strcpy(p->name,name);
        p->score=score;
        head=InsertDoc(head,p);
        scanf("%d %s %d"&num,name,&score);
    }
    return head;
}
struct stud_node * InsertDoc(struct stud_node *head,struct stud_node *p){
    struct stud_node *pt1=head;
    struct stud_node *pt2=p;
    if(head==NULL){
        head->next=p;
        return head;
    }
    while (pt1->next!=NULL)
    {
        pt1=pt1->next;
    }
    pt1->next=p;
    p->next=NULL;
    return head;
}