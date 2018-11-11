// 程序设计与算法（三）期末考试(2018秋季)
// 015:编程填空：矩形排序
// Created by Administrator on 2018-11-10.
//
/*
 给定一系列边长已知的矩形，输出对矩形进行两种排序的结果。
 在第一种排序中，先按矩形的面积从大到小排序；若两个矩形的面积相同，则周长大的排在前。
 在第二种排序中，先按矩形的周长从小到大排序；若两个矩形的周长相同，则面积小的排在前。
 * */
#include <iostream>
#include <set>
using namespace std;
// 在此处补充你的代码

class Rectangle{
public:
    int w,h;
    int area,perimeter;
public:
    Rectangle(int w_,int h_):w(w_),h(h_){
        area=w*h;
        perimeter=(w+h)*2;
    }
};

ostream&operator<<(ostream &os,const Rectangle & a){
    os<<a.area<<" "<<a.perimeter;
    return os;
}
bool operator<(const Rectangle &a,const Rectangle &b){
    if(a.area>b.area)return true;
    else if(a.area==b.area) return a.perimeter>b.perimeter;
    else return false;
}
//重点是这个自定义比较函数类
class Comp{
public:
    bool operator()(const Rectangle &a,const Rectangle &b)const {
        if(a.perimeter<b.perimeter)return true;
        else if(a.perimeter==b.perimeter) return a.area<b.area;
        else return false;
    }
};

int main() {
    freopen("F:\\xcmprogram\\netlesson\\pa3\\in.txt","r",stdin);
    freopen("F:\\xcmprogram\\netlesson\\pa3\\out.txt","w",stdout);
    multiset<Rectangle> m1;
    multiset<Rectangle, Comp> m2;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m1.insert(Rectangle(a, b));
        m2.insert(Rectangle(a, b));
    }
    for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}