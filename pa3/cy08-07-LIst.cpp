/*
 程序设计实习MOOC /程序设计与算法（三）第八周测验(2018秋季)
 7:List
 write by xucaimao,2018-10-25
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <list>
#include <map>
using namespace std;

map<int,list<int> > m;

int n,x,y;
char op[10000];
int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    scanf("%d",&n);
    while(n--){
        scanf("%s",op);
        if(strcmp(op,"new")==0){
            scanf("%d",&x);
            m.insert(map<int,list<int> >::value_type(x,list<int>()));
        }
        if(strcmp(op,"add")==0){
            scanf("%d%d",&x,&y);
            m[x].push_back(y);
        }
        if(strcmp(op,"merge")==0){
            scanf("%d%d",&x,&y);
            m[x].merge(m[y]);
            //m[y].clear();
        }
        if(strcmp(op,"unique")==0){
            scanf("%d",&x);
            m[x].sort();
            m[x].unique();
        }
        if(strcmp(op,"out")==0){
            scanf("%d",&x);
            m[x].sort();
            list<int>::iterator it;
            for(it=m[x].begin();it!=m[x].end();it++){
                printf("%d ",*it);
            }
            printf("\n");
        }
    }
    return 0;
}