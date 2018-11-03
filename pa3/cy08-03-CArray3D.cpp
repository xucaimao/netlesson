/*
 程序设计实习MOOC /程序设计与算法（三）第八周测验(2018秋季)
 3:很难蒙混过关的CArray3d三维数组模板类
 write by xucaimao,2018-10-28
*/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
// 在此处补充你的代码
private:
    class CArray2D{
    public:
        int row,col;
        T* data;
    public:
        CArray2D():row(0),col(0){data=NULL;}
        void init(int r,int c){
            row=r;
            col=c;
            if(r+c)
                data=new T[r*c];
        }
        ~CArray2D(){
            if(data!=NULL)
                delete []data;
        }
        T* operator[](int r){
            return data+r*col;
        }
        operator T*(){
            return data;
        }
    };
    CArray2D* layerData;    //说明此处是指针数组
    int layer;
public:
    CArray3D(int la, int r, int c){ //开始时这里参数顺序错了导致莫名其妙的错误
        layer=la;
        layerData=new CArray2D [layer]; //此处需要用到无参构造函数
        for(int i=0;i<layer;i++)
            layerData[i].init(r,c);     //分配相应的存储空间
    }

    ~CArray3D(){
        if(layerData!=NULL)
            delete [] layerData;
    }
    //为了能作为左值
    CArray2D& operator[] (int la) {
        return layerData[la];
    }
};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 5; ++k)
                cout << a[i][j][k] << "," ;
            cout << endl;
        }
    }
}
void PrintB()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k)
                cout << b[i][j][k] << "," ;
            cout << endl;
        }
    }
}

int main()
{

    int No = 0;
    for( int i = 0; i < 3; ++ i ) {
        a[i];
        for( int j = 0; j < 4; ++j ) {
            a[j][i];
            for( int k = 0; k < 5; ++k ){
                //通过下面几句的跟踪可以对程序的内部逻辑有更清楚的了解
//                a[i];
//                a[i][j];
//                a[i][j][k];
                a[i][j][k] = No ++;
            }

            a[j][i][i];
        }
    }
    PrintA();
    //从下面两句可以看出，二维数组部分必须连续存放
    memset(a[1],-1 ,20*sizeof(int));
    //上面一句，a[1]返回的是一个CArray2D类的实例，但是memset函数的第一个参数需要的是void*类型，二者类型不匹配
    //此时就会在类定义中查找有没有与void*相匹配的类型转换函数，如果找到就执行
    PrintA();
    memset(a[1][1],0 ,5*sizeof(int));
    PrintA();

    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 2; ++j )
            for( int k = 0; k < 2; ++k )
                b[i][j][k] = 10.0/(i+j+k+1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl;

    return 0;
}