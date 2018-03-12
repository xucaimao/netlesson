/*
程序设计实习MOOC / 程序设计与算法（一）第十二周测验(2017冬季)  
3:Set
write by xucaimao,2018-01-24 21:00,AC 2

*/

#include <cstdio>
#include <set>
using namespace std;

int main()
{
    multiset<int> st;
    set<int> stbk;//用于储存所有进入集合的元素
    freopen("in.txt","r",stdin);
    int T;
    char ord[5];
    int n;
    scanf("%d",&T);
    getchar();
    for(int t=0;t<T;t++){
        scanf("%s",ord);
        scanf("%d",&n);
        getchar();
        switch(ord[2]){
            case 'd'://add
                st.insert(n);
                stbk.insert(n);
                printf("%lu\n",st.count(n) );
                break;
            case 'l'://del
                printf("%lu\n",st.count(n) );
                st.erase(n);
                break;
            case 'k'://ask
                set<int>::iterator p;
                p=stbk.find(n);
                if( p==stbk.end() )
                    printf("0 ");
                else 
                    printf("1 ");
                printf("%lu\n",st.count(n) );

        }
    }
	return 0;
}