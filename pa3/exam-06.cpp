// 程序设计与算法（三）期末考试(2018秋季)
// 006:编程填空：去除重复元素排序
// Created by Administrator on 2018-11-10.
//
/*
 C++可以使用copy函数输出容器(container)中的元素, 可以代替for循环.
 头文件:
 #include <algorithm>
 #include <iterator>
 格式:
 std::copy(cont.begin(), cont.end(),std::ostream_iterator<Type>(std::cout, " "));
 Type是需要输出格式的类型, 如容器是vector<int>, 则Type是int.
*/

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

int main() {
    freopen("F:\\xcmprogram\\netlesson\\pa3\\in.txt","r",stdin);
    int t;
    int  a[100];
    cin >> t;
    while(t--) {
        for(int i = 0;i < 12; ++i)
            cin >> a[i];
// 在此处补充你的代码
        set<int> b;
        for(int i = 0;i < 12; ++i){
            b.insert(a[i]);
        }
        auto c= std::ostream_iterator<int>(std::cout," ");

        std::copy(b.begin(), b.end(), c);
        cout << endl;

    }
    return 0;
}