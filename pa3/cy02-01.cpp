/*
 程序设计实习MOOC /程序设计与算法（三）第二周测验(2018春季)
 001:编程填空：学生信息处理程序
 write by xucaimao,20180326,AC
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
    int score[4];
    double average;
public:
    void input(){
        char s[25];
        //从标准输入设备键盘读取一串字符串，长度不超过指定长度，并以指定的结束符结束
        cin.getline(name,20,',');
        cin.getline(s,20,',');
        age=atoi(s);
        cin.getline(s,20,',');
        number=atoi(s);
        for(int i=0;i<3;i++){
            cin.getline(s,20,',');
            score[i]=atoi(s);
        }
        cin>>score[3];
    }

    void calculate(){
        int sum=0;
        for(int i=0;i<4;i++)
            sum+=score[i];
        average=sum/4.0;
    }

    void output(){
        cout<<name<<","<<age<<","<<number<<","<<average<<endl;
    }
};

int main() {
    Student student;        // 定义类的对象
    student.input();        // 输入数据
    student.calculate();    // 计算平均成绩
    student.output();       // 输出数据
}