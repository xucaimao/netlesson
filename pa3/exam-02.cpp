// 程序设计与算法（三）期末考试(2018秋季)
// 002:编程填空：统计动物数量
// Created by Administrator on 2018-11-10.
//
/*
输入
 无
输出
 0 animals in the zoo, 0 of them are dogs, 0 of them are cats
 3 animals in the zoo, 2 of them are dogs, 1 of them are cats
 6 animals in the zoo, 3 of them are dogs, 3 of them are cats
 3 animals in the zoo, 2 of them are dogs, 1 of them are cats
 * */
#include <iostream>
using namespace std;
// 在此处补充你的代码
class Animal{
public:
    static int number;
    virtual ~Animal(){};    //重点是这里
};

class Dog{
public:
    static int number;
    Dog(){
        number++;
        Animal::number++;
    }
    ~Dog(){
        number--;
        Animal::number--;
    }
};

class Cat :public Animal    //重点是这里
{
public:
    static int number;
    Cat(){
        number++;
        Animal::number++;
    }
    virtual ~Cat(){ //这里的virtual可以省略
        number--;
        Animal::number--;
    }

};

int Animal::number=0;
int Dog::number=0;
int Cat::number=0;


void print() {
    cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
    print();
    Dog d1, d2;
    Cat c1;
    print();
    Dog* d3 = new Dog();
    Animal* c2 = new Cat;
    Cat* c3 = new Cat;
    print();
    delete c3;
    delete c2;
    delete d3;
    print();
}