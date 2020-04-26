typedef int ElemType;
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkedList;

int main(int argc, char const *argv[])
{
    DuLinkedList L;

    return 0;
}
DuLNode *GetElem_Dul(DuLinkedList L, int i)
{
    return 0;
}
int Insert(DuLinkedList L, int i, ElemType e)
{
    DuLinkedList p;
    if (!(p = GetElem_Dul(L, 2)))
        return -1;
    {
        DuLNode *s;
        s->data = 1;
        s->prior = p->prior;
        p->prior->next = s;
        s->next = p;
        p->prior = s;
        return 1;
    }
}
int Delete(DuLinkedList L, int i)
{
    DuLinkedList p;
    if (!(p = GetElem_Dul(L, 2)))
        return -1;
    p->prior->next = p->next;
    p->next->prior = p->prior;
}