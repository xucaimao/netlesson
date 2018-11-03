/*
 程序设计实习MOOC /程序设计与算法（三）第八周测验(2018秋季)
 23:冷血格斗场
 write by xucaimao,2018-11-01
 重点是考察multimap的有序性及lower_bound的使用，防止越界是重点
*/
#include <iostream>
#include <map>
using namespace std;

int main()
{
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/out.txt","w",stdout);
    typedef multimap<int,int> mmap;
    mmap m;
    mmap::iterator it;
    mmap::iterator itmax,itmin,itp;
    //first--实力值 second--id
    int power=1000000000,id=1;
    m.insert(mmap::value_type(power,id));  //插入一号选手
    int n,powerpre,powernext;
    cin>>n;
    while(n--){
        cin>>id>>power;
        if(id==318449){
            //cout<<"have break"<<endl;
        }
        // iterator lower_bound(onst T& val)查找一个最大的位置it,使得[begin(),it)
        // 中的所有元素都比val小
        it=m.lower_bound((power));

        if( it==m.begin()){
            //此时指向第一个相等或大于的元素
            int power_=it->first;
            for(itp=it;itp!=m.end() && itp->first==power_;itp++){
                if(itp->second < it->second)
                    it=itp; //记录相等power值的元素中，id值最小的元素
            }
        }
        else if(it==m.end()){
            //此时指向最后一个小于的元素的后面
            it--;
            int power_=it->first;
            for(itp=it; itp!=m.begin() && itp->first==power_;itp--){  //遍历重复元素
                if(itp->second < it->second)
                    it=itp;
            }

        }
        else if( it->first == power){
            //此时指向第一个相等的元素
            int power_=it->first;
            for(itp=it;itp!=m.end() && itp->first==power_;itp++){
                if(itp->second < it->second)
                    it=itp; //记录相等power值的元素中，id值最小的元素
            }
        }
        else{
            //此时it指向比power大的第一个元素
            int power_=it->first;
            itmax=it;
            for(itp=it; itp!=m.end() && itp->first==power_;itp++){  //遍历重复元素
                if(itp->second < itmax->second)
                    itmax=itp;
            }
            //此时itmax指向比power大，且序号最小的元素

            --it;//指向比power小的最后一个元素
            power_=it->first;
            itmin=it;
            for(itp=it;itp!=m.begin() && itp->first==power_;itp--){
                if(itp->second < itmin->second)
                    itmin=itp;
            }

            //此时itmin指向小值中序号最小的
            //下面对大值与小值再进行比较
            if(itmax!=m.end()){
                //此时大值才有意义
                if(abs(power - itmax->first) < abs(power - itmin->first))
                    it=itmax;
                else if(abs(power - itmin->first) < abs(power - itmax->first))
                    it=itmin;
                else{
                    //差距相等
                    if(itmin->second < itmax->second) it=itmin;
                    else it=itmax;
                }
            }

        }
        cout<<id<<" "<<it->second<<endl;
        m.insert(mmap::value_type(power,id));
    }
    return 0;
}