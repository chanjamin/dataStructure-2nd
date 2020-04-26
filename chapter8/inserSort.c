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

void MyInsertSort(SqList *L)
{
    RedType sorted[MAXSIZE + 1];
    for (int i = 0; i < L->length; i++)
    {
        sorted[i].key = -MaxInt;
    }

    for (int i = 0; i <= L->length; i++)
    {
        KeyType k = L->r[i].key;
        for (int j = 0; j < L->length; j++)
        {
            if (k >= sorted[j].key)
            {
                for (int w = j; w < L->length - 1; w++)
                {
                    sorted[w + 1] = sorted[w];
                }
                sorted[j] = L->r[i];
            }
        }
    }
}

// 0做监视哨
void insertSort(SqList *L)
{
    for (int i = 2; i < L->length; i++)
    {
        if (L->r[i - 1].key > L->r[i].key)
        {
            //交换i/i+1
            L->r[0] = L->r[i];
            L->r[i] = L->r[i - 1];
            //还不知道交换后的i和1~i-1之间的大小关系,1~i-1都是排序好的
            int j;
            for (j = i - 2; L->r[0].key < L->r[j].key; --j)
            {
                L->r[j + 1] = L->r[j];
            }
            L->r[j + 1] = L->r[0];
        }
    }
}

//折半插入排序
void BInsertSort(SqList *L)
{
    for (int i = 2; i < L->length; i++)
    {
        L->r[0] = L->r[i];
        int low = 1, high = i - 1;
        while (low <= high)
        {
            int m = (low + high) / 2;
            if (L->r[0].key < L->r[m].key)
                high = m - 1;
            else
                low = m + 1;
            for (int j = i - 1; j >= high + 1; --j) //对于high+1~i-1，记录后移
            {
                L->r[j + 1] = L->r[j];
            }
            L->r[high + 1] = L->r[0]; //到正确位置
        }
    }
}

//希尔排序
void ShellSort(SqList *L, int dt[], int t)
{
    for (int i = 0; i < t; i++)
    {
        shellInsert(L, dt[i]);
    }
}

void shellInsert(SqList *L, int dk)
{
    for (int i = dk + 1; i < L->length; i++)
    {
        if (L->r[i].key < L->r[i - dk].key)
        {
            L->r[0] = L->r[i];
            int j = i - dk;
            for (; j > 0 && L->r[j].key > L->r[0].key; j -= dk)
            {
                L->r[j+dk]=L->r[j];//j是要插入的位置
            }
            L->r[j+dk]=L->r[0];
        }
    }
}