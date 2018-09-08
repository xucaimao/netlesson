/*
 程序设计实习MOOC /程序设计与算法（三）第三周测验(2018春季)
 5:
 write by xucaimao,2018-04-03,AC
*/
//TODO
#define Red=0;
#define Blue=1;
#include <iostream>
using namespace std;

char RedSq[5]={'i','l','w','n','d'};//红军士兵制造顺序
char BlueSq[5]={'l','d','n','i','w'};//蓝军士兵制造顺序
char MSq[5]={'d','n','i','l','w'};//生命力初始值的输入顺序
int ord[2][5]={{2,3,4,1,0},{3,0,1,2,4}};

class Warrior{
public:
    int number,life,attack;
    char type;
    Warrior(int n,int l,int a,char t)
            :number(n),lift(l),attack(a),type(t){}

};

class Headquarter{
public:
    int knum;//制造的士兵总数,也就是士兵编号
    int lifematter;//初始生命元
    int warrior[5];//分别保存五种武士的数量
    char sq[5];//武士的制造顺序
    int lm[5];//每种武士所需要的生命力值,与武士顺序相对应
    int cur;//当前制造的士兵顺序
    bool enable;//能否制造士兵的标志
    //构造函数，初始生命元为m，制造顺序为s[]，每种士兵所需要的生命力，红蓝军:0-红 1-蓝
    Headquarter(int m,const char s[],const int m[],int side){
        knum=0;
        lifematter=m;
        enable=1;
        cur=0;
        for(int i=0;i<5;i++){
            sq[i]=s[i];
            lm[i]=m[ ord[side][i] ];//输入顺序与实际顺序转换
            warrior[i]=0;
        }
    }
    bool MakeWarrior(){
        int ok=0;
        if()
    }
};

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int case,M,lm[5];
    scanf("%d",&case);
    for(int i=0;i<case;i++){//处理各组数据
        scanf("%d",&M);
        for(int j=0;i<5;j++)//读入数据
            scanf("%d",&lm[j]);
        Headquarter RED(M,RedSq,lm,0);
        Headquarter BLUE(M,BlueSq,lm,1);
        int BlueEnableMake=1;
        int RedEnableMake=1;
        while( RedEnableMake || BlueEnableMake ){
            if(RedEnableMake){
                RedEnableMake=RED.MakeWarrior();
            }
            if(BlueEnableMake){
                BlueEnableMake=BLUE.MakeWarrior();
            }
        }

    }
}

