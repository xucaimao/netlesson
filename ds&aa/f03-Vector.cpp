// vector的实现
// Created by xcm on 2018/9/16.
//

#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

const int SPARE_CAPACITY=10;

template <typename T>
class Vector{
private:
    int theSize;    //有效数据数量
    int theCapacity;//容量
    T* data;        //数据存储空间
public:
    //构造函数
    explicit Vector(int initSize=0):theSize{initSize},theCapacity{initSize+SPARE_CAPACITY}
    {
        data=new T[theCapacity];
    }
    //拷贝构造函数
    Vector(const Vector& rhs):theSize{rhs.theSize},theCapacity{rhs.theCapacity},data{NULL}
    {
        data=new T[theCapacity];
        for(int i=0;i<theSize;i++)
            data[i]=rhs.data[i];
    }
    //重载=运算符
    Vector &operator=(const Vector& rhs){
        Vector copy = rhs;
        std::swap(*this,copy);
        return *this;
    }

    ~Vector(){
        delete[] data;
    }
    //只能索引 vector 中已经存在的元素，此处需要增加判断
    T& operator[](int idx){
        assert(idx>0 && idx<theSize);
        return data[idx];
    }

    bool empty()const{
        return theSize==0;
    }

    int size()const{
        return theSize;
    }
    int capacity()const{
        return theCapacity;
    }
    //reserve改变数组空间的大小，改小时不能小于数组已存数据的空间
    void reserve(int newCapacity){
        if(newCapacity<theSize)
            return;
        T* newData=new T[newCapacity];//分配新的空间
        for(int i=0;i<theSize;i++)//复制数据
            newData[i]=data[i];
        theCapacity=newCapacity;
        T* old=data;
        data=newData;
        delete[] old;
    }

    void push_back(const T& x){
        if(theSize==theCapacity)        //判断空间是否满了
            reserve(2*theCapacity);     //扩容二倍
        data[theSize++]=x;
    }

    void pop_back(){
        theSize--;
    }

    const T& back()const {
        return data[theSize-1];
    }

    void print(){
        cout<<"size is: "<<theSize<<" ; capacity is: "<<theCapacity<<endl;
        if(theSize==0){
            cout<<"[EMPTY]"<<endl;
            return;
        }
        for(int i=0;i<theSize;i++){
            if(i>0) cout<<" ";
            cout<<data[i];
        }
        cout<<endl;
    }

    void resize(int newSize){
        if(newSize>theCapacity)
            reserve(newSize);
        theSize=newSize;
    }
};

int mymain() {
    Vector<int> a;
    a.print();
    for(int i=1;i<=10;i++)a.push_back(i);
    a.print();
    for(int i=1;i<=5;i++)a.push_back(i);
    a.print();
    a[14]=16;
    a.print();
    return 0;
}