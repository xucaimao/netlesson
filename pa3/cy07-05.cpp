/*
 程序设计实习MOOC /程序设计与算法（三）第七周测验(2018秋季)
 5:山寨版istream_iterator
 write by xucaimao,2018-10-20
 C++标准模板库 istream_iterator模版使用说明：
 其构造函数执行过程中就会要求输入，然后每次执行++，则读取输入流中的下一个项目，
 执行 * 则返回上次从输入流中读取的项目。
*/
#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{
// 在此处补充你的代码
private:
    T data;
    istream &is;    //这里需要引用
public:
    CMyistream_iterator(istream &is_):is(is_){
        is>>data;
    }
    void operator++(int){
        //定义后++运算符
        is>>data;
    }
    T operator*(){
        return data;
    }
};



int main()
{
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int t;
    cin >> t;
    while( t -- ) {
        CMyistream_iterator<int> inputInt(cin);//读入第一个数
        int n1,n2,n3;
        n1 = * inputInt;        //第一个数赋值給n1
        int tmp = * inputInt;   //第一个数赋值給tmp
        cout << tmp << endl;
        inputInt ++;            //读入第二个数
        n2 = * inputInt;        //第二个数赋值給n2
        inputInt ++;            //读入第三个数
        n3 = * inputInt;        //第三个数赋值給n3
        cout << n1 << " " << n2<< " " << n3 << " ";
        CMyistream_iterator<string> inputStr(cin);//读入第一个字符串
        string s1,s2;
        s1 = * inputStr;
        inputStr ++;
        s2 = * inputStr;
        cout << s1 << " " << s2 << endl;
    }
    return 0;
}