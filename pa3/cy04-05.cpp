//程序设计实习MOOC / 程序设计与算法（三）第四周测验(2018秋季)
//5:别叫，这个大整数已经很简化了!
// Created by xucaimao on 2018/9/26.
//
//C语言整形数范围(-2147483648,2147483647),
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX = 110;
class CHugeInt {
// 在此处补充你的代码
private:
    int dignum;     //实际的有效位数
    int data[25];   //按数组下标从低到高，把长整数从低位到高位，每9位存在数组的一位
public:
    CHugeInt(int n=0){
        for(int i=0;i<25;i++)
            data[i]=0;
        int dn=0;
        while(n){
            data[dn++]=n%1000000000;
            n/=1000000000;
        }
        dignum=dn;
    }

    CHugeInt(const char * s){
        //注意字符串的高地位和整数的高地位正好是相反的
        for(int i=0;i<25;i++)
            data[i]=0;
        int dn=0;
        int len=strlen(s);
        int i=len-1;    //指向最低位
        while(i>=0){
            int j=0;    //本次处理的字符数量
            int n=0;
            int dig=1;
            while(j<9 && i >=0){
                n+=(s[i]-'0')*dig;
                dig*=10;
                i--;
                j++;
            }
            data[dn++]=n;
        }
        dignum=dn;
    }

    //拷贝构造函数
    CHugeInt(const CHugeInt& c){
        dignum=c.dignum;
        for(int i=0;i<25;i++)
            data[i]=c.data[i];
    }

    friend ostream&operator<<(ostream& os,const CHugeInt& c){
        for(int i=c.dignum-1;i>=0;i--)
            os<<c.data[i];
        return os;
    }

    //这里其实是定义的一个全局重载 "+" 的函数
    friend CHugeInt operator+(const CHugeInt & a,const CHugeInt& b){
        CHugeInt t;
        int i=0,inc=0;
        while(i<a.dignum || i<b.dignum || inc){
            int dig=a.data[i]+b.data[i]+inc;
            t.data[i]=dig%1000000000;
            inc=dig/1000000000;
            i++;
        }
        t.dignum=i;
        return t;
    }

    CHugeInt&operator++(){
        int i=0,inc=1;
        while(i<dignum || inc){
            int dig=data[i]+inc;
            data[i]=dig%1000000000;
            inc=dig/1000000000;
            i++;
        }
        dignum=i;
        return *this;
    }

    CHugeInt operator++(int){
        CHugeInt t(*this); //创建当前对象的拷贝
        //当前对象加1
        int i=0,inc=1;
        while(i<dignum || inc){
            int dig=data[i]+inc;
            data[i]=dig%1000000000;
            inc=dig/1000000000;
            i++;
        }
        dignum=i;
        return t;
    }


    CHugeInt&operator+=(int n){
        int i=0,inc=n;
        while(i<dignum || inc){
            //注意这里的dig不能采用int型，否则当n为整形的极大值时，会产生溢出
            long long int dig=data[i]+inc;
            data[i]=dig%1000000000;
            inc=dig/1000000000;
            i++;
        }
        dignum=i;
        return *this;
    }

};

int  main()
{
    freopen("F:\\xcmprogram\\netlesson\\pa3\\in.txt","r",stdin);
    char s[210];
    int n;

    while (cin >> s >> n) {
        CHugeInt a(s);
        CHugeInt b(n);

        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        cout  << ++ b << endl;
        cout << b++ << endl;
        cout << b << endl;
    }
    return 0;
}