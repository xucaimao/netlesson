/*
程序设计实习MOOC / 程序设计与算法（一）第十二周测验(2017冬季)  
4:热血格斗场
write by xucaimao,2018-01-24 21:40,AC 2
每一个新入会的会员，只能和已经入会的会员进行比赛
*/

#include <cstdio>
#include <set>
using namespace std;
struct Player{
    int id,power;
    bool operator < (const Player & b)const{
        return power<b.power;
    }
};

int main()
{
    set<Player> st;
    freopen("in.txt","r",stdin);
    int T;
    int id,power;
    Player pl;
    pl.id=1;
    pl.power=1000000000;
    st.insert(pl);//facer入会
    scanf("%d",&T);

    for(int t=0;t<T;t++){
        scanf("%d%d",&id,&power);
        pl.id=id;
        pl.power=power;
        st.insert(pl);//新会员入会
        printf("%d ", id);

        set<Player>::iterator p,pre,next;
        p=st.find(pl);
        if( p==st.begin() ){//指向第一个元素，即没有比他小的
            p++;
            printf("%d\n",p->id );
        }
        else{
            pre=st.find(pl);
            pre--;//指向小一位的元素
            next=st.find(pl);
            next++;//指向大一位的元素
            int d1,d2;
            d1=power - (pre->power);
            d2=(next->power) - power;
            if(d1<=d2)
                printf("%d\n",pre->id );
            else
                printf("%d\n",next->id );
        }
        
    }

	return 0;
}