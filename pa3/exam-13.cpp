// 程序设计与算法（三）期末考试(2018秋季)
// 013:编程填空：三生三世
// Created by Administrator on 2018-11-10.
// 考察：sort自定义排序，函数调用与函数对象调用的区别
// 前者不需要加括号，直接用函数名；后者需要加括号，重载()运算符
//
/*
输入
首先输入整数n，代表电视剧的个数。接下来，对于每个电视剧有两行输入：第一行一个字符串（可能含有空格，逗号，冒号等标点符号）作为电视剧的名字；
 第二行包括三个整数，分别为演员阵容、剧情和演技的评分。
输出
输出包括三行，分别为电视剧按演员阵容、剧情和演技的排行榜（评分由高到低），电视剧名字之间以分号隔开
 * */

#include<iostream>
#include<cstring>
#include<list>
#include<algorithm>
using namespace std;

class TV_Drama {
public:
    char name[100];
    int actor;
    int story;
    int acting_skill;
// 在此处补充你的代码
    TV_Drama(char _name[], int _actor, int _story, int _acting_skill){
        int i=0;
        //此处的深拷贝是重点
        while(_name[i]!='\0'){
            name[i]=_name[i];
            i++;
        }
        name[i]='\0';
        actor=_actor;
        story=_story;
        acting_skill=_acting_skill;
    }
    friend bool operator<(const TV_Drama & a,const TV_Drama & b){
        if(a.actor>b.actor)return true;
        else return false;
    }
};

//函数，直接通过函数名调用
bool comparator_1(const TV_Drama & a,const TV_Drama & b){
    if(a.story>b.story)return true;
    else return false;
}
//函数对象，调用的时候要加()
class comparator_2{
public:
    bool operator()(const TV_Drama & a,const TV_Drama & b){
        if(a.acting_skill>b.acting_skill)return true;
        else return false;
    }
};


void Printer(const TV_Drama & a){
    cout<<a.name<<";";
}

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    list<TV_Drama> lst;
    int n;

    cin>>n;
    char  _name[100];
    int _actor, _story, _acting_skill;
    for (int i=0; i<n; i++){
        cin.ignore();
        cin.getline(_name,100);
        cin>>_actor>>_story>>_acting_skill;
        lst.push_back(TV_Drama(_name, _actor, _story, _acting_skill));
    }

    lst.sort();     //按阵容(actor)由高到低排序
    for_each(lst.begin(), lst.end(), Printer);
    cout<<endl;

    lst.sort(comparator_1); //按剧情(story)由高到低排序,函数调用,直接用函数名
    for_each(lst.begin(), lst.end(), Printer);
    cout<<endl;

    lst.sort(comparator_2());//按演技(acting_skill)由高到低排序,函数对象调用,需加()
    for_each(lst.begin(), lst.end(), Printer);
    cout<<endl;

    return 0;
}