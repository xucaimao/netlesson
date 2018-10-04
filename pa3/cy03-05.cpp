/*
 程序设计实习MOOC /程序设计与算法（三）第三周测验(2018秋季)
 5:魔兽世界之一：备战
 write by xucaimao,2018-09-23,AC at 2018-09-23
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int Red=0;
const int  Blue=1;
char colorName[2][5]={"red","blue"};
char inputOrd[5][7]={"dragon","ninja","iceman","lion","wolf"};//生命力初始值的输入顺序
int makeOrd[2][5]={ {2,3,4,1,0},{3,0,1,2,4} };//红军、蓝军士兵制造顺序,就是在inputOrd中的序号
int currentTime;

class Headquarter{
private:
    int color;
    int totalNum;//制造的士兵总数,也就是士兵编号
    int lifeMatter;//当前剩余的生命元
    int warrior[5];//分别保存五种武士的数量,按inputOrd的顺序存放
    int valueOfMake[5];//每种武士所需要的生命力值,按制造的顺序存放
    int cur;//当前制造的士兵在makeOrder[][]中的第二维下标
    bool stopped;//是否已经停止制造
public:
    //构造函数，初始生命元为m，每种士兵所需要的生命力l[]，红蓝军:0-红 1-蓝
    Headquarter(int m,const int l[],int color_){
        stopped=false;
        color=color_;
        totalNum=0;
        lifeMatter=m;
        cur=0;      //当前制造武士的序号,即makeOrd[color][cur]
        for(int i=0;i<5;i++){
            valueOfMake[i]=l[ makeOrd[color_][i] ];//输入顺序与实际顺序转换
            warrior[i]=0;
        }
//        cout<<colorName[color]<<" : ";
//        for(int i=0;i<5;i++)
//            cout<<valueOfMake[i]<<" ";
//        cout<<endl;
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


    void makeWarrior(){
        if( !stopped ){
            if( enableMake() ){
                //找到第一个可以制造的武士
                while(valueOfMake[ cur ] > lifeMatter){
                    cur=(cur+1)%5;  //循环
                }
                lifeMatter-=valueOfMake[ cur ];  //生命值减少
                //下面，把制造的士兵种类，转换到在inputOrd[]中的位置
                int ordInInput=makeOrd[color][cur];
                warrior[ ordInInput ]++;     //相应的士兵增加
                totalNum++;         //总数增加
                cout.fill('0');
                cout.width(3);
                cout<<currentTime<<" "<<colorName[color]<<" "<<inputOrd[ordInInput]<<" "<<totalNum<<" born with strength ";
                cout<<valueOfMake[ cur ]<<","<<warrior[ordInInput]<<" "<<inputOrd[ordInInput];
                cout<<" in "<<colorName[color]<<" headquarter"<<endl;
                //开始直接加1,导致数组越界，调试了很久
                cur=(cur+1)%5;              //指向下一个等待制造的兵种
            }
            else{
                //生命元的值不能制造任何一种战士
                stopped=true;
                cout.fill('0');
                cout.width(3);
                cout<<currentTime<<" "<<colorName[color]<<" headquarter stops making warriors"<<endl;
            }

        }
    }

    bool isStopped(){
        return stopped;
    }

};

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int caseNum;
    int M,valueOfMake[5];
    cin>>caseNum;
    for(int i=1;i<=caseNum;i++){//处理各组数据
        currentTime=0;
        cin>>M;
        for(int j=0;j<5;j++)//读入数据
            cin>>valueOfMake[j];
        Headquarter RED(M,valueOfMake,Red);
        Headquarter BLUE(M,valueOfMake,Blue);
        cout<<"Case:"<<i<<endl;
        while( !RED.isStopped() || !BLUE.isStopped() ){
            RED.makeWarrior();
            BLUE.makeWarrior();
            currentTime++;
        }

    }
    return 0;
}
