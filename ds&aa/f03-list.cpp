//
// Created by xcm on 2018/9/17.
//

#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

template <typename T>
class List{
private:
    struct Node{
        T data;
        Node * prev;
        Node * next;
        //value=T{},这一句不可少
        Node(const T& value=T{},Node* p=NULL,Node* n=NULL):data{value},prev{p},next{n}{}
    };
    int theSize;
    Node* head;
    Node* tail;

    void init(){
        theSize=0;
        head=new Node;
        tail=new Node;
        head->next=tail;
        tail->prev=head;
    }
public:
    void insert(Node* p,const T & x){
        theSize++;
        Node * t=new Node{x,p->prev,p};
        p->prev->next=t;
        p->prev=t;
    }
    //删除p所指向的节点
    void erase(Node* p){
        Node* t=p;
        p->prev->next=p->next;
        p->next->prev=p->prev;
        delete t;
        theSize--;
    }
    //清除链表的数据节点
    void clear(){
        while(head->next != tail){
            erase(head->next);
        }
    }

    List(){
        init();
    }

    List(const List & rhs){
        init();
        Node* p=rhs.head->next;
        while(p != rhs.tail){
            push_back(p->data);
            p=p->next;
        }
    }
    ~List(){
        clear();
        delete head;
        delete tail;
    }

    List &operator=(const List& rhs){
        List copy(rhs);
        std::swap(*this,copy);
        return *this;
    }

    //在链表尾部插入一个节点
    void push_back(const T & x){
        insert(tail,x);
    }
    //在链表头部插入一个节点
    void push_front(const T & x){
        insert(head->next,x);
    }
    void pop_back(){
        erase(tail->prev);
    }
    void pop_front(){
        erase(head->next);
    }
    //在p所指向的节点前，插入一个新节点，新节点的数据域为x


    void print(){
        Node * p=head->next;
        int pn=0;
        cout<<"SIZE : "<<theSize<<" | DATA : ";
        while(p != tail){
            if(pn>0) cout<<" ";
            cout<< p->data;
            pn++;
            p=p->next;
        }
        cout<<endl;
    }

};

int main() {
    List<int> a;
    a.print();
    for(int i=1;i<=5;i++) a.push_back(i);
    a.print();
    for(int i=1;i<=5;i++) a.push_front(i);
    a.print();
    List<int> b(a);

    b.print();
    return 0;
}