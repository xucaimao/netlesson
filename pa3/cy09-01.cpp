/*
 程序设计实习MOOC /程序设计与算法（三）第八周测验(2018秋季)
 1:Set
 write by xucaimao,2018-10-28
*/
#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> s;    //用于记录插入的元素（有重复）
    set<int> sadd;  //用于记录插入过的元素（不能有重复）
    multiset<int>::iterator it;
    set<int>::iterator its;
    char ord[100];
    int m,n;

    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    cin>>n;
    while(n--){
        cin>>ord>>m;
        if(ord[1]=='d'){
            s.insert(m);
            sadd.insert(m);
            cout<<s.count(m)<<endl; //犯迷糊写成s.size()
        }
        else if(ord[1]=='s'){
            its=sadd.find(m);
            if(its!=sadd.end()){
                cout<<"1 "<<s.count(m)<<endl;
            }
            else{
                cout<<"0 "<<s.count(m)<<endl;
            }
        }
        else if(ord[1]=='e'){
            cout<<s.count(m)<<endl;
            s.erase(m);
        }
    }

    return 0;
}