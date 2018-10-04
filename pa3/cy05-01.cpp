//程序设计实习MOOC / 程序设计与算法（三）第五周测验(2018秋季)
//1:全面的MyStrin
// Created by xucaimao on 2018/10/01.
//编译时，前面提供的字符串函数全部注释，不让不能通过编译

#include <cstdlib>
#include <iostream>
using namespace std;
//int strlen(const char * s)
//{	int i = 0;
//    for(; s[i]; ++i);
//    return i;
//}
//void strcpy(char * d,const char * s)
//{
//    int i = 0;
//    for( i = 0; s[i]; ++i)
//        d[i] = s[i];
//    d[i] = 0;
//
//}
//int strcmp(const char * s1,const char * s2)
//{
//    for(int i = 0; s1[i] && s2[i] ; ++i) {
//        if( s1[i] < s2[i] )
//            return -1;
//        else if( s1[i] > s2[i])
//            return 1;
//    }
//    return 0;
//}
//void strcat(char * d,const char * s)
//{
//    int len = strlen(d);
//    strcpy(d+len,s);
//}int strlen(const char * s)
//{	int i = 0;
//    for(; s[i]; ++i);
//    return i;
//}
//void strcpy(char * d,const char * s)
//{
//    int i = 0;
//    for( i = 0; s[i]; ++i)
//        d[i] = s[i];
//    d[i] = 0;
//
//}
//int strcmp(const char * s1,const char * s2)
//{
//    for(int i = 0; s1[i] && s2[i] ; ++i) {
//        if( s1[i] < s2[i] )
//            return -1;
//        else if( s1[i] > s2[i])
//            return 1;
//    }
//    return 0;
//}
//void strcat(char * d,const char * s)
//{
//    int len = strlen(d);
//    strcpy(d+len,s);
//}int strlen(const char * s)
//{	int i = 0;
//    for(; s[i]; ++i);
//    return i;
//}
//void strcpy(char * d,const char * s)
//{
//    int i = 0;
//    for( i = 0; s[i]; ++i)
//        d[i] = s[i];
//    d[i] = 0;
//
//}
//int strcmp(const char * s1,const char * s2)
//{
//    for(int i = 0; s1[i] && s2[i] ; ++i) {
//        if( s1[i] < s2[i] )
//            return -1;
//        else if( s1[i] > s2[i])
//            return 1;
//    }
//    return 0;
//}
//void strcat(char * d,const char * s)
//{
//    int len = strlen(d);
//    strcpy(d+len,s);
//}
class MyString
{
// 在此处补充你的代码
private:
    char * str;
    int len;    //有效字符的长度，不包含末尾的'\0'
public:
    //类型转换、无参构造函数
    MyString(const char * s=""){
        len=strlen(s);
        str=new char[len+1];    //加上末尾'\0'的空间
        strcpy(str,s);      //注意strcpy函数，最后的'\0'被一起复制
    }

    //拷贝构造函数
    MyString(const MyString & s){
        len=s.len;
        str=new char[len+1];
        strcpy(str,s.str);
    }

    //定义的全局函数
    friend ostream&operator<<(ostream& os,const MyString & s){
        os<<s.str;
        return os;
    }
    MyString &operator=(const MyString & s){
        if(this != &s){     //避免自身拷贝
            delete[]str;
            len=s.len;
            str=new char[len+1];
            strcpy(str,s.str);
        }
        return *this;
    }
    ~MyString(){
        delete[] str;
    }

    //定义的全局函数
    friend MyString operator+(const MyString & a,const MyString & b){
        MyString t;
        t.len=a.len+b.len;
        t.str=new char[t.len+1];
        strcpy(t.str,a.str);
        strcat(t.str,b.str);
        return t;
    }
    MyString&operator+=(const char *s){
        MyString t(*this);
        len+=strlen(s);
        delete[]str;
        str=new char[len+1];
        strcpy(str,t.str);
        strcat(str,s);
        return *this;
    }

    MyString operator()(int s,int l){
        char * t_str=new char[l+1];
        for(int i=s,j=0;str[i] && j<l;)
            t_str[j++]=str[i++];
        t_str[l]='\0';
        MyString tmp(t_str);
        return tmp;
    }

    bool  operator<(const MyString & b){
        if( strcmp(str,b.str) == -1) return true;
        else return false;
    }

    bool operator>(const MyString & b){
        if( strcmp(str,b.str) == 1) return true;
        else return false;
    }

    bool operator==(const MyString & b){
        if( strcmp(str,b.str) == 0) return true;
        else return false;
    }

    char &operator[](int i){
        return str[i];
    }

};

int CompareString( const void * e1, const void * e2) {
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( * s1 < *s2 )
        return -1;
    else if( *s1 == *s2)
        return 0;
    else if( *s1 > *s2 )
        return 1;
}


int main()
{
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString),CompareString);
    for( int i = 0;i < 4;i ++ )
        cout << SArray[i] << endl;
    //cout<<"s1 is: "<<s1<<endl;
    //s1的从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //s1的从下标5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}