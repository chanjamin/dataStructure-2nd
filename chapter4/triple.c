#define MAXSIZE 101
typedef int elemtype;
struct Triple{
    int row;
    int column;
    elemtype value;
}

struct TMartix
{
    int cn;//列数
    int rn;//行数
    int tn;//非0个数
    Triple[MAXSIZE]
};
