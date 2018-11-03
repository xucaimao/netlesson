/*
 程序设计实习MOOC /程序设计与算法（三）第八周测验(2018秋季)
 2:热血格斗场
 write by xucaimao,2018-11-01
 重点是考察map的有序性及lower_bound的使用
*/
#include <iostream>
#include <map>
using namespace std;

int main()
{
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    typedef map<int,int > mymap;
    mymap m;
    mymap::iterator it;
    //first--实力值 second--id
    int power=1000000000,id=1;
    m.insert(mymap::value_type(power,id));  //插入一号选手
    int n;
    cin>>n;
    while(n--){
        cin>>id>>power;
        // iterator lower_bound(onst T& val)查找一个最大的位置it,使得[begin(),it)
        // 中的所有元素都比val小
        it=m.lower_bound((power));
        int powpre,pownext;

        if(it!=m.begin()){
            pownext=it->first;
            --it;
            powpre=it->first;
            if(abs(power-pownext) < abs(power-powpre))
                ++it;
        }
        //这里隐藏着 it==begin()，不能it--，而应当直接输出
        cout<<id<<" "<<it->second<<endl;
        m.insert(mymap::value_type(power,id));
    }
    return 0;
}