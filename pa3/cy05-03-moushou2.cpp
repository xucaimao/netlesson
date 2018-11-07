/*
 程序设计实习MOOC /程序设计与算法（三）第三周测验(2018秋季)
 3:魔兽世界之二：装备
 write by xucaimao,2018-10-01,AC at 2018-10-02
*/
//每此制造出来的士兵，即使类型一样，它的其他属性也可能不一样因此需要维护一个士兵的集合
//类的相互调用，只能采用先把类定义完整（包含成员变量与成员函数），再把类的函数放在类定义后面的方式，否则会编译不通过

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int Red=0;
const int  Blue=1;

class Headquarter;

class Warrior{
private:
    Headquarter * pHead;  //所属的司令部
    int color;
    int life;       //士兵的生命值
    int kindNo;     //士兵的种类0-dragon,1-ninja,2-iceman,3-lion,4-wolf
    int No;         //士兵的编号，也就是制造序号

    int weaponNum;  //拥有的武器数量
    int weapon[2];  //用于存放武器的型号
    double morale;  //士气值
    int loyal;      //忠诚度

public:
    Warrior(Headquarter * p,int life_,int kindNo_,int No_,int color_);
    void print(int currentTime);
    static char warriorName[5][7];//士兵的名称，也就是士兵生命值的输入顺序
    static char colorName[2][5];
    static char weaponName[3][6];
};


class Headquarter{
private:
    int color;
    int totalNum;//制造的士兵总数,也就是士兵编号
    int lifeMatter;//当前剩余的生命元
    int warrior[5];//分别保存五种武士的数量,按worriorName的顺序存放
    int curMakeIdx;//当前制造的士兵在makeOrder[color][]中的第二维下标
    bool stopped;//是否已经停止制造
    Warrior* pWorriors[1000];   //存放制造出的各个士兵(每个士兵即使种类相同，其他属性也有可能不同)
public:
    friend class Warrior;
    //构造函数，初始生命元为m，红蓝军:0-红 1-蓝
    Headquarter(int m,int color_);
    ~Headquarter();

    //生命元数量只要能满足制造某一个武士就返回true
    bool enableMake();

    void makewarrior(int currentTime);

    bool isStopped();
    string getcolor();
    static int valueOfMake[5];//每种武士所需要的生命力值,按输入的顺序存放
    static int makeOrd[2][5];
};

Warrior::Warrior(Headquarter * p,int life_,int kindNo_,int No_,int color_):pHead{p}{
    life=life_;
    kindNo=kindNo_;
    No=No_;
    color=color_;
    //增加的程序
    weaponNum=0;
    loyal=0;
    morale=0;
    switch(kindNo){
        case 0: //dragon
            weaponNum=1;
            weapon[0]=No%3;
            morale=pHead->lifeMatter/(double)life;
            break;
        case 1: //ninja
            weaponNum=2;
            weapon[0]=No%3;
            weapon[1]=(No+1)%3;
            break;
        case 2: //iceman
            weaponNum=1;
            weapon[0]=No%3;
            break;
        case 3: //lion
            loyal=pHead->lifeMatter;
            break;
        case 4: //wolf
            break;
    }
}

void Warrior::print(int currentTime){
    cout.fill('0');
    cout.width(3);
    cout<<currentTime<<" "<<pHead->getcolor()<<" "<<warriorName[kindNo]<<" "<<No<<" born with strength ";
    cout<<life<<","<<pHead->warrior[kindNo]<<" "<<warriorName[kindNo];
    cout<<" in "<<pHead->getcolor()<<" headquarter"<<endl;

    switch(kindNo){
        case 0: //dragon
            cout<<"It has a "<<weaponName[weapon[0]]<<",and it's morale is "<<fixed<<setprecision(2)<<morale<<endl;
            break;
        case 1: //ninja
            cout<<"It has a "<<weaponName[weapon[0]]<<" and a "<<weaponName[weapon[1]]<<endl;
            break;
        case 2: //iceman
            cout<<"It has a "<<weaponName[weapon[0]]<<endl;
            break;
        case 3: //lion
            cout<<"It's loyalty is "<<loyal<<endl;
            break;
        case 4: //wolf
            break;

    }
}

Headquarter::Headquarter(int m,int color_){
    stopped=false;
    color=color_;
    totalNum=0;
    lifeMatter=m;
    curMakeIdx=0;      //当前制造武士的序号,即makeOrd[color][curMakeIdx]
    for(int i=0;i<5;i++)
        warrior[i]=0;
}

Headquarter:: ~Headquarter(){
    for(int i=0;i<totalNum;i++)
        delete pWorriors[i];
}

bool Headquarter::enableMake(){
    bool ans= false;
    for(int i=0;i<5;i++){
        if(valueOfMake[i]<=lifeMatter){
            ans=true;
            break;
        }
    }
    return ans;
}

void Headquarter::makewarrior(int currentTime){
    if( !stopped ){
        if( enableMake() ){
            //根据剩余生命值，找到第一个可以制造的武士
            //注意这里的序号转换 makeOrd[color][curMakeIdx]
            while(valueOfMake[ makeOrd[color][curMakeIdx] ] > lifeMatter){
                curMakeIdx=(curMakeIdx+1)%5;  //当前制造的士兵种类循环
            }
            //下面，把制造的士兵序号，转换到在worriorName[]中的位置，也就是士兵的种类
            int warriorKind=makeOrd[color][curMakeIdx];
            lifeMatter-=valueOfMake[ warriorKind ];  //生命值减少

            warrior[ warriorKind ]++;     //相应的士兵增加
            //分配士兵对象的空间，并与数组建立联系
            //注意数组下标从0开始，士兵编号从1开始
            pWorriors[totalNum]=new Warrior(this,valueOfMake[ warriorKind ],warriorKind,totalNum+1,color);
            //打印信息
            pWorriors[totalNum]->print(currentTime);

            totalNum++;         //总数增加

            //开始直接加1,导致数组越界，调试了很久
            curMakeIdx=(curMakeIdx+1)%5;              //指向下一个等待制造的兵种
        }
        else{
            //生命元的值不能制造任何一种战士
            stopped=true;
            cout.fill('0');
            cout.width(3);
            cout<<currentTime<<" "<<getcolor()<<" headquarter stops making warriors"<<endl;
        }

    }
}

bool Headquarter::isStopped(){
    return stopped;
}

string Headquarter::getcolor(){
    if(color==0)return "red";
    else return "blue";
}

//静态成员初始化
int Headquarter::valueOfMake[5];
int Headquarter::makeOrd[2][5]={ {2,3,4,1,0},{3,0,1,2,4} };//红军、蓝军士兵制造顺序,就是在worriorName中的序号
char Warrior::warriorName[5][7]={"dragon","ninja","iceman","lion","wolf"};//士兵名称，也是生命值的输入顺序
char Warrior::colorName[2][5]={"red","blue"};

char Warrior::weaponName[3][6]={"sword","bomb","arrow"};

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int caseNum;
    int M;
    cin>>caseNum;
    for(int i=1;i<=caseNum;i++){//处理各组数据
        int curTime=0;
        cin>>M;
        for(int j=0;j<5;j++)//读入数据
            cin>>Headquarter::valueOfMake[j];
        Headquarter RED(M,Red);
        Headquarter BLUE(M,Blue);
        cout<<"Case:"<<i<<endl;
        while( !RED.isStopped() || !BLUE.isStopped() ){
            RED.makewarrior(curTime);
            BLUE.makewarrior(curTime);
            curTime++;
        }

    }
    return 0;
}
