/*
 程序设计实习MOOC /程序设计与算法（三）第一周测验(2018秋季)
 2:难一点的swap
 填空，使得程序输出结果是：5,3
 write by xucaimao,2018-09-03,AC
*/
#include <iostream>
using namespace std;

void swap(int * & a,int * & b)  //填写括号内的参数
{
    int * tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    int a = 3,b = 5;
    int * pa = & a;
    int * pb = & b;
    swap(pa,pb);
    cout << *pa << "," << * pb;
    return 0;
}