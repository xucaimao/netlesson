//
// Created by xcm on 2020/5/19.
//

#ifndef DS_LYB_HEAP_H
#define DS_LYB_HEAP_H

#include <iostream>
#include <cmath>
using namespace std;
//最大堆--父节点比任一孩子结点的值都要大
template <typename Item>
class MaxHeap{
private:
    Item* data;
    int count;      //实际元素数量
    int capacity;   //堆的容量

    //插入元素后，维护堆定义的正确性
    void shiftUp(int p){
        while(p>1 && data[p/2]<data[p]){
            swap(data[p],data[p/2]);
            p/=2;
        }
    }
    //自己开始写的，正确但是繁琐
    void shiftDown0(int p){
        while(true){
            int target=p;       //寻找交换的目标位置
            if(p*2+1<=count){   //有两个孩子结点,找到大的
                if(data[p*2]<data[p*2+1])
                    target=p*2+1;
                else
                    target=p*2;
            }
            else if(p*2<=count)
                target=p*2;
            else break;         //没有孩子结点了
            if(data[p]<data[target]){
                swap(data[p],data[target]);
                p=target;
            }
            else break;
        }
    }
    //教程的写法，逻辑优化
    void shiftDown(int p){
        while(p*2<=count){//有左孩子
            int target=p*2;
            //有右孩子且右孩子比左孩子大
            if(target+1 <= count && data[target]< data[target+1])
                target++;
            //此时target指向两个孩子中大的那一个
            //下面条件成立，说明父结点比孩子结点都大，满足最大堆的定义
            if(data[p]>data[target])
                break;
            //data[p]<data[target],父节点比子结点小，不满足最大堆的定义，需要交换数据
            swap(data[p],data[target]);
            p=target;
        }
    }
    //此程序主要是减少swap的次数，类似于插入排序。

    void addSize(){
        Item* temp=data;
        data=new Item[capacity*2+1];
        for(int i=0;i<=capacity;i++)
            data[i]=temp[i];
        capacity*=2;    //堆的容量加倍
        delete[] temp;
    }

    void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }

public:
    //考虑数组容量的问题
    void insert(Item item){
        if(count+1 >capacity){
            cout<<"Alert: add size!!!"<<endl;
            addSize();
        }

        data[++count]=item;
        shiftUp(count);
    }
    //构造函数，设置容量的初始值
    MaxHeap(int capacity=10){
        this->capacity=capacity;
        data=new Item[capacity+1];
        count=0;
    }
    //构造函数，根据数组创建堆
    MaxHeap(Item arr[],int n){
        capacity=n;
        data=new Item[capacity+1];
        count=n;
        for(int i=n/2;i>=1;i--)
            shiftDown(i);
    }
    ~MaxHeap(){
        delete [] data;
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count==0;
    }

    //取出堆中的最大元素(堆顶元素)并删除
    Item extractMax(){
        assert(count>0);
        Item item=data[1];
        data[1]=data[count--];
        shiftDown(1);
        return item;
    }
    //以树形打印整数堆
    void print(){

        if( size() >= 100 ){
            cout<<"Fancy print can only work for less than 100 int";
            return;
        }

        if( typeid(Item) != typeid(int) ){
            cout <<"Fancy print can only work for int item";
            return;
        }

        cout<<"The Heap size is: "<<size()<<endl;
        cout<<"data in heap: ";
        for( int i = 1 ; i <= size() ; i ++ )
            cout<<data[i]<<" ";
        cout<<endl;
        cout<<endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for( int level = 0 ; level < max_level ; level ++ ){
            string line1 = string(max_level_number*3-1, ' ');

            int cur_level_number = min(count-int(pow(2,level))+1,int(pow(2,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            cout<<line1<<endl;

            if( level == max_level - 1 )
                break;

            string line2 = string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            cout<<line2<<endl;

            cur_tree_max_level_number /= 2;
        }
    }

};


int mymain0(){
//    MaxHeap<int> heap=MaxHeap<int>(100);
    int n=20;
    int arr[n];
    srand(time(NULL));
    for(int i=0;i<n;i++)
        arr[i]=(rand()%100);
    MaxHeap<int> heap=MaxHeap<int>(arr,n);
    heap.print();
    for(int i=0;i<n;i++){
        cout<< heap.extractMax()<<" ";
//        heap.print();
    }
    cout<<endl;

    return 0;
}

#endif //DS_LYB_HEAP_H
