/*
《算法基础与在线实践》练习题4-5 扩号匹配问题 POJ3704
write by xucaimao,20171122 21:00开始编程，
非递归方式 21:40测试通过
*/
#include<cstdio>
#include <cstring>
using namespace std;
const int maxn=110;
char s[maxn];
int stack[maxn];

void solve(char s[],int len){
	//非递归方式
	int stp=0;//此时栈空
	for(int i=0;i<len;i++){
		if(s[i]=='('){
			stp++;
			stack[stp]=i;//栈记录'('在字符数组的位置
		}
		else if(s[i]==')'){
			if(stp>0){//栈非空，说明有'('可以匹配
				s[stack[stp]]=' ';//最近匹配的'('清除
				s[i]=' ';//')'清除
				stp--;
			}
		}
		else s[i]=' ';//字母清除
	}
	for(int i=0;i<len;i++){//对没有被清除的'('和')'做标记
		if(s[i]=='(') s[i]='$';
		if(s[i]==')') s[i]='?';
	}
}

int main(){
	freopen("e0405.in","r",stdin);
	while(scanf("%s",s)!=EOF){
		printf("%s\n",s);
		solve(s,strlen(s));
		printf("%s\n",s );
	}
	
	return 0;
}