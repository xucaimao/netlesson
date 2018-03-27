/*
 程序设计实习MOOC /程序设计与算法（三）第二周测验(2018春季)
 002:奇怪的类复制
 write by xucaimao,20180326,AC
*/
#include <iostream>
using namespace std;
class Sample {
public:
    int v;
    Sample(int a=0){//单参数构造函数，包含了零参数构造函数
        v=a;
    }
    Sample(const Sample & a){//拷贝构造函数
        v=a.v+2;//等价于this->v=a.v+2;
    }
// 在此处补充你的代码
};
void PrintAndDouble(Sample o)
{
    cout << o.v;
    cout << endl;
}
int main()
{
    Sample a(5);//调用单参数构造函数
    Sample b = a;//调用拷贝构造函数，b.v=7
    //重点在下面的函数调用，这里用的是传值调用，传值就会调用拷贝构造函数，使得值改变
    PrintAndDouble(b);//打印9
    Sample c = 20;//等价于 Sample c(20)
    //重点在下面的函数调用，这里用的是传值调用，传值就会调用拷贝构造函数，使得值改变
    PrintAndDouble(c);//打印22
    Sample d;//调用单参数构造函数的缺省值
    d = a;
    cout << d.v;
    return 0;
}