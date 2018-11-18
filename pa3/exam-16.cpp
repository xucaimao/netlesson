// 程序设计与算法（三）期末考试(2018秋季)
// 016:编程填空：维护平面点
// Created by Administrator on 2018-11-10.
//
/*
序填空，一开始平面上一个点都没有
每次可以插入一个点，删除一个已经存在的点，或者按照x 或y 来查询一个存在的点
保证任何时候任意两个点一定是一个点严格在另一个点的右下方
即两点(x1, y1), (x2, y2)，必定有x1 > x2 且y1 < y2 ，或者x1 < x2 且y1 > y2
输入
输入数据的每一行，格式为以下之一：
A x y
R x y
Qx x
Qy y
其中 x 与 y 都是 0 到 10^9 之间的整数
A x y 表示插入点 (x, y)
R x y 表示删除点 (x, y)，保证存在
Qx x 表示在当前所有点中，找到第一维为x的点，输出其第二维的值，保证存在
Qy y 表示在当前所有点中，找到第二维为y的点，输出其第一维的值，保证存在
总共操作数不超过100000
输出
对于每一个 Qx 和 Qy 操作，输出一行表示对应的答案

 * */
#include <set>
#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
class myComp{
public:
    //重点是三个const的使用，以及判断条件的建立
    bool operator()(const pair<int,int> &a,const pair<int,int> &b) const{
        //头两句用于lower_bound的特殊点x=-1 y=-1进行排序使用的
        if(a.first==-1 || b.first==-1)return a.second>b.second;
        if(a.second==-1 || b.second==-1)return a.first<b.first;
        //用于set内的普通节点排序
        if(a.first<b.first)return a.second>b.second;
        return false;
    }
};

int main() {
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    string cmd;
    set<pair<int, int>, myComp> S;
    while (cin >> cmd) {
        if (cmd == "A") {
            int x, y;
            cin >> x >> y;
            S.insert(make_pair(x, y));
            //自己增加的输出语句
            cout<<"After insert:"<<endl;
            for(auto e:S)
                cout<<"["<<e.first<<","<<e.second<<"] ";
            cout<<endl;
        } else if (cmd == "Qx") {
            int x;
            cin >> x;
            cout << S.lower_bound(make_pair(x, -1))->second << endl;
        } else if (cmd == "Qy") {
            int y;
            cin >> y;
            cout << S.lower_bound(make_pair(-1, y))->first << endl;
        } else {
            int x, y;
            cin >> x >> y;
            S.erase(make_pair(x, y));
            cout<<"After erase:"<<endl;
            for(auto e:S)
                cout<<"["<<e.first<<","<<e.second<<"] ";
            cout<<endl;
        }
    }
    return 0;
}