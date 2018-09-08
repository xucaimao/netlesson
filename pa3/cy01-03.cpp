/*
 程序设计实习MOOC /程序设计与算法（三）第一周测验(2018秋季)
 3:好怪异的返回值
 填空，使得程序输出结果是：10
 write by xucaimao,2018-09-03,AC
*/
#include <iostream>
using namespace std;
// 在此处补充你的代码
int & getElement(int * a, int i)
{
    return a[i];
}
int main()
{
    int a[] = {1,2,3};
    getElement(a,1) = 10;
    cout << a[1] ;
    return 0;
}
