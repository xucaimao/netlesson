/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 11-散列1 电话聊天狂人 （25 分）
 * wirte by xucaimao,2018-11-13
 给定大量手机用户通话记录，找出其中通话次数最多的聊天狂人。
 输入格式:
 输入首先给出正整数N（≤10^5），为通话记录条数。随后N行，每行给出一条通话记录。简单起见，
 这里只列出拨出方和接收方的11位数字构成的手机号码，其中以空格分隔。
 输出格式:
 在一行中给出聊天狂人的手机号码及其通话次数，其间以空格分隔。如果这样的人不唯一，则输出
 狂人中最小的号码及其通话次数，并且附加给出并列狂人的人数。
 * */
#include <iostream>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
const int maxN=200000+10;
//分离链接法
class PhoneHash{
private:
    struct Node{
        long long int number;
        int time;
        Node* next;
        Node(long long int n):number(n){
            time=1;
            next=NULL;
        }
    };
    Node** data;    //定义一个Node* 类型的指针数组
    int TableSize;
    int maxTime;            //用于记录最大次数
    int personWithSameMaxTime;
    set<long long int>  record;  //用于记录相同次数的最小号码

    bool isPrime(int n){
        //判断2之后，就可以判断从3到sqrt(n)之间的奇数了，无需再判断之间的偶数
        if(n%2==0)
            return false;
        int sn=sqrt(n);
        for(int i=3;i<sn;i+=2)
            if(n%i ==0)return false;
        return true;
    }
    //返回比n大的最小素数
    int nextPrime(int n){
        while(n++){
            if(isPrime(n))return n;
        }
        return 0;
    }

    void delNode(Node* p){
        //递归删除链表的所有节点
        if(p==NULL)
            return ;
        delNode(p->next);
        delete p;
    }

public:
    PhoneHash(){
        //TableSize：比最大数据数量大的，最小质数
        TableSize=nextPrime(maxN);
        data=new Node*[TableSize]{NULL};
        personWithSameMaxTime=0;
        maxTime=0;
    }
    ~PhoneHash(){
        //先删除所有的链表，再删除数组本身
        for(int i=0;i<TableSize;i++)
            delNode(data[i]);
        delete [] data;
    }
    //查找号码，如果号码已经在表内，则返回指针，否则返回NULL
    Node* find(long long int num){
        Node* p=data[(num%100000)%TableSize]; //用后五位作为关键值
        while(p){
            if(p->number == num)return p;
            p=p->next;
        }
        return NULL;
    }
    void insert(long long int num){
        Node *p=find(num);
        if(p){
            p->time++;    //找到直接修改次数
            //cout<<num<<" called again, it's time is : "<<p->time<<endl;
        }
        else{
            int i=(num%100000)%TableSize;
            p=new Node(num);
            p->next=data[i];
            data[i]=p;
            //cout<<num<<" called first, it's time is : "<<p->time<<endl;
        }
        //开始判断最大值
        if(p->time > maxTime){
            //出现一个大值，更改最大值，清空号码记录
            record.clear();
            maxTime=p->time;
            personWithSameMaxTime=1;
            record.insert(p->number);
        }
            //出现相同值，记录
        else if(p->time == maxTime){
            record.insert(p->number);
            personWithSameMaxTime++;
        }

    }

    void cacu(){
        //可以修改为打印所有相同最大次数的电话号码
//        cout<<"All number with "<<maxTime<<" is:"<<endl;
//        for(auto e:record)
//            cout<<e<<" ";
//        cout<<endl;
        cout<< *record.begin()<<" "<<maxTime;
        //开始没看清楚题目，少了下面这句。粗心害死人！！！
        if(personWithSameMaxTime>1)
            cout<<" "<<personWithSameMaxTime;
        cout<<endl;
    }
};

int main(){
    freopen("F:\\xcmprogram\\netlesson\\ds-zju\\in.txt","r",stdin);
    int Case;
    long long int n1,n2;
    PhoneHash phash;
    cin>>Case;
    while(Case--){
        cin>>n1>>n2;
        phash.insert(n1);
        phash.insert(n2);
    }
    phash.cacu();
    return 0;
}