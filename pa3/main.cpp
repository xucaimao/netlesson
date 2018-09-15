/*
程序拷贝进来编译执行
 //TODO
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int inc=10;

template <typename T>
class Vector {
private:

    T theSize;   //实际存贮数据的数量
    int theCapacity;//可存贮的空间容量
    int * data; //数据存贮空间
public:
    //构造函数
    explicit Vector(int initSize=0):theSize{initSize},theCapacity{initSize+inc} {
        data=new T[theCapacity];
    }
    //复制构造函数,需要采用深拷贝的形式
    Vector(const Vector& v):theSize{v.theSize},theCapacity{v.theCapacity},data{NULL}{
        data=new T[v.theCapacity];
        for(int i=0;i<theSize;i++)
            data[i]=v.data[i];
    }
    ~Vector(){
        delete[] data;
    }

    Vector &operator=(const Vector & v){
        Vector copy=v;
        std::swap(*this,copy);
        return *this;
    }

    //返回值的类型是int&
    int &operator[](int i){
        return data[i];
    }

    void push_back(int n){
            data[theSize]=n;
            theSize++;

    }

    int length(){
        return theSize;
    }
};

int main()
{
    Vector<int> a;
    for(int i=1;i<8;i++)
        a.push_back(i);//动态分配内存来存放数组，需要一个指针成员变量

        cout<<"a is: ";
    for(int i=0;i<=a.length();i++)
        cout<<a[i]<<" ";//需要重载"[]"运算符
        cout<<endl;
    Vector<int> a2,a3;
    a2=a;//需要重载"="运算符
//    cout<<"a2 is: ";
//    for(int i=0;i<=a2.length();i++)
//        cout<<a2[i]<<" ";//需要重载"[]"运算符
//        cout<<endl;
//    a2=a3;
//    cout<<"a2 is: ";
//    for(int i=0;i<a2.length();i++)
//        cout<<a2[i]<<" ";
//    cout<<endl;
//    a3[0]=100;
//    Vector<int> a4(a);//需要复制构造函数
//    for(int i=0;i<a4.length();i++)
//        cout<<a4[i]<<" ";
//    cout<<endl;
    return 0;
}