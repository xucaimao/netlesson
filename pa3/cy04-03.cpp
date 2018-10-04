//程序设计实习MOOC / 程序设计与算法（三）第四周测验(2018秋季)
//3:惊呆！Point竟然能这样输入输出
// Created by xucaimao on 2018/9/26.
//
#include <iostream>
using namespace std;
class Point {
private:
    int x;
    int y;
public:
    Point() { };
// 在此处补充你的代码
    friend istream&operator>>(istream& is,Point & p){ //注意这里的p不能加const限定
        is>>p.x>>p.y;
        return is;
    }

    friend ostream&operator<<(ostream& os,const Point & p){
        os<<p.x<<","<<p.y;
        return os;
    }

};
int main()
{
    Point p;
    while(cin >> p) {
        cout << p << endl;
    }
    return 0;
}