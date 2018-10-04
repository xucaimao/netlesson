//程序设计实习MOOC / 程序设计与算法（三）第四周测验(2018秋季)
//4:写一个二维数组类 Array2
// Created by xucaimao on 2018/9/26.
//
#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
private:
    int row,col;
    int **data; //指针数组
public:
    Array2(int r=0,int c=0){
        row=r;
        col=c;
        if(r+c){
            data=new int*[row];     //先分配行指针数组的空间
            for(int r=0;r<row;r++)
                data[r]=new int[col];//再分配具体元素的空间
        }
        else data=NULL;
    }

    ~Array2(){
        if(data){
            for(int r=0;r<row;r++)
                delete[] data[r];   //先删除实际的数据空间
            delete[] data;          //再删除指针数组的空间
            data=NULL;
        }
    }

    int &operator()(const int r,const int c){
        return data[r][c];
    }

    //注意下面的返回值类型，不能用 int&
    //对于data[r][c]，data[r]先返回一个指针，指向所在行的头地址，
    int *operator[](const int r){
        return data[r]; //data[r]=*(data+r)
    }

    Array2&operator=(const Array2& a){
        if(this == &a)return *this; //防止自身赋值
        if(data){
            //释放自身的空间
            for(int r=0;r<row;r++)
                delete[] data[r];
            delete[] data;
            data=NULL;
        }
        if(a.data){
            //先分配空间
            data=new int*[a.row];
            for(int r=0;r<a.row;r++)
                data[r]=new int[a.col];
            //开始数据复制
            for(int r=0;r<a.row;r++)
                for(int c=0;c<a.col;c++)
                    data[r][c]=a.data[r][c];
        }
        return *this;
    }

};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}