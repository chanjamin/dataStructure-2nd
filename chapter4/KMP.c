#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void getNextVal(char *p, int next[])
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        if (k == -1 || p[j] == p[k])
        {
            ++k;
            ++j;
            if (p[j] != p[k])
                next[j] = k;
            else
                next[j] = next[k];
        }
        else
        {
            k = next[k]; //往前找
        }
    }
}

void getNext(char *p, int next[])
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        //p[k]表示前缀，p[j]表示后缀
        if (k == -1 || p[j] == p[k])
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}
int main(int argc, char const *argv[])
{
    char *str = "ababaaab";
    int next [20] ;
    getNextVal(str, next);
    for (int i = 0; i < 50; i++)
    {
        printf("%d,", next[i]);
    }
}
