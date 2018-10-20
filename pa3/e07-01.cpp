/*
 程序设计实习MOOC /程序设计与算法（三）第七周测验(2018秋季)
 1:简单的SumArray
 write by xucaimao,2018-10-20
*/
#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(T * s,T* e){
    T ans=*s;
    T* p=s+1;
    for(;p!=e;p++)
        ans+=*p;
    return ans;
}

int main() {
    string array[4] = { "Tom","Jack","Mary","John"};
    cout << SumArray(array,array+4) << endl;
    int a[4] = { 1, 2, 3, 4};  //提示：1+2+3+4 = 10
    cout << SumArray(a,a+4) << endl;
    return 0;
}