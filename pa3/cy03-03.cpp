/*
 程序设计实习MOOC /程序设计与算法（三）第三周测验(2018春季)
 3:编程填空：统计动物数量
 write by xucaimao,2018-04-04,AC
*/

#include <iostream>
using namespace std;
// 在此处补充你的代码
//Animal是基类
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
    Animal* c2 = new Cat;
    //c2指向Cat类对象，也就是基类指针可以指向派生类对象，但是反过来就不行
    //不采用继承，编译会出错，因为等号两侧类型不匹配
    Cat* c3 = new Cat;
    print();
    delete c3;
    delete c2;
    delete d3;
    print();
}
// c2是Animal*类型的指针，同时c2指向了Cat类。当执行delete c2时，会调用析构函数。
// 此时，先看指针类的析构函数是不是虚函数。如果不是虚函数，则直接执行（包括默认析构函数）
// 如果是虚函数，则执行所指向对象的析构函数。
// 也就是说，delete c2时，如果Animal类没有虚析构函数，则会执行相应的Animal类的析构函数
// 没有定义析构函数，就是采用缺省析构函数，此时将什么都不做，从而导致结果错误
// 一旦在Animal类中定义了虚析构函数，则会执行所指向对象（Cat类）的析构函数，从而得到正确结果
// 虚函数的作用: 根据指针所指向的具体对象的类型（而不是指针或引用的类型），选择具体的析构函数。