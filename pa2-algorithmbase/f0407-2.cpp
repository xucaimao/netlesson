/*
程序设计与算法（二）算法基础 第二周 递归 例题1
《算法基础与在线实践》第四章 例题7
 算24点 POJ2787
write by xucaimao,20171124 20:30开始编程
扩展打印表达式的功能
*/

#include <cstdio>
#include <cmath>
double in[5];//用于储存输入及中间数据
vector<int> ans;//用于记录答案，+ — * / 用-1~-4表示
int ansnum=0;

void solve(double in[],int len){
	//对有len个元素的数组in,求24点的解法
	double tmp[5];//必须采用新申请空间的局部数组
	//
	if(len==1 && in[0]>0 && fabs(in[0]-24.0)<1e-6 )ansnum++;
	else if(len>=2){//最少两个变量，才能进行计算
		for (int i = 0; i < len; ++i)
			for (int j = 0; j < len; ++j){
				if(j==i)continue;
				int m=0;//用于统计tmp数组中的元素数量
				for (int k = 0; k < len; ++k)
					if(k!=i && k!=j){
						tmp[m]=in[k];
						m++;
					}
				//记录
				tmp[m]=in[i]+in[j];
				solve(tmp,m+1);
				tmp[m]=in[i]-in[j];
				solve(tmp,m+1);
				tmp[m]=in[i]*in[j];
				solve(tmp,m+1);
				if(in[j]!=0)
					tmp[m]=in[i]/in[j];
				solve(tmp,m+1);
			}
	}
}

int main(){
	freopen("f0407.in","r",stdin);
	while(1){
		for (int i = 0; i < 4; ++i)
			scanf("%lf",&in[i]);
		if(!in[0])break;
		ansnum=0;
		solve(in,4);
		printf("%s\n",ansnum>0 ? "YES" : "NO" );
	}
	return 0;
}