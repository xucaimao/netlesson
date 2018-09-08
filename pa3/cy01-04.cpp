/*
 程序设计实习MOOC /程序设计与算法（三）第一周测验(2018秋季)
 4:神秘的数组初始化
 填空，使得程序输出结果是：123,456
 write by xucaimao,2018-09-03,AC
*/
#include <iostream>
using namespace std;

int main()
{
    int * a[] = {
// 在此处补充你的代码
    NULL,new int,new int,new int[6]
    };

    *a[2] = 123;
    a[3][5] = 456;
    if(! a[0] ) {
        cout << * a[2] << "," << a[3][5];
    }
    return 0;
}