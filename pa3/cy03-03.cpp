/*
 程序设计实习MOOC /程序设计与算法（三）第三周测验(2018春季)
 3:编程填空：统计动物数量
 write by xucaimao,2018-04-03,AC
*/

#include <iostream>
using namespace std;
// 在此处补充你的代码
class Animal{
public:
    static int number;

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

class Cat{
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

int Animal::number=0;
int Dog::number=0;
int Cat::number=0;

void print() {
    cout << Animal::number << " animals in the zoo, " << Dog::number
         << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
    print();
    Dog d1, d2;
    Cat c1;
    print();
    Dog* d3 = new Dog();
//    Animal* c2 = new Cat;
    Cat* c3 = new Cat;
    print();
    delete c3;
//    delete c2;
    delete d3;
    print();
}