// 程序设计与算法（三）期末考试(2018秋季)
// 011:编程填空：前K大的偶数
// Created by Administrator on 2018-11-10.
//
/*
输入
有多组数据
第一行是数据组数 t
对每组数据：
第一行为整数n (n>=3)和k
接下来的一行为n个整数，保证这些整数中至少有k个偶数。
输出
对每组数据，输出k个整数，降序排列，表示选出来的大小排名前k的偶数
 * */

#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;
class MyQueue
{
// 在此处补充你的代码
private:
    int k;
    //注意这里的比较函数
    multiset<int,greater<int> > s;
public:
    MyQueue(int k_):k(k_){}
    friend istream&operator>>(istream& is,MyQueue & q){
        int n;
        is>>n;
        if(n%2 ==0)
            q.s.insert(n);
        return is;
    }
    void disp(){
        for(auto e:s)
            cout<<e<<" ";
        cout<<endl;
    }
    friend ostream&operator<<(ostream& os,MyQueue & q){
        //注意这里的遍历
        multiset<int,greater<int> >::iterator it;
        int i=0;
        for(it=q.s.begin();it!=q.s.end() && i<q.k;it++,i++)
            os<<*it<<" ";
        return os;
    }

};
int main()
{
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        MyQueue q(k);
        for (int i = 0; i < n; ++i)
            cin >> q;
        q.disp();
        cout<<q;
        cout << endl;
    }
    return 0;
}
