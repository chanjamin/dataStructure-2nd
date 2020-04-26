#include <stdio.h>
#define MAXSIZE 20
#define MaxInt 32767
typedef int KeyType;
typedef int InfoType;
typedef struct
{
    KeyType key;
    InfoType otherinfo;
} RedType;
typedef struct
{
    RedType r[MAXSIZE + 1];
    int length;
} SqList;

void MyselectSort(SqList *L)
{
    for (int i = 1; i < L->length; i++)
    {
        for (int j = i + 1; j < L->length; j++)
        {
            if (L->r[i].key < L->r[j].key)
                L->r[0] = L->r[j];
            L->r[j] = L->r[i];
            L->r[i] = L->r[0];
        }
    }
}

void selectSort(SqList *L)
{
    for (int i = 1; i < L->length; i++)
    {
        int k = i;
        for (int j = i + 1; j < L->length; j++)
        {
            if (L->r[i].key < L->r[j].key)
                k = j;
        }
        if (k != i)
        {
            L->r[0] = L->r[i];
            L->r[i] = L->r[k];
            L->r[k] = L->r[0];
        }
    }
}

/*
 *以下0号元素不用
 */
void HeapAdjust(SqList *L, int s, int m)
{
    RedType rc = L->r[s];
    for (int i = 2 * s; i < m; i *= 2)
    {
        if (i < m && L->r[i].key < L->r[i + 1].key) //左比右小，去右子树
            ++i;
        if (rc.key >= L->r[i].key)
            break;         //应插入位置
        L->r[s] = L->r[i]; //继续交换
        s = i;             //孩子
    }
    L->r[s] = rc; //插入
}

void createHeap(SqList *L)
{
    //从第一个非叶子节点开始，调整堆
    int n = L->length;
    for (int i = n / 2; i > 0; --i)
    {
        HeapAdjust(L,i,n);
    }
}

void heapSort(SqList *L){
    //创建堆
    createHeap(L);
    //交换堆顶元素，调整堆
    for(int i=L->length;i>1;i--){
        L->r[0]=L->r[i];
        L->r[1]=L->r[i];
        L->r[i]=L->r[0];
        HeapAdjust(L,1,i-1);
    }
}

