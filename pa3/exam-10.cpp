// 程序设计与算法（三）期末考试(2018秋季)
// 010:编程填空：回调函数
// Created by Administrator on 2018-11-10.
//
/*
 输入x1 x2 x3 x4 x5 ，输出y = x5^5 + x4^4 + x3^3 + x2^2 + x1^1 + 1的y的值
 * */
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;
class MyFunc
{
// 在此处补充你的代码
public:
    int exp;
    MyFunc(int e):exp(e){}
    int operator()(int m){
        int ans=1;
        for(int i=0;i<exp;i++)
            ans=ans*m;
        return ans;
    }
};
int main()
{
    freopen("F:\\xcmprogram\\netlesson\\pa3\\in.txt","r",stdin);
    int n;
    cin >> n;
    while(n--) {
        vector<MyFunc> v;
        for (int i = 0; i < 5; ++i)
            v.push_back(MyFunc(i+1));
        int ans = 1;
        for (int i = 0; i < 5; ++i)
        {
            int m;
            cin >> m;
            ans += v[i](m);
        }
        cout << ans <<endl;
    }
}