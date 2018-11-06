/*
 程序设计实习MOOC /程序设计与算法（三）第八周测验(2018秋季)
<<<<<<< HEAD
 3:冷血格斗场
 write by xucaimao,2018-11-01


template<class ForwardIterator,class T,class Compare>
ForwardIterator lower_bound(ForwardIterator first,ForwardIterator last,const T &val,Compare comp);
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int maxN=10;

class Player{
public:
    int id,power;
    Player(){}
    Player(int id_,int power_):id(id_),power(power_){}
};

Player data[maxN];

bool cmp(const Player &a,const Player &b){
    //先比较power值，如果power值相等再比较id值
    if(a.power<b.power) return true;
    else if(a.power == b.power ) return a.id<b.id;
    else return false;
}

bool cmp2(const Player &a,const Player &b){
    //先比较power值，如果power值相等再比较id值
    if(a.power<b.power) return true;
    else return false;
}


int main()
{
    freopen("F:\\xcmprogram\\netlesson\\pa3\\in.txt","r",stdin);
    //freopen("F:\\xcmprogram\\netlesson\\pa3\\out.txt","w",stdout);
    //first--实力值 second--id
    int id=1,power=1000000000;
    data[1]=Player(id,power);  //插入一号选手
    int i=1,n;
    cin>>n;
    while(n--){
        cin>>id>>power;
        if(id==3451430){
            cout<<"";

        }
        sort(data+1,data+i+1,cmp);  //前闭后开的区间
        for(int k=1;k<=i;k++)
            cout<<"("<<data[k].id<<","<<data[k].power<<") ";
        cout<<endl;
        // iterator lower_bound(onst T& val)查找一个最大的位置it,使得[begin(),it)
        // 中的所有元素都比val小
        int it=lower_bound(data+1,data+i,Player(id,power),cmp2)-data;
        if(it==1){}
        else if(it>i){
            --it;
        }
        else if(data[it].power ==power){
            //it为第一个等于power且id值最小的元素

        }
        else{
            //it为第一个大于power且id值最小的元素，it-1为第一个小于power且id值最大的元素
            if(abs(power - data[it].power) < abs(power - data[it-1].power)){}
            else if(abs(power - data[it-1].power) < abs(power - data[it].power))
                it--;
            else{
                //差距相等取id值小的
                if(data[it-1].id < data[it].id) it--;
            }
        }
        cout<<id<<","<<power<<": ";
        cout<<id<<" "<<data[it].id<<endl;
        data[++i]=Player(id,power); //插入新元素
    }
    return 0;
}