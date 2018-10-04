/*
 程序设计实习MOOC /程序设计与算法（三）第四周例题(2018秋季)
 CDemo类--运算符重载
 write by xucaimao,2018-09-23,AC at 2018-09-23
*/

#include <iostream>
using namespace std;

class CDemo{
private:
    int n;
public:
    CDemo(int i=0):n{i} {}

    CDemo &operator++(){
        ++n;
        return *this;
    }
    CDemo operator++(int){
        CDemo tmp(*this);   //记录修改前的对象
        n++;
        return tmp;
    }

    CDemo&operator--(){
        --n;
        return *this;
    }
//    friend CDemo&operator--(CDemo & c){
//        --c.n;
//        return c;
//    }

    CDemo operator--(int){
        CDemo tmp(*this);
        --n;
        return tmp;
    }
//    friend CDemo operator--(CDemo& c,int){
//        CDemo tmp(c);
//        --c.n;
//        return tmp;
//    }

    operator int(){ //把CDemo类的对象，转换成int类型值
        return n;
    }
    //上面的类型转换和下面的重载<<,二选一
//    friend ostream&operator<<(ostream & os,const CDemo & c){
//        os<<c.n;
//        return os;
//    }

    CDemo&operator+=(int i){
        n+=i;
        return *this;
    }

    CDemo&operator-=(int i){
        n-=i;
        return *this;
    }
};

int main(){
    CDemo d(5);
    cout<<(d++)<<",";
    cout<<d<<",";
    cout<<(++d)<<",";
    cout<<d<<endl;
    d+=2;
    cout<<d<<endl;

    cout<<(d--)<<",";
    cout<<d<<",";
    cout<<(--d)<<",";
    cout<<d<<endl;
    d-=2;
    cout<<d<<endl;
    return 0;
}