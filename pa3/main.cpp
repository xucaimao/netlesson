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
char colorName[2][5]={"red","blue"};
char weaponName[3][6]={"sword","bomb","arrow"};
int valueOfMake[5];                  //每种武士所需要的生命力值,按输入的顺序存放
int attackOfWorrior[5];              //每种武士初始的攻击力
int NumOfCity;                       //程序输入的城市的总数量


void time2Str(char * s,int t){
    //hhh:mm格式
    int h=t/60,m=t%60;
    s[6]='\0';
    s[5]=m%10+'0';
    s[4]=m/10+'0';
    s[3]=':';
    s[2]=h%10+'0';
    h/=10;
    s[1]=h%10+'0';
    h/=10;
    s[0]=h%10+'0';
}
class Headquarter;
class Warrior;
class Dragon;
class Ninjia;
class Iceman;
class Wolf;
class Lion;

class Weapon{
protected:
    Warrior * pWarriror;    //所属的士兵
    int id;                 //武器编号0-sword,1-bomb,2-arrow
    int numOfUse;           //可以使用的次数
    bool canUse;            //通过此变量控制weapon对象的删除
public:
    Weapon(Warrior* p,int id_);
    void attack(Warrior* enemy);
    friend bool operator<(const Weapon & a,const Weapon & b);
    void printWeapon();
    int getId();
};


class Warrior{
    //基类
protected:
    Headquarter * pHead;    //所属的司令部
    int elements;           //士兵的生命值
    int Number;             //士兵的编号，也就是制造序号
    int force;              //攻击力
    int position;           //士兵所处城市的编号，用于士兵的行走，判断是否战斗
    int weaponNum;          //拥有的武器数量
    int weaponTypeNum[3];   //用于统计每种武器的数量
    Weapon* pWeapon[10];    //用于存放武器,最多10件

public:
    friend class Weapon;
    Warrior(Headquarter * p,int elem_,int Num_,int pos_,int wn_);
    void hurted(int numOfHurt);
    virtual void printBornMsg(char* curTimeStr)=0;
    virtual void printWorriorMsg(char* curTimeStr)=0;
    void sortWeapon();
    virtual void move(char* curTimeStr)=0;
    static int KOfLoyal;   //Lion忠诚度降低的值
    static char warriorName[5][7];//士兵的名称，也就是士兵生命值的输入顺序
};

class Headquarter{
protected:
    int color;
    int targetCity;             //本方要攻占的对方司令部的城市编号
    int totalNum;               //制造的士兵总数,也就是士兵编号
    int livingWorrierNum;       //活着的士兵数量
    int lifeMatter;             //当前剩余的生命元
    int warrior[5];             //分别保存五种武士的数量,按worriorName的顺序存放
    int curMakeIdx;             //当前制造的士兵在makeOrder[color][]中的第二维下标
    bool stopped;               //是否已经停止制造
    bool winBattle;             //赢得战争胜利(本方士兵占领对方)
    Warrior* pWorriors[1000];   //存放制造出的各个士兵(每个士兵即使种类相同，其他属性也有可能不同)
public:
    friend class Warrior;
    friend class Lion;
    friend class Ninjia;
    friend class Dragon;
    friend class Iceman;
    friend class Wolf;
    //构造函数，初始生命元为m，红蓝军:0-红 1-蓝
    Headquarter(int m,int color_);
    //~Headquarter();

    //生命元数量只要能满足制造某一个武士就返回true
    bool enableMake();
    bool win();
    void setWin();
    void lionEscape();                          //狮子逃走
    void makewarrior(char* curTimeStr);
    void printLifeMatter(char* curTimeStr);
    void printWorrior(char* curTimeStr);
    void allMove(char* curTimeStr);             //所有士兵移动一步
    bool isStopped();
    string getColorStr();
    static int makeOrd[2][5];
};

class Dragon:public Warrior{
private:
public:
    Dragon(Headquarter * p,int wKind,int Num_,int pos_):Warrior(p,wKind,Num_,pos_,1){
        pWeapon[0]=new Weapon(this,Number%3);
    }
    void printBornMsg(char* curTimeStr){
        cout<<curTimeStr<<" "<<pHead->getColorStr()<<" dragon "<<Number<<" born"<<endl;
    }
    void printWorriorMsg(char* curTimeStr){
        sortWeapon();
        cout<<curTimeStr<<" "<<pHead->getColorStr()<<" dragon "<<Number<<" has";
        for(int i=0;i<3;i++){
            cout<<" "<<weaponTypeNum[i]<<" "<<weaponName[i];
        }
        cout<<" and "<<elements<<" elements"<<endl;
    }
    void move(char* curTimeStr) {
        //对于红色
        int direction=1;
        if(pHead->color==1)direction=-1;    //蓝色，往城市编号小的方向走
        position+=direction;                //往下一个城市走
        cout<<curTimeStr<<" "<<pHead->getColorStr()<<" dragon "<<Number<<" marched to city ";
        cout<<position<<" with "<<elements<<" elements and force "<<force<<endl;
        if(position == pHead->targetCity){   //到达对方司令部
            cout<<curTimeStr<<" "<<pHead->getColorStr()<<" dragon "<<Number<<" reached ";
            int c=pHead->color;
            if(c==0)c=1;
            if(c==1)c=0;
            cout<<colorName[c]<<" headquarter with "<<elements<<" elements and force "<<force<<endl;
            cout<<curTimeStr<<" "<<colorName[c]<<" headquarter was taken"<<endl;
            pHead->setWin();
        }
    }
};

class Ninjia:public Warrior{
private:
public:
    Ninjia(Headquarter * p,int wKind,int Num_,int pos_):Warrior(p,wKind,Num_,pos_,2){
        pWeapon[0]=new Weapon(this,Number%3);
        pWeapon[1]=new Weapon(this,(Number+1)%3 );
    }
    void printBornMsg(char* curTimeStr){
        cout<<curTimeStr<<" ";
        cout<<pHead->getColorStr()<<" Ninjia "<<Number<<" born"<<endl;
    }
    void printWorriorMsg(char* curTimeStr){
        sortWeapon();
        cout<<curTimeStr<<" "<<pHead->getColorStr()<<" ninjia "<<Number<<" has";
        for(int i=0;i<3;i++){
            cout<<" "<<weaponTypeNum[i]<<" "<<weaponName[i];
        }
        cout<<" and "<<elements<<" elements"<<endl;
    }
    void move(char* curTimeStr) {
        //对于红色
        int direction=1;
        if(pHead->color==1)direction=-1;    //蓝色，往城市编号小的方向走
        position+=direction;                //往下一个城市走
        cout<<curTimeStr<<" "<<pHead->getColorStr()<<" ninjia "<<Number<<" marched to city ";
        cout<<position<<" with "<<elements<<" elements and force "<<force<<endl;
        if(position == pHead->targetCity){   //到达对方司令部
            cout<<curTimeStr<<" "<<pHead->getColorStr()<<" dragon "<<Number<<" reached ";
            int c=pHead->color;
            if(c==0)c=1;
            if(c==1)c=0;
            cout<<colorName[c]<<" headquarter with "<<elements<<" elements and force "<<force<<endl;
            cout<<curTimeStr<<" "<<colorName[c]<<" headquarter was taken"<<endl;
            pHead->setWin();
        }
    }
};

class Iceman:public Warrior{
private:
public:
    Iceman(Headquarter * p,int wKind,int Num_,int pos_):Warrior(p,wKind,Num_,pos_,1){
        pWeapon[0]=new Weapon(this,Number%3);;
    }
    void printBornMsg(char* curTimeStr){
        cout<<curTimeStr<<" ";
        cout<<pHead->getColorStr()<<" Iceman "<<Number<<" born"<<endl;
    }
    void printWorriorMsg(char* curTimeStr){
        sortWeapon();
        cout<<curTimeStr<<" "<<pHead->getColorStr()<<" iceman "<<Number<<" has";
        for(int i=0;i<3;i++){
            cout<<" "<<weaponTypeNum[i]<<" "<<weaponName[i];
        }
        cout<<" and "<<elements<<" elements"<<endl;
    }
    void move(char* curTimeStr) {
        //对于红色
        int direction=1;
        if(pHead->color==1)direction=-1;    //蓝色，往城市编号小的方向走
        position+=direction;                //往下一个城市走
        int ele;
        ele=elements/10;
        elements=elements-ele;  //生命力降低
        cout<<curTimeStr<<" "<<pHead->getColorStr()<<" iceman "<<Number<<" marched to city ";
        cout<<position<<" with "<<elements<<" elements and force "<<force<<endl;
        if(position == pHead->targetCity){   //到达对方司令部
            cout<<curTimeStr<<" "<<pHead->getColorStr()<<" dragon "<<Number<<" reached ";
            int c=pHead->color;
            if(c==0)c=1;
            if(c==1)c=0;
            cout<<colorName[c]<<" headquarter with "<<elements<<" elements and force "<<force<<endl;
            cout<<curTimeStr<<" "<<colorName[c]<<" headquarter was taken"<<endl;
            pHead->setWin();
        }
    }
};

class Lion:public Warrior{
private:
    int loyal;              //忠诚度
public:
    Lion(Headquarter * p,int wKind,int Num_,int pos_):Warrior(p,wKind,Num_,pos_,1){
        pWeapon[0]=new Weapon(this,Number%3);
        loyal=pHead->lifeMatter;//todo
    }
    void printBornMsg(char* curTimeStr){
        cout<<curTimeStr<<" ";
        cout<<pHead->getColorStr()<<" lion "<<Number<<" born"<<endl;
        cout<<"Its loyalty is "<<loyal<<endl;
    }
    void printWorriorMsg(char* curTimeStr){
        sortWeapon();
        cout<<curTimeStr<<" "<<pHead->getColorStr()<<" lion "<<Number<<" has";
        for(int i=0;i<3;i++){
            cout<<" "<<weaponTypeNum[i]<<" "<<weaponName[i];
        }
        cout<<" and "<<elements<<" elements"<<endl;
    }
    void move(char* curTimeStr) {
        //对于红色
        int direction=1;
        if(pHead->color==1)direction=-1;    //蓝色，往城市编号小的方向走
        position+=direction;                //往下一个城市走
        cout<<curTimeStr<<" "<<pHead->getColorStr()<<" lion "<<Number<<" marched to city ";
        cout<<position<<" with "<<elements<<" elements and force "<<force<<endl;
        if(position == pHead->targetCity){   //到达对方司令部
            cout<<curTimeStr<<" "<<pHead->getColorStr()<<" dragon "<<Number<<" reached ";
            int c=pHead->color;
            if(c==0)c=1;
            if(c==1)c=0;
            cout<<colorName[c]<<" headquarter with "<<elements<<" elements and force "<<force<<endl;
            cout<<curTimeStr<<" "<<colorName[c]<<" headquarter was taken"<<endl;
            pHead->setWin();
        }
        loyal-=KOfLoyal;    //忠诚度降低
    }
};

class Wolf:public Warrior{
private:
    int weaponNum;          //拥有的武器数量
    Weapon* pWeapon[10];    //用于存放武器,最多10件
public:
    Wolf(Headquarter * p,int wKind,int Num_,int pos_):Warrior(p,wKind,Num_,pos_,0){}
    void printBornMsg(char* curTimeStr){
        cout<<curTimeStr<<" ";
        cout<<pHead->getColorStr()<<" wolf "<<Number<<" born"<<endl;
    }
    void printWorriorMsg(char* curTimeStr){
        sortWeapon();
        cout<<curTimeStr<<" "<<pHead->getColorStr()<<" wolf "<<Number<<" has";
        for(int i=0;i<3;i++){
            cout<<" "<<weaponTypeNum[i]<<" "<<weaponName[i];
        }
        cout<<" and "<<elements<<" elements"<<endl;
    }
    void move(char* curTimeStr) {
        //对于红色
        int direction=1;
        if(pHead->color==1)direction=-1;    //蓝色，往城市编号小的方向走
        position+=direction;                //往下一个城市走
        cout<<curTimeStr<<" "<<pHead->getColorStr()<<" wolf "<<Number<<" marched to city ";
        cout<<position<<" with "<<elements<<" elements and force "<<force<<endl;
        if(position == pHead->targetCity){   //到达对方司令部
            cout<<curTimeStr<<" "<<pHead->getColorStr()<<" dragon "<<Number<<" reached ";
            int c=pHead->color;
            if(c==0)c=1;
            if(c==1)c=0;
            cout<<colorName[c]<<" headquarter with "<<elements<<" elements and force "<<force<<endl;
            cout<<curTimeStr<<" "<<colorName[c]<<" headquarter was taken"<<endl;
            pHead->setWin();
        }
    }
};


Warrior::Warrior(Headquarter * p,int wKind,int Num_,int pos_,int wn_){
    pHead=p;
    elements=valueOfMake[wKind];
    force=attackOfWorrior[wKind];
    Number=Num_;
    position=pos_;
    weaponNum=wn_;
}

void Warrior::sortWeapon() {
    std::sort(pWeapon,pWeapon+weaponNum);
    for(int i=0;i<3;i++)
        weaponTypeNum[i]=0;
    for(int i=0;i<weaponNum;i++)
        weaponTypeNum[pWeapon[i]->getId()]++;
}

void Warrior::hurted(int numOfHurt) {
    elements-=numOfHurt;
    if(elements<=0){
        //todo
    }
}


Headquarter::Headquarter(int m,int color_){
    stopped=false;
    winBattle=false;
    color=color_;
    totalNum=0;
    lifeMatter=m;
    curMakeIdx=0;      //当前制造武士的序号,即makeOrd[color][curMakeIdx]
    for(int i=0;i<5;i++)
        warrior[i]=0;
    if(color==0)targetCity=NumOfCity+1;
    else targetCity=0;
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

bool Headquarter::win() {
    return winBattle;
}
void Headquarter::setWin(){
    winBattle= true;
}

void Headquarter::lionEscape() {
    //todo
    //loyal低于0，且不在对方基地

}

void Headquarter::makewarrior(char* curTimeStr){
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
            int posOfCity;
            if(color==Red)
                posOfCity=0;
            else if(color==Blue)
                posOfCity=NumOfCity+1;
            //分配士兵对象的空间，并与数组建立联系
            //注意数组下标从0开始，士兵编号从1开始
            //todo
            //开始按类型分别制造
            switch (warriorKind){
                case 0:
                    pWorriors[totalNum]=new Dragon(this,warriorKind,totalNum+1,posOfCity);
                    break;
                case 1:
                    pWorriors[totalNum]=new Ninjia(this,warriorKind,totalNum+1,posOfCity);
                    break;
                case 2:
                    pWorriors[totalNum]=new Iceman(this,warriorKind,totalNum+1,posOfCity);
                    break;
                case 3:
                    pWorriors[totalNum]=new Lion(this,warriorKind,totalNum+1,posOfCity);
                    break;
                case 4:
                    pWorriors[totalNum]=new Wolf(this,warriorKind,totalNum+1,posOfCity);
                    break;
            }

            //打印信息
            pWorriors[totalNum]->printBornMsg(curTimeStr);

            totalNum++;             //总数增加
            livingWorrierNum++;     //活着的士兵数量增加

            //开始直接加1,导致数组越界，调试了很久
            curMakeIdx=(curMakeIdx+1)%5;              //指向下一个等待制造的兵种
        }
        else{
            //生命元的值不能制造任何一种战士
//            stopped=true;
//            cout<<curTimeStr<<" "<<getColorStr()<<" headquarter stops making warriors"<<endl;
        }

    }
}

bool Headquarter::isStopped(){
    return stopped;
}

void Headquarter::printLifeMatter(char* curTimeStr){
    cout<<curTimeStr<<" "<<lifeMatter<<" elements in "<<colorName[color]<<" headquarter"<<endl;
}

void Headquarter::printWorrior(char* curTimeStr) {
    for(int i=0;i<totalNum;i++){
        pWorriors[i]->printWorriorMsg(curTimeStr);
    }
}
void Headquarter::allMove(char* curTimeStr) {
    for(int i=0;i<totalNum;i++){
        pWorriors[i]->move(curTimeStr);
    }
}

string Headquarter::getColorStr(){
    if(color==0)return "red";
    else return "blue";
}

Weapon::Weapon(Warrior* p,int id_){
    pWarriror=p;
    id=id_;
    numOfUse=2;
    canUse=true;
}
void Weapon::printWeapon() {
    cout<<weaponName[id];
}
int Weapon::getId() {
    return id;
}
bool operator<(const Weapon & a,const Weapon & b){
    if(a.canUse && b.canUse){
        if(a.id<b.id)return true;
        else if(a.id==b.id)return a.numOfUse<b.numOfUse;
        else return false;
    }
    else if(a.canUse)return true;
    else return false;
}
void Weapon::attack(Warrior* enemy){
    //发动对enemy的攻击
    if(id==0 && canUse){    //sword
        int attForce=pWarriror->force * 2 / 10;
        enemy->hurted(attForce);
    }
    else if(id==1 && canUse){    //bomb
        int attForce=pWarriror->force * 4 / 10;
        enemy->hurted(attForce);
        canUse=false;       //bomb只能使用一次
        if(typeid(*pWarriror) != typeid(Ninjia))  //Ninjia对bomb免疫
            pWarriror->hurted(attForce/2);  //对自己的伤害减半+
    }
    else if(id==2 && canUse){    //arrow
        int attForce=pWarriror->force * 3 / 10;
        enemy->hurted(attForce);
        numOfUse--;
        if(numOfUse==0)canUse=false;
    }
}




//静态成员初始化
int Headquarter::makeOrd[2][5]={ {2,3,4,1,0},{3,0,1,2,4} };//红军、蓝军士兵制造顺序,就是在worriorName中的序号
char Warrior::warriorName[5][7]={"dragon","ninja","iceman","lion","wolf"};//士兵名称，也是生命值的输入顺序
int Warrior::KOfLoyal;   //Lion忠诚度降低的值

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    char curTimeStr[10];
    int caseNum;
    int M,T;
    cin>>caseNum;
    for(int i=1;i<=caseNum;i++){//处理各组数据
        int curTime=0;
        cin>>M>>NumOfCity>>Warrior::KOfLoyal>>T;    //读入生命元、城市数、Lion忠诚度降低值、时间
        for(int j=0;j<5;j++)//读入生命元数据
            cin>>valueOfMake[j];
        for(int j=0;j<5;j++)//读入攻击力数据
            cin>>attackOfWorrior[j];

        Headquarter RED(M,Red);
        Headquarter BLUE(M,Blue);
        cout<<"Case "<<i<<":"<<endl;
        while(curTime<T){
            time2Str(curTimeStr,curTime);
            if(curTime%60 == 0 && ( !RED.isStopped() || !BLUE.isStopped() ) ){
                RED.makewarrior(curTimeStr);
                BLUE.makewarrior(curTimeStr);
            }
            if(curTime%60 ==5){     //Lion逃走

            }
            if(curTime%60 ==10){    //士兵向下一个城市行走
                RED.allMove(curTimeStr);
                BLUE.allMove(curTimeStr);
                if(RED.win() || BLUE.win())break;
            }
            if(curTime%60 ==35){    //wolf抢夺对方武器

            }
            if(curTime%60 ==40){    //有两个士兵的城市，开战

                if(RED.win() || BLUE.win())break;
            }
            if(curTime%60 ==50){    //司令部包括它拥有的生命元
                RED.printLifeMatter(curTimeStr);
                BLUE.printLifeMatter(curTimeStr);
            }
            if(curTime%60 ==55){    //每个士兵报告它拥有的武器情况
                RED.printWorrior(curTimeStr);
                BLUE.printWorrior(curTimeStr);
            }
            curTime++;
        }

    }
    return 0;
}
