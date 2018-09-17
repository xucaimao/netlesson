/*
 程序设计实习MOOC /程序设计与算法（三）第三周测验(2018春季)
 1:返回什么才好呢
 write by xucaimao,2018-04-03,AC
*/

#include <iostream>
using namespace std;
class A {
public:
    int val;

    A(int v=123):val(v){}

    A(const A & a){
        val=a.val;
    }
//重点在这里，不需要下面的 int& 返回类型的函数

//    int & GetObj(){
//        return val;
//    }

    A & GetObj(){
        return *this;
    }
// 在此处补充你的代码
};

int main() {
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int m,n;
    A a;
    cout << a.val << endl;     //输出123
    while(cin >> m >> n) {
        a.GetObj() = m;     //m=2,此语句使得a.val=2
        //上面这一句其实可以转化成 a=m,然后再调用构造函数
        cout << a.val << endl;
        a.GetObj() = A(n);
        cout << a.val<< endl;
    }
    return 0;
}