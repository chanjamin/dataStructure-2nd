#define MAX_QUEUE_SIZE 100
typedef ElemType int;
typedef struct queue{
    ElemType QueueArray[MAX_QUEUE_SIZE];
    int front;
    int rear;
}SqQueue 