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
    Sample(int a){
        v=a;
    }
    Sample(const Sample & a){
        v=a.v+4;
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
    Sample a(5);
    Sample b = a;
    PrintAndDouble(b);
    Sample c = 20;
    PrintAndDouble(c);
    Sample d;
    d = a;
    cout << d.v;
    return 0;
}