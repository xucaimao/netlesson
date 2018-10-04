//程序设计实习MOOC / 程序设计与算法（三）第四周测验(2018秋季)
//2:看上去好坑的运算符重载
// Created by xucaimao on 2018/9/26.
//
#include <iostream>
using namespace std;
class MyInt
{
    int nVal;
public:
    MyInt( int n) { nVal = n ;}
// 在此处补充你的代码
    MyInt &operator-(int n){
        nVal-=n;
        return *this;
    }
    operator int(){
        return nVal;
    }

};
int Inc(int n) {
    return n + 1;
}
int main () {
    int n;
    while(cin >>n) {
        MyInt objInt(n);//输入20
        objInt-2-1-3;
        cout << Inc(objInt);//不重载类型转换运算符，这里编译就会提示类型不匹配
        cout <<",";
        objInt-2-1;
        cout << Inc(objInt) << endl;//输出12
    }
    return 0;
}