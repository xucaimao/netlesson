//程序设计实习MOOC / 程序设计与算法（三）第四周测验(2018秋季)
//1:MyString
// Created by xucaimao on 2018/9/26.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString {
    char * p;
public:
    //类型转换构造函数
    MyString(const char * s) {
        if( s) {
            p = new char[strlen(s) + 1];
            strcpy(p,s);
        }
        else
            p = NULL;

    }
    ~MyString() { if(p) delete [] p; }
// 在此处补充你的代码
    //拷贝构造函数
    MyString(const MyString& mstr){
        //当前对象刚生成，所以不需要判断是否为自身赋值
        if( mstr.p ) {
            p = new char[strlen(mstr.p) + 1];
            strcpy(p,mstr.p);
        }
        else
            p = NULL;
    }

    MyString & Copy(const char * s){
        if(p) delete [] p;
        if( s ) {
            p = new char[strlen(s) + 1];
            strcpy(p,s);
        }
        else
            p = NULL;
        return *this;
    }

    MyString &operator=(const MyString & mstr){
        //判断是否为自身赋值
        if(this == &mstr) return *this ;//注意这一句的写法：判断两个对象的地址是否一致

        if(p) delete [] p;
        if( mstr.p ) {
            p = new char[strlen(mstr.p) + 1];
            strcpy(p,mstr.p);
        }
        else
            p = NULL;
        return *this;
    }

    MyString &operator=(const char * s){
        if( s) {
            p = new char[strlen(s) + 1];
            strcpy(p,s);
        }
        else
            p = NULL;
        return *this;
    }

    //这里定义的其实是全局函数
    friend ostream&operator<<(ostream& os, const MyString & s){
        os<<s.p;
        return os;
    }

};

int main()
{
//    freopen("F:\\xcmprogram\\netlesson\\pa3\\in.txt","r",stdin);
    char w1[200],w2[100];
    while( cin >> w1 >> w2) {
        MyString s1(w1);
        //下面一条语句，是对象定义初始化，只会调用构造函数，不会调用重载后的赋值语句
        MyString s2 = s1;   //如果不定义拷贝构造函数，会导致s2和s1指向同一片内存空间，会有很多隐患
        MyString s3(NULL);
        s3.Copy(w1);
        cout << s1 << "," << s2 << "," << s3 << endl;

        s2 = w2;
        s3 = s2;
        s1 = s3;
        cout << s1 << "," << s2 << "," << s3 << endl;

    }
}