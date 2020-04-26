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

//冒泡排序,while优化版
void bubbleSort(SqList *L){
      int flag=1,m=1;
      while(m<=L->length-1&&flag==1){
          flag=0;//如无交换，不进行下一趟
          for (int i = 1; i < L->length-1; i++)
          {
              if(L->r[i].key > L->r[i+1].key){
                  flag=1;
                  RedType r= L->r[i+1];
                   L->r[i+1]= L->r[i];
                   L->r[i]=r;
              }
          }
          ++m;
      }
}

int parttition(SqList *L,int low,int high){
    int pivotkey=L->r[low].key;
    L->r[0]=L->r[low];
    while (low<high)
    {
        while(low<high&&L->r[high].key >= pivotkey)
            --high;
        L->r[low]=L->r[high];
        while(low<high&&L->r[low].key <= pivotkey)
            --low;
        L->r[high]=L->r[low];
    }
    L->r[low]=L->r[0];
    return low;
}

void QuickSort(SqList *L,int low,int high){
    if(low<high){
        int pivotloc=parttition(L,low,high);
        QuickSort(L,low,pivotloc-1);
        QuickSort(L,pivotloc+1,high);
    }
}

void QuickSort(SqList *L){
    QuickSort(L,1,L->length);
}