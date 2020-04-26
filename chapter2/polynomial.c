#define MAXSIZE 100
typedef struct 
{
    float ceof;
    int expn;
}Polynomial;
typedef struct{
    Polynomial *elem;
    int length;
}SqList;
