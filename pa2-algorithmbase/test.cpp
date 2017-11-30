#include<iostream>
using namespace std;
int main(){
	char c=cin.peek();
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
	cout<<befdot+aftdot<<endl;
	return 0;
}