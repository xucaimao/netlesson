/*
 程序设计实习MOOC /程序设计与算法（三）第二周测验(2018春季)
 003:超简单的复数类
 write by xucaimao,2018-03-27,AC
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    Complex(){
        r=0;i=0;
    }
    Complex(const char * s){//要加const，不然编译错误
        r=s[0]-'0';
        i=s[2]-'0';
    }
};
int main() {
    Complex a;
    a = "3+4i";
    a.Print();
    a = "5+6i";
    a.Print();
    return 0;
}