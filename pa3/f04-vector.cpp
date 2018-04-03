/*
 程序设计实习MOOC /程序设计与算法（三）第四周例题(2018春季)
 004:可变长数组的实现
 write by xucaimao,2018-03-27,AC
 TODO
*/
#include <iostream>
using namespace std;
class CArray {
private:
    int * data;
    int size;
    int minsize=100,inc=20;
public:
    int i;
    //构造函数
    CArray(int s=minsize):data(new int[s]){}
    //复制构造函数
    CArray(const CArray & s){

    }
    ~CArray(){
        delete data;
    }

    //返回值的类型是int&
    int &operator[](int i){
        return data[i];
    }

    void push_back(int n){

    }

    int length(){
        return size;
    }
};
int main()
{
    CArray a;
    for(int i=0;i<5;i++)
        a.push_back(i);//动态分配内存来存放数组，需要一个指针成员变量
    CArray a2,a3;
    a2=a;//需要重载"="运算符
    for(int i=0;i<5;i++)
        cout<<a2[i]<<" ";//需要重载"[]"运算符
    a2=a2;
    for(int i=0;i<a2.length();i++)
        cout<<a2[i]<<" ";
    cout<<endl;
    a3[0]=100;
    CArray a4(a);//需要复制构造函数
    for(int i=0;i<a4.length();i++)
        cout<<a4[i]<<" ";
    cout<<endl;
    return 0;
}