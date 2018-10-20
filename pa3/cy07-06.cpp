/*
 程序设计实习MOOC /程序设计与算法（三）第七周测验(2018秋季)
 6:这个模板并不难
 write by xucaimao,2018-10-20
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <class T>
class myclass {
// 在此处补充你的代码
private:
    T *p;
    int size;
public:
    myclass(T arr[],int len){
        p=new T[len+1];   //注意这里的用法
        size=len;
        for(int i=0;i<len;i++)
            p[i]=arr[i];
    }
    ~myclass( ) {
        delete [] p;
    }
    void Show()
    {
        for( int i = 0;i < size;i ++ ) {
            cout << p[i] << ",";
        }
        cout << endl;
    }
};
int a[100];
int main() {
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    char line[100];
    while( cin >> line ) {
        myclass<char> obj(line,strlen(line));;
        obj.Show();
        int n;
        cin >> n;
        for(int i = 0;i < n; ++i)
            cin >> a[i];
        myclass<int> obj2(a,n);
        obj2.Show();
    }
    return 0;
}