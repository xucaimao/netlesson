/*
程序设计与算法（二）算法基础 第三周 递归 例题1
 四则运算表达式求值 POJ4132 
write by xucaimao,20171127,AC 2017-11-27 22:13:31
表达式、项、因子 的递归定义是重点
出现数字，实际上是递归终止的条件
*/
#include <cstdio>
#include <iostream>

using namespace std;
double factor_value();
double term_value();
double exp_value();

double term_value(){
	//求项的值
	//项=因子*or/因子*or/...
	double result=factor_value();
	while(true){
		char op=cin.peek();
		if(op=='*'||op=='/'){
			cin.get();
			double value=factor_value();
			if(op=='*')result*=value;
			else result/=value;
		}
		else break;
	}
	return result;
}

double factor_value(){
	//求因子的值
	//因子=(表达式) or 一个数
	//数由字符转成数，是难点
	double result=0;
	char c=cin.peek();
	if(c=='('){
		cin.get();//读入'('
		result=exp_value();
		cin.get();//读入')'
	}
	else{//读入数字字符串，并转化成数字
		double befdot=0,aftdot=0;
		bool hasdot=false;
		double dig=0.1;//小数点后的位数
		while( (c>='0' && c<='9') || c=='.' ){
			cin.get();
			if(c>='0' && c<='9'){
				if(hasdot){//计算小数点后
					aftdot+=(c-'0')*dig;
					dig*=0.1;
				}
				else
					befdot=befdot*10+c-'0';
			}
			else hasdot=true;//遇到小数点，设置标志
			c=cin.peek();//再看下一个字符
		}
		result=befdot+aftdot;
	}
	return result;
}

double exp_value(){
	//求表达式的值
	//表达式=项+or-项+or-...
	double result=term_value();
	while(true){
		char op=cin.peek();//看
		if(op=='+' || op=='-'){
			cin.get();//实际读入字符
			double value=term_value();
			if(op=='+')
				result+=value;
			else result-=value;
		}
		else
			break; 
	}
	return result;
}

int main(){
	printf("%.2lf\n", exp_value());
	return 0;
}