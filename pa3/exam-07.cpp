// 程序设计与算法（三）期末考试(2018秋季)
// 007:编程填空：按要求输出
// 下列程序的输出为"10 13 18 15 17 12 16 19",
// Created by Administrator on 2018-11-10.
//
#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <set>
using namespace std;
int  a[10] = {0, 6, 7, 3, 9, 5, 8, 6, 4, 9};
int  b[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int main(int argc, char** argv) {
// 在此处补充你的代码
    map<int,int > c;
    map<int,int >::iterator it;

    for(int i=0; i<10; i++)
        c[a[i]] = b[i];
    for(it=c.begin(); it!=c.end(); it++)
        cout<<it->second<<" ";
    return 0;
}