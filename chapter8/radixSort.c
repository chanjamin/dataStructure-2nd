#define MAXNUM_KEY 8 //关键字项数最大值
#define RADIX 10 //基数
#define MAX_SPACE 10000
typedef int KeyType;
typedef int otherItems;
typedef struct{
    KeyType keys[MAXNUM_KEY];
    InfoType otherItems;
    int next;

}SLCell;
typedef struct {
    SLCell r[MAX_SPACE];
    int keynum;
    int recnum;
}SLList;
typedef int ArrType[RADIX];

/**
 * 定位i 与f[i]的映射
 */
int ord(int i){
    return i;
}

/**
 * 找j的后继
 */
int succ(int j){
    return ++j;
}
//对keys[i]进行分配
void distribute(SLCell *r,int i,ArrType f,ArrType e){
    for (int i = 0; i < RADIX; i++)
    {
        f[i]=e[i]=0;//清空上一次结果
    }
    
    for(int p=r[0].next;p;p=r[p].next){
        int index=ord(p);
        if(!f[index]){
            f[j]=p;
        }else{//不为空队列
            r[e[j]].next=p;//链在链表上
        }
            e[index]=p;//维护队尾

    }
}
//对keys[i]进行回收
void collect(SLCell *r,int i,ArrType f,ArrType e){
    int j = 0
    for (; !f[j]; succ(j));//第一个非空队列
    r[0].next=f[j];//头节点
    int t=e[j];//尾指针
    
    while(j<RADIX){
        for(j=succ(j);j<RADIX-1&&!f[j];j=succ(j));
        if(f[j]){
            r[t].next=f[j];//链接上
            t=e[j];
        }
    }
    r[t].next=0;
}

void radixSort(SLList *L){
    ArrType f,e;
    for (int i = 0; i < L->recnum ; i++)
    {
        L->r[i].next=i+1;//初始链
    }
    L->r[L->recnum].next=0;//位指针指向0
    for (itn i = 0; i < L->keynum; i++)
    {
        distribute(L->r,i,f,e);
        collect(L-r,i,f,e);
    }
    
}