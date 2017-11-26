#include <iostream>  
#include <string>  
#include <math.h>

using namespace std;  
const double LING = 1E-6;  
const int CONT = 4;  
const int VOLUE = 24;  
double number[CONT];  
string expression[CONT];  
bool m_judge = false; //判断是否有解。  
int ansnum = 0; 

  char* itoa(int value, char* result, int base) {  
        // check that the base if valid  
        if (base < 2 || base > 36) { *result = '\0'; return result; }  
        char bb[]="zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz";
        char* ptr = result, *ptr1 = result, tmp_char;  
        int tmp_value;  
  
        do {  
            tmp_value = value;  
            value /= base;  
            *ptr++ = bb[35 + (tmp_value - value * base)];  
        } while ( value );  
  
        // Apply negative sign  
        if (tmp_value < 0) *ptr++ = '-';  
        *ptr-- = '\0';  
        while(ptr1 < ptr) {  
            tmp_char = *ptr;  
            *ptr-- = *ptr1;  
            *ptr1++ = tmp_char;  
        }  
        return result;  
    }

void Find(int n)  
{  
    if (n == 1)  
    {  
        if ( fabs(number[0] - VOLUE) <= LING )  
        {  
            cout << expression[0] << "\t\t";  
            m_judge = true;  
            ansnum ++;  
            if((ansnum % 3)==0) //使输出时每行三个表达式  
                cout<<endl;  
        }  
        else  
        { }  
    }  
    for(int i=0; i < n; i++)//查找  
    {  
        for (int j = i + 1; j < n; j++)//与其后面的查找进行计算  
        {  
            double a, b;  
            string expressiona, expressionb;  
            a = number[i];  
            b = number[j];  
            number[j] = number[n - 1];  
            expressiona = expression[i];  
            expressionb = expression[j];  
            expression[j] = expression[n - 1];  
            expression[i]= '('+ expressiona + '+' + expressionb + ')';  
            number[i] = a + b;  
            Find(n-1);  
            expression[i]='('+ expressiona+ '-' + expressionb + ')';  
            number[i] = a - b;  
            Find(n-1);  
            expression[i] = '('+expressionb + '-' + expressiona + ')';  
            number[i] = b -a;  
            Find(n-1);  
            expression[i]= '('+ expressiona +'*'+ expressionb+ ')';  
            number[i]=a*b;  
            Find(n-1);  
            if (b != 0)  
            {  
                expression[i] ='('+expressiona+'/' + expressionb + ')';  
                number[i] = a / b;  
                Find(n-1);  
            }  
            if (a != 0)  
            {  
                expression[i]='('+expressionb + '/'+ expressiona + ')';  
                number[i] = b / a;  
                Find(n-1);  
            }  
            number[i] =a;  
            number[j]=b;  
            expression[i] = expressiona;  
            expression[j] = expressionb;  
        }  
    }  
}  
int main()  
{  
    cout<<"请输入四个数:\n";  
    for (int i = 0; i < CONT; i++)  
    {  
        char ch[20];  
        cout<<"第"<<i+1<<"个数:";  
        cin >>number[i];  
        itoa(number[i],ch, 10); //itoa()函数的作用是把第一个参数(数值)传送(转换)到第二个参数(字符串)中去，第三个参数(int型)是该数值在字符串里以什么进制存放。  
        expression[i] = ch;  
    }  
    cout<<endl;  
    Find(CONT) ;  
    if(m_judge==true)  
    {  
        cout << "\n成功！" << endl;  
        cout<<"总共的计算方法共有： "<<ansnum<<endl;  
    }  
    else  
    {  
        cout << "失败！" << endl;  
    }  
    return 0;  
}