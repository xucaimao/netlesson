/*
程序设计与算法（二）算法基础 第六周 动态规划 例题4
《算法基础与在线实践》例题7.4 最佳加法表达式 
write by xucaimao,2017-12-24 21:30,AC at 2017-12-26 16:59:13
大整数的处理是重点难点

*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=55;
string s;

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
	bool operator > (const BigInteger &b)const{
		//位数不相同，直接根据位数判断大小
		if(s.size() != b.s.size())return s.size()>b.s.size();
		//位数相同，从最高位开始判断
		for(int i=s.size()-1;i>=0;i--)
			if(s[i]!=b.s[i])return s[i]>b.s[i];
		return false;//相等
	}
	
	friend ostream& operator << (ostream &out,const BigInteger& x){
		//重载输出运算符<<
		for(int i=x.s.size()-1;i>=0;i--){
			out<<x.s[i];
		}
		return out;
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
BigInteger v[maxn][maxn];

BigInteger s2num(const string &str,int start,int end){
		//str[s...e]之间的字符转换成大整数
	BigInteger t;
	t.s.clear();
	int x, len=(end-start)/t.WIDTH+1;
	for(int i=0;i<len;i++){
		int e=end-i*t.WIDTH;
		//大整数的首位可能不足8位
		int s=max(start,e-t.WIDTH+1);
		sscanf(str.substr(s,e-s+1).c_str(),"%d",&x);
		t.s.push_back(x);
	}
	return t;
}

BigInteger big(){
	//定义一个无穷大的数，考虑本题数字最多50位,50/8<8
	BigInteger t;
	t.s.clear();
	int maxw=8;
	for(int i=0;i<maxw;i++)
		t.s.push_back(99999999);
	return t;
}

BigInteger solve(int m,int n){
	//记忆式的递归程序
	if(v[m][n]>0)return v[m][n];
	if(m==0)return num[1][n];
	else if(n-1<m) return big();
	else{
		BigInteger ans=big();
		for(int i=m;i<=n-1;i++){
			BigInteger t=solve(m-1,i)+num[i+1][n];
			if(t<ans)ans=t;//记录小值
		}
		v[m][n]=ans;
		return ans;
	}
}

int main(){
	freopen("in.txt","r",stdin);
	int m=0;
	while(scanf("%d",&m)!=EOF){
		getchar();
		memset(num,0,sizeof(num));
		memset(v,0,sizeof(v));
		cin>>s;
		s=" "+s;//
		//cout<<s<<endl;
		int len=s.length();
		//初始
		for(int i=1;i<len;i++)
			for(int j=i;j<len;j++){
				num[i][j]=s2num(s,i,j);
				// cout<<"["<<i<<","<<j<<"]=";
				// cout<<num[i][j]<<endl;
			}
		
		BigInteger ans= solve2(m,len-1);
		cout<<ans<<endl;
	}
	return 0;
}
