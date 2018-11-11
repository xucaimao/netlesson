// 程序设计与算法（三）期末考试(2018秋季)
// 001:编程填空：二进制输出
// Created by Administrator on 2018-11-10.
//
/*
 给出一个int表示范围内的正整数x，输出其二进制表示。一共要输出31位，不足处要补0。
输入
 第一行是整数n(n<15)，表示有n个正整数要处理
 第二行是n个正整数
输出
 对每个给出的正整数，输出其二进制表示。不足31位则用0补齐到31位
 * */
#include <iostream>
#include <string>
using namespace std;
string dec2bin(int x){
// 在此处补充你的代码
    char an[32];
    an[31]='\0';
    int i=30;
    char c;
    int dig;
    while(i>=0){
        dig= x & 1;
        c='0'+dig;
        x=x>>1;
        an[i--]=c;
    }
    string ans(an);
    return ans;
}
int main(){
    freopen("F:\\xcmprogram\\netlesson\\pa3\\in.txt","r",stdin);
    freopen("F:\\xcmprogram\\netlesson\\pa3\\out2.txt","w",stdout);
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        cout << dec2bin(x) << endl;
    }
    return 0;
}

