/*
程序设计实习MOOC / 程序设计与算法（一）第十周测验(2017冬季)  
5:从字符串中取数
write by xucaimao,2018-01-10 18:20,AC 2018-01-11 11:42:39
需要用到静态变量
*/

#include <iostream>
#include <iomanip>
using namespace std;
double GetDoubleFromString(char * str)
{
// 在此处补充你的代码
	static char *p;
    if(str!=NULL) p=str;//第一次调用时指向字符串
    if(*p=='\0')return -1; 
    double t1=0,t2=0;//定义整数位和小数位 
    bool havedot=0;
    while( (*p<'0' || *p>'9') && *p!='\0' )p++;//找到第一个数字字符 
    while(*p>='0' && *p<='9'){//处理小数点前的数字 
        t1=t1*10+*p-'0';
        p++;
    }
    if(*p=='.'){
        p++;
        havedot=1;
    }
    if(havedot){//处理小数点后的数字 
        double dig=1;
        while( (*p>='0' && *p<='9') && *p!='\0' ){
            dig/=10;
            t2+=(*p-'0')*dig;
            p++;
        }
    }
    return t1+t2;
}

int main()
{
	char line[300];
	while(cin.getline(line,280)) {
		double n;
		n = GetDoubleFromString(line);
		while( n > 0) {
			cout << fixed << setprecision(6) << n << endl;
			n = GetDoubleFromString(NULL);
		}
	}
	return 0;
}