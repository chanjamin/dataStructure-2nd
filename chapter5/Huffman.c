#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码
typedef int ElemType;
typedef struct {
    int weight;
    int parent,lchild,rchild;
}HTNode ,*HuffmanTree;
typedef char ** HuffmanCode;
void select(HuffmanTree T,int len,int *s1,int *s2){
    int min1,min2=INT_MAX;
    //找到最小权值1
    for (int i = 1; i <= len; i++)
    {
        if(T[i]->weight<=min1&&T[i]->parent==0){
            min1=T[i]->weight;
            *s1=i;
        }
    }
    int temp=T[s1]->weight;
    T[s1]->weight=INT_MAX;
    for (int i = 1; i <=len; i++)
    {
        if(T[i]->weight<=min2&&T[i]->parent==0){
            min2=T->weight;
            *s2=i;
        }
    }
    T[s1]->weight=temp;
}

void createHuffmanTree(HuffmanTree HT,int n){
    int m,s1,s2,i;
    if(n<=1)
    return;
    m=2*n-1;
    HTNode [m+1] tree;
    HT=tree;
    //初始化
    for (int i = 1; i < =m; i++)
    {
        HT[i]->parent=0;HT[i]->lchild=0;HT[i]->rchild=0;       
    }
    //权
    for (int i = 1; i < =n; i++)
    {
        printf("请输入权值:");
        scanf("%d",&HT[i]->weight);
    }
    //创建
    for(int i=n+1;i<=m;i++){
        select(&HT,i-1,&s1,&s2);
        HT[s1]->parent=i;
        HT[s2]->parent=i;
        HT[i]->lchild=s1;
        HT[i]->rchild=s2;
        HT[i]->weight= HT[s1]->weight+HT[s2]->weight;

    }
}
//HuffmanTree数组
void createHuffmanCode(HuffmanTree *HT,HuffmanCode HC,int n){
    HC=char *[n+1];
    char cd [n];
    cd[n-1]='\0';
    for (int i = 1; i <=n; i++)
    {
        int start=n-1;
        int c=i;
        int f=HT[i]->parent;
        while (f!=0)
        {
            --start;
            if(HT[f]->lchild==c)
                cd[start]='0';
            else
            {
                cd[start]='1'
            }
            c=f;
            f=HT[f]->parent;
            
        }
        strcpy(HC[i],cd);
    }
    
}

int main(int argc, char const *argv[])
{
    int n;HuffmanTree T;
    printf("哈夫曼树结点数:");
    scanf("%d",&n);
    createHuffmanTree(T,n);
    return 0;
}
