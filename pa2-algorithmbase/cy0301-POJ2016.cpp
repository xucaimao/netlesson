/*
程序设计与算法（二）第二周测验 1:Boolean Expressions POJ2106
write by xucaimao,20171129,AC 2017-11-29 22:57:19
表达式= 项&|项...&|项
项=(表达式)
项=V or F ;这也是递归终止条件
项=!项
条件的推导，很费心思。重点在!运算符。
*/
#include<iostream>
using namespace std;
bool term();
bool exp();

bool exp(){
	bool result;
	result=term();//本行与下一行顺序不能反。开始时在这里折腾了许久
	while(cin.peek()==' ')cin.get();//跳过空格
	char op=cin.peek();
	while(op=='&' || op=='|'){
		cin.get();
		bool nextvalue=term();
		if(op=='&')result= result&&nextvalue;
		else if(op=='|')result= result||nextvalue;
		while(cin.peek()==' ')cin.get();//跳过空格
		op=cin.peek();//探测下一个运算符
	}
	return result;
}

bool term(){
	bool result;
	while(cin.peek()==' ')cin.get();//跳过空格
	char op=cin.peek();
	if(op=='('){//项=(表达式)
		cin.get();
		result=exp();
		while(cin.peek()==' ')cin.get();//跳过空格
		cin.get();
	}
	else if(op=='!'){//项=!项
		cin.get();
		result=!term();
	}
	else{//项=V or F
		if(op=='V'){result=true;cin.get();}
		else if(op=='F'){result=false;cin.get();}
	} 
	return result;
}


int main(){
	freopen("cy0301.in","r",stdin);
	char ch=cin.peek();
	int T=0;	
	while(ch!=EOF){
		cout<<"Expression "<<++T<<": ";
		bool answer=exp();
		if(answer)cout<<"V"<<endl;
		else cout<<"F"<<endl;
		if(cin.peek()=='\n')cin.get();//此行是重点
	}
	
	return 0;
}