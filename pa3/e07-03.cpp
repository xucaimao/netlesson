/*
 程序设计实习MOOC /程序设计与算法（三）第七周测验(2018秋季)
 3:简单的Filter
 write by xucaimao,2018-10-20
*/
#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
template <typename TP,typename OP>
TP Filter(TP p1,TP p2,TP tar,OP op){
    for(p1;p1!=p2;p1++){
        if(op(*p1)){
            *tar=*p1;
            tar++;
        }
    }
    return tar;
}
bool LargerThan2(int n)
{
    return n > 2;
}
bool LongerThan3(string s)
{
    return s.length() > 3;
}

string as1[5] = {"Tom","Mike","Jack","Ted","Lucy"};
string as2[5];
int  a1[5] = { 1,2,3,4,5};
int a2[5];
int main() {
    string * p = Filter(as1,as1+5,as2,LongerThan3);
    for(int i = 0;i < p - as2; ++i)
        cout << as2[i];
    cout << endl;
    int * p2 = Filter(a1,a1+5,a2,LargerThan2);
    for(int i = 0;i < p2-a2; ++i)
        cout << a2[i] << ",";
    return 0;
}