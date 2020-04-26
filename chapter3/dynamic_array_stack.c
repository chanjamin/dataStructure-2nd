#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
#define STACK_SIZE 100
#define STACK_INCREMENT 10
typedef int ElemType;
typedef struct sqstack
{
    ElemType *bottom;
    ElemType *top;
    int stackSize;
} SQStack;

Status Init_Stack(void)
{
    SQStack sqstack;
    sqstack.bottom = (ElemType *)malloc(STACK_SIZE * sizeof(ElemType));
    if (!sqstack.bottom)
        return ERROR;
    sqstack.top = sqstack.bottom;
    sqstack.stackSize = STACK_SIZE;
    return OK;
}
/**
 * 为什么能够通过++，因为申请的是连续的内存空间
 * 
 * */
Status push(SQStack s, ElemType e)
{
    //如果栈满
    if (s.top == s.bottom + s.stackSize)
    {
        //重新分配
        s.bottom = (ElemType *)realloc(s.bottom, (s.stackSize + STACK_INCREMENT) * sizeof(ElemType));
    }
    if (!s.bottom)
    {
        return ERROR;
    }

    //top-》栈顶
    s.top = s.bottom + (s.stakSize - 1);
    //size变化
    s.stackSize += STACK_INCREMENT;
    //进栈，top++
    s.top = &e;
    s.top++;
}
//出栈
Status pop(SQStack S, ElemType *e)
{
    if (s.top == s.bottom)
    {
        return ERROR;
    }
    s.top--;
    e = *s.top;
    return OK;
}