/*
 程序设计实习MOOC /程序设计与算法（三）第七周测验(2018秋季)
 4:你真的搞清楚为啥 while(cin >> n) 能成立了吗？
 write by xucaimao,2018-10-20
*/
#include <iostream>
using namespace std;
class MyCin
{
// 在此处补充你的代码
private:
    bool status;
public:
    MyCin():status(true){}
    MyCin &operator>>(int & n){
        cin>>n;
        if(n==-1)
            status=false;
        return *this;
    }

    operator bool(){
        return status;
    }
};
int main()
{
    //freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2 )
        cout  << n1 <<" "<< n2 << endl;
    return 0;
}