/*
 程序设计实习MOOC /程序设计与算法（三）第三周测验(2018秋季)
 5:魔兽世界之一：备战
 write by xucaimao,2018-09-23,AC at 2018-09-23
 2018-01-02根据郭伟老师的程序，整体架构做了调整
 不采用全局数据，采用静态变量
 编译会出错，只有把类的成员函数移到外面，才能消除错误
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int Red=0;
const int  Blue=1;

class Headquarter;

class Warrior{
private:
    Headquarter * pHead;  //所属的司令部
    int color;
    int life;   //士兵的生命值
    int kindNo; //士兵的种类0-dragon,1-ninja,2-iceman,3-lion,4-wolf
    int No;     //士兵的编号，也就是制造序号
public:
    Warrior(Headquarter* p,int life_,int kindNo_,int No_,int color_):pHead{p}{
        life=life_;
        kindNo=kindNo_;
        No=No_;
        color=color_;
    }
    void print(int currentTime,int kindNum){
        cout.fill('0');
        cout.width(3);
        cout<<currentTime<<" "<<colorName[color]<<" "<<warriorName[kindNo]<<" "<<No<<" born with strength ";
        cout<<life<<","<<kindNum<<" "<<warriorName[kindNo];
        cout<<" in "<<colorName[color]<<" headquarter"<<endl;
    }
    static char warriorName[5][7];//士兵的名称，也就是士兵生命值的输入顺序
    static char colorName[2][5];
};


class Headquarter{
private:
    int color;
    int totalNum;//制造的士兵总数,也就是士兵编号
    int lifeMatter;//当前剩余的生命元
    int warrior[5];//分别保存五种武士的数量,按worriorName的顺序存放
    int curMakeIdx;//当前制造的士兵在makeOrder[color][]中的第二维下标
    bool stopped;//是否已经停止制造
    Warrior* pWarriors[1000];   //存放制造出的各个士兵(每个士兵即使种类相同，其他属性也有可能不同)
public:
//    friend class Warrior;
    //构造函数，初始生命元为m，红蓝军:0-红 1-蓝
    Headquarter(int m,int color_){
        stopped=false;
        color=color_;
        totalNum=0;
        lifeMatter=m;
        curMakeIdx=0;      //当前制造武士的序号,即makeOrd[color][curMakeIdx]
        for(int i=0;i<5;i++)
            warrior[i]=0;
    }
    ~Headquarter(){
        for(int i=0;i<totalNum;i++)
            delete pWarriors[i];
    }

    //生命元数量只要能满足制造某一个武士就返回true
    bool enableMake(){
        bool ans= false;
        for(int i=0;i<5;i++){
            if(valueOfMake[i]<=lifeMatter){
                ans=true;
                break;
            }
        }
        return ans;
    }

    void makeWarrior(int currentTime){
        if( !stopped ){
            if( enableMake() ){
                //找到第一个可以制造的武士
                //注意这里的序号转换 makeOrd[color][curMakeIdx]
                while(valueOfMake[ makeOrd[color][curMakeIdx] ] > lifeMatter){
                    curMakeIdx=(curMakeIdx+1)%5;  //循环
                }
                lifeMatter-=valueOfMake[ makeOrd[color][curMakeIdx] ];  //生命值减少
                //下面，把制造的士兵序号，转换到在worriorName[]中的位置，也就是士兵的种类
                int warriorKind=makeOrd[color][curMakeIdx];
                warrior[ warriorKind ]++;     //相应的士兵增加
                //分配士兵对象的空间，并与数组建立联系
                //注意数组下标从0开始，士兵编号从1开始
                pWarriors[totalNum]=new Warrior(this,valueOfMake[ warriorKind ],warriorKind,totalNum+1,color);
                //打印信息
                pWarriors[totalNum]->print(currentTime, warrior[ warriorKind ]);

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

    bool isStopped(){
        return stopped;
    }
    string getcolor(){
        if(color==0)return "red";
        else return "blue";
    }
    static int valueOfMake[5];//每种武士所需要的生命力值,按输入的顺序存放
    static int makeOrd[2][5];
};
//静态成员初始化
int Headquarter::valueOfMake[5];
int Headquarter::makeOrd[2][5]={ {2,3,4,1,0},{3,0,1,2,4} };//红军、蓝军士兵制造顺序,就是在worriorName中的序号
char Warrior::warriorName[5][7]={"dragon","ninja","iceman","lion","wolf"};//士兵名称，也是生命值的输入顺序
char Warrior::colorName[2][5]={"red","blue"};

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
            RED.makeWarrior(curTime);
            BLUE.makeWarrior(curTime);
            curTime++;
        }

    }
    return 0;
}
