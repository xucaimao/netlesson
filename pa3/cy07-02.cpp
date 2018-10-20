/*
 程序设计实习MOOC /程序设计与算法（三）第七周测验(2018秋季)
 2:简单的foreach
 write by xucaimao,2018-10-20
*/
#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
template <typename PT,typename OP>
void MyForeach(PT p1,PT p2,OP op){
    for(;p1!=p2;p1++)
        op(*p1);
}

void Print(string s)
{
    cout << s;
}
void Inc(int & n)
{
    ++ n;
}
string arr[100];
int a[100];
int main() {
    //freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int m,n;
    while(cin >> m >> n) {
        for(int i = 0;i < m; ++i)
            cin >> arr[i];
        for(int j = 0; j < n; ++j)
            cin >> a[j];
        MyForeach(arr,arr+m,Print);
        cout << endl;
        MyForeach(a,a+n,Inc);
        for(int i = 0;i < n; ++i)
            cout << a[i] << ",";
        cout << endl;
    }
    return 0;
}