/*
程序设计与算法（二）算法基础 第六周 动态规划 例题4
《算法基础与在线实践》例题7.4 最佳加法表达式 
write by xucaimao,2017-12-24 21:30,
大整数
注意读入整数字符串的时候，高位在前(字符数组的低位)
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=55;
char str[maxn],ans[maxn];

struct BigInteger{
	static const int BASE=100000000;
	static const int WIDTH=8;
	vector<int> s;

	BigInteger(long long num=0){*this=num;}//构造函数
	BigInteger operator = (long long num){
		//重载赋值预算符,整数到大整数
		s.clear();
		do{
			s.push_back(num%BASE);
			num/=BASE;
		}while(num>0);
		return *this;
	}
	bool operator < (const BigInteger &b)const{
		//位数不相同，直接根据位数判断大小
		if(s.size() != b.s.size())return s.size()<b.s.size();
		//位数相同，从最高位开始判断
		for(int i=s.size()-1;i>=0;i--)
			if(s[i]!=b.s[i])return s[i]<b.s[i];
		return false;//相等
	}
	BigInteger operator = (const string &str){
		//重载赋值预算符,string建成大整数
		s.clear();
		int x;
		int len=(str.length()-1)/WIDTH+1;//大整数所占用的整数的位数
		for(int i=0;i<len;i++){
			//str[start...end)的字符串转变成int
			int end=str.length()-i*WIDTH;
			int start=max(0,end-WIDTH);//防止不够8位产生越界
			//读取格式化字符串中的数据
			sscanf(str.substr(start,end-start).c_str(),"%d",&x);
			s.push_back(x);
		}
		return *this;
	}
	

	friend ostream& operator << (ostream &out,const BigInteger& x){
		//重载输出运算符<<
		for(int i=x.s.size()-1;i>=0;i--){
			out<<x.s[i];
		}
		return out;
	}
	friend istream& operator >> (istream &in,BigInteger& x){
		string s;
		if(!(in>>s))return in;
		x=s;
		return in;
	}
	BigInteger operator + (const BigInteger& b) const {
		BigInteger c;
		c.s.clear();
		for(int i=0,g=0;;i++){
			//g是进位的值
			if(g==0 && i>=s.size() && i>=b.s.size())break;
			int x=g;
			if(i<s.size())x+=s[i];//如果存在此位,就加上
			if(i<b.s.size())x+=b.s[i];
			c.s.push_back(x%BASE);
			g=x/BASE;
		}
		return c;
	}
	BigInteger operator += (const BigInteger& b){
		*this=*this+b;
		return *this;
	}
};
//用于一次性把str[s...e]构建成大整数,避免后期重复计算
BigInteger num[maxn][maxn];

int main00(){
	freopen("in.txt","r",stdin);
	int m=0;
	while(scanf("%d",&m)!=EOF){
		scanf("%s",num);

		//solve(num,m);
		printf("%s\n",ans );
	}
	return 0;
}

int main(){
	string s="1234567897654";
	int len=s.length();
	BigInteger t=s2num(s,0,12);
	cout <<t<<endl;
	// for(int i=0;i<len-1;i++)
	// 	for(int j=i+1;j<len;j++){

	// 		num[i][j]=s2num(s,i,j);
	// 		cout<<num[i][j]<<endl;
	// 	}
	return 0;
}