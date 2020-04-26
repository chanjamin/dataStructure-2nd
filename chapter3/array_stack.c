#define MAX_STACK_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType;
typedef struct sqstack{
    ElemType stack_arrar[MAX_STACK_SIZE];
    int top;
}sqstack;

//初始化
sqstack Init_Stack(void){
    sqstack s;
    s.top=0;
    return s;
}

//压栈 ,1和2协调
Status push(sqstack s,ElemType e){
    //1
    if (top==MAX_STACK_SIZE-1)
    {
        return ERROR;
    }
    //2
    s.top++;
    s.stack_arrar[s.top]=e;
    return OK;
}

Status pop(sqstack s,ElemType *e){
    if(s.top==0)
        return ERROR;
    *e=s.stack_arrar[s.top];
    s.top--;
    return OK;
}