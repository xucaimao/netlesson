//程序设计实习MOOC / 程序设计与算法（三）第五周测验(2018秋季)
//4:编程填空：统计动物数量
// Created by xucaimao on 2018/10/01.
//静态变量及初始化；虚函数的作用
//
#include <iostream>
using namespace std;
// 在此处补充你的代码
//这里的Animal只是一个抽象类，数量的变更应该都是有后面继承的具体类来产生
class Animal{
public:
    static int number;
    virtual ~Animal(){}
};
class Dog:public Animal{
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
class Cat:public Animal{
public:
    static int number;
    Cat(){
        number++;
        Animal::number++;
    }
    ~Cat(){
        number--;
        Animal::number--;
    }
};

int Animal::number=0,Dog::number=0,Cat::number=0;

void print() {
    cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
    print();
    Dog d1, d2;
    Cat c1;
    print();
    Dog* d3 = new Dog();
    Animal* c2 = new Cat;   //这里c2的类型是Animal，new函数会触发Cat类的构造函数
    Cat* c3 = new Cat;
    print();
    delete c3;
    delete c2;  //会触发Animal类的析构函数，如果没有在Animal类中定义虚的析构函数，就不会触发Cat类的析构函数
    //
    delete d3;
    print();
}