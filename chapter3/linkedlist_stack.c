#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
#define STACK_SIZE 100
#define STACK_INCREMENT 10
typedef int ElemType;
typedef struct Stack_Node
{
    ElemType data;
    struct Stack_Node *next;
} Stack_Node;

Stack_Node *Init()
{
    Stack_Node *top;
    top = (Stack_Node *)malloc(sizeof(Stack_Node));
    top->next = NULL;
    return top;
}

Stack_Node *Init2()
{
    Stack_Node top;
    struct Stack_Node *p = &top;
    p->next = NULL;
    return p;
}

Status push(Stack_Node *top, ElemType e)
{
    Stack_Node *p;
    p = (Stack_Node *)malloc(sizeof(Stack_Node));
    if (!p)
    {
        return ERROR;
    }
    p->data = e;
    p->next = top->next;//p->next= NULL;
    top->next = p;
    return OK;
}
Status pop(Stack_Node *top, ElemType *e)
{
    Stack_Node *p;
    if (top->next == NULL)
    {
        return ERROR;
    }
    p = top->next;
    *e = p->data;
    top->next = p->next;
    free(p);
    return OK;
}
//n数。b进制
void conversion(int n, int d)
{
    Stack_Node *S;
    int k, *e;
    S = Init();
    while (n > 0)
    {
        k = n % d;
        push(S, k);
        n /= 10;
    }
    while (S->next != NULL)
    {
        pop(S, e);
        printf("%1d", *e);
    }
}
int main(int argc, char const *argv[])
{
    conversion(4567, 8);
    return 0;
}
