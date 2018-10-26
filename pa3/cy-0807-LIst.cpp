/*
 程序设计实习MOOC /程序设计与算法（三）第八周测验(2018秋季)
 7:List
 write by xucaimao,2018-10-25
*/
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
typedef map<int,list<int>> myMap;
myMap m;

int main()
{
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int n;
    cin>>n;
    myMap::iterator it;
    myMap::iterator it2;
    while(n--){
        char cmd[10];
        int id,num;
        cin>>cmd;
        if(cmd[0]=='n'){
            cin>>id;
            m.insert(myMap::value_type( id,list<int>() ) );
        }
        else if(cmd[0]=='a'){
            cin>>id>>num;
            it=m.find(id);
            if( it!=m.end() )
                it->second.push_back(num);
        }
        else if(cmd[0]=='o'){
            cin>>id;
            it=m.find(id);
            if( it!=m.end() ){
                it->second.sort();
                list<int>::iterator i;
                for(i=it->second.begin();i!=it->second.end();i++)
                    cout<<*i<<" ";
                cout<<endl;
            }

        }
        else if(cmd[0]=='m'){
            int id1,id2;
            cin>>id1>>id2;
            it=m.find(id1);
            it2=m.find(id2);
            if( it!=m.end() && it2!=m.end() ){
                m[id1].sort();
                m[id2].sort();
                m[id1].merge(m[id2]);
            }
        }
        else if(cmd[0]=='u'){
            cin>>id;
            it=m.find(id);
            if( it!=m.end() )
                it->second.unique();
        }
    }
    return 0;
}