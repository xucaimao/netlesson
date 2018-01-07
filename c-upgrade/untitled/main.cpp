#include <iostream>
#include <cstdio>
using namespace std;
#define  F1(var)  printf("var=%d", var)
#define  F0(var)  F1(var * var)

int main(void)
{
    F0(3+4);
    return 0;
}
