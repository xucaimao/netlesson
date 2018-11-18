/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 11-散列3 QQ帐户的申请与登陆 （25 分）
 * wirte by xucaimao,2018-11-13
 把聊天狂人的程序简单修改了一下，一次通过，爽！！！
 * */
#include <iostream>
#include <string>
#include <cmath>
#include <set>
using namespace std;
const int maxN=100000+10;
//分离链接法
class PhoneHash{
private:
    struct Node{
        long long int number;
        string password;
        Node* next;
        Node(long long int n,string p):number(n){
            number=n;
            password=p;
            next=NULL;
        }
    };
    Node** data;    //定义一个Node* 类型的指针数组
    int TableSize;

    bool isPrime(int n){
        //判断2之后，就可以判断从3到sqrt(n)之间的奇数了，无需再判断之间的偶数
        if(n<2)return false;
        if(n==2)return true;
        if(n%2==0)
            return false;
        int sn=sqrt(n);
        for(int i=3;i<sn;i+=2)
            if(n%i ==0)return false;
        return true;
    }
    //返回比n大的最小素数
    int nextPrime(int n){
        while(!isPrime(n))
            n++;
        return n;
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
    }
    ~PhoneHash(){
        //先删除所有的链表，再删除数组本身
        for(int i=0;i<TableSize;i++)
            delNode(data[i]);
        delete [] data;
    }
    //查找号码，如果号码已经在表内，则返回指针，否则返回NULL
    Node* find(long long int num){
        Node* p=data[num%TableSize]; //用后五位作为关键值
        while(p){
            if(p->number == num)return p;
            p=p->next;
        }
        return NULL;
    }
    void newUser(long long int num,string psw){
        Node *p=find(num);
        if(p){
            cout<<"ERROR: Exist"<<endl;
        }
        else{
            int i=num%TableSize;
            p=new Node(num,psw);
            p->next=data[i];
            data[i]=p;
            cout<<"New: OK"<<endl;
        }
    }

    void login(long long int num,string psw){
        Node *p=find(num);
        if(p){
            if(p->password == psw)
                cout<<"Login: OK"<<endl;
            else cout<<"ERROR: Wrong PW"<<endl;
        }
        else
            cout<<"ERROR: Not Exist"<<endl;
    }
};

int main(){
    freopen("F:\\xcmprogram\\netlesson\\ds-zju\\in.txt","r",stdin);
    int Case;
    long long int n;
    string s;
    char ord;
    PhoneHash phash;
    cin>>Case;
    while(Case--){
        cin>>ord>>n>>s;
        if(ord=='N') phash.newUser(n,s);
        if(ord=='L') phash.login(n,s);
    }
    return 0;
}