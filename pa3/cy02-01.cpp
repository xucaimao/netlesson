/*
 程序设计实习MOOC /程序设计与算法（三）第二周测验(2018秋季)
 001:编程填空：学生信息处理程序
 填空，使得程序输出结果是：123,456
 write by xucaimao,2018-09-03,AC
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
// 在此处补充你的代码
private:
    char name[25];
    int age,number;
    int s1,s2,s3,s4;
    float averScore;

public:
    void input(){
        char c;
        // 考察函数cin.getline()的用法
        // cin.getline(arrayname,size,s)当遇到s时会结束输入，并把s从缓冲区中删除
        // cin.get（arrayname,size,s）当遇到s时会结束输入，但不会删除缓冲区中的s
        // cin遇到缓冲区中的[enter],[space],[tab]会结束当前输入，并舍弃[enter],[space],[tab]，继续下一项输入，
        // 当有连续[space],[enter,[tab]会全部舍弃。
        cin.getline(name,20,',');
        cin>>age>>c>>number>>c>>s1>>c>>s2>>c>>s3>>c>>s4;
//        cout<<"Input is:"<<endl;
//        cout<<name<<","<<age<<","<<number<<","<<s1<<","<<s2<<","<<s3<<","<<s4<<endl;
    }

    void calculate(){
        int totalScore=(s1+s2+s3+s4);
        averScore=totalScore/4.0;
    }
    void output(){
        cout<<name<<","<<age<<","<<number<<","<<averScore<<endl;
    }

};

int main() {
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    Student student;        // 定义类的对象
    student.input();        // 输入数据
    student.calculate();    // 计算平均成绩
    student.output();       // 输出数据
}