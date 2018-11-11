// 程序设计与算法（三）期末考试(2018秋季)
// 012:编程填空：Printer
// Created by Administrator on 2018-11-10.
// 考察函数对象的初始化及使用
//首先生成类 Printer 的对象，并用 n 初始化，调用for_each 时将用该函数对象进行判断。
/*
完成以下程序，使得输入的整数x，以及若干正整数，将大于x的正整数输出；
然后输入若干字符串，将字符串长度大于x的字符串输出
输入
第一行是整数t，表示一共t组数据
每组数据有三行
第一行是整数x和整数 n
第二行是n个整数
第三行是n个不带空格的字符串
输出
对每组数据
先按原序输出第一行中大于x的正整数(数据保证会有输出）
再按原序输出第二行中长度大于x的字符串 (数据保证会有输出）
样例输入
 * */

#include<iostream>
#include <string>
#include<algorithm>
#include<vector>
#include<bitset>

using namespace std;


class Printer {
// 在此处补充你的代码
private:
    int n;
public:
    Printer(int n_):n(n_){}
    void operator()(string &a){
        if(a.size()>n)
            cout<<a<<",";
    }
    void operator()(int a){
        if(a>n)
            cout<<a<<",";
    }
};
int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int t;
    cin >> t;
    while(t--) {
        int n,x;
        cin>>x>>n;

        vector<int> intVec;
        for(int i = 0;i < n; ++i) {
            int y;
            cin >> y;
            intVec.push_back(y);
        }
        for_each(intVec.begin(), intVec.end(), Printer(x));
        cout<<endl;

        vector<string> strVec;
        for(int i = 0;i < n; ++i) {
            string str;
            cin >> str;
            strVec.push_back(str);
        }
        for_each(strVec.begin(), strVec.end(), Printer(x));
        cout<<endl;
    }
    return 0;
}
