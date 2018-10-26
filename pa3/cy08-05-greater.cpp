/*
 程序设计实习MOOC /程序设计与算法（三）第八周测验(2018秋季)
 5:白给的list排序
 write by xucaimao,2018-10-25
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int main()
{
    double a[] = {1.2,3.4,9.8,7.3,2.6};
    list<double> lst(a,a+5);
    lst.sort(greater<double>());//重点是考察greater的用法

    for(list<double>::iterator i  = lst.begin(); i != lst.end(); ++i)
        cout << * i << "," ;
    return 0;
}