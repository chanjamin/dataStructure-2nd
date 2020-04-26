#include <stdio.h>
typedef struct Lnode
{
    char *p;
    struct Lnode *next;
} Lnode, *LinkList;
int main(int argc, char const *argv[])
{
    Lnode head;
    LinkList list = &head;
    Lnode no1 = {"hello", 0};
    head.next = &no1;
    printf("%s",(*(head).next).p);
    return 0;
}
