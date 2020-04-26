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

//8.10 两个子表归并
void merge(SqList *L,SqList *L2,int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    while (i<=mid&& j<=high)
    {
        if(L->r[i].key<=L->r[j].key){
            L2[k++]=L[i++];
        }else{
            L2->r[k++]=L[j++];
        }
    }
    while(i<=mid){
        L2[k++]=L[i++];
    }
    while(j<=high){
        L2[k++]=L[j++];
    }
}

//求mid,并对划分两子表递归MSort,再合并 
void MSort(SqList *R,SqList *T,int low,int high){
    if(low==high){
        T[low]=R[low];
    }else{
        int mid=(low+high)/2;
        MSort(R,L,low,mid);
        MSort(R,L,mid+1,high);
        merge(R,L,low,mid,high);
    }
}

void mergeSort(SqList *L){
    MSort(L,L,1,L->length);
}