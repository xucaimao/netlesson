/*
程序设计与算法（二）第一周测验2 拨钟问题 POJ1816
write by xucaimao,20171116,23:00
本题主要学习利用二进制法枚举子集
本程序题目样例可以通过，但提交时WA
错误在于，一个输入可能要有多次才能满足要求。枚举子集的方法不能满足此要求

*/
#include<cstdio>
#include<cstring>
int clk[9];
int tar[9];
int mov[9];//根据选取的移动序列，计算转动次数的临时数组
//数组从0开始，最后输出要注意转化
char mvstr[9][6]={"ABDE","ABC","BCEF","ADG","BDEFH",
                  "CFI","DEGH","GHI","EFHI"};

bool check(int v){
	//根据数字n的二进制位判断能否满足条件
	memset(mov,0,sizeof(mov));
	for(int i=0;i<9;i++){
		if( v&(1<<i) ){//当前i位为1
			int len=strlen(mvstr[i]);//当前位对应的移动序列的长度
			for(int j=0;j<len;j++){//根据当前移动序列改变mov数组的值
				int p=mvstr[i][j]-'A';
				mov[p]++;
				if(mov[p]>tar[p])//大于需要的转动次数，提前终止
					return false;
			}
		}
		
	}
	for(int i=0;i<9;i++)
		if(mov[i]!=tar[i])
			return false;
	return true;
}

int main(){
	
	freopen("in-cy0102.txt","r",stdin);
	for(int i=0;i<9;i++){
		scanf("%d",&clk[i]);//读入第i号钟的初始状态
		tar[i]=(4-clk[i])%4;//储存第i号钟需要转动的次数
	}
	//开始枚举子集(二进制法)
	int v=0;
	int maxn=(1<<9);
	for(;v<maxn;v++){
		if(check(v))break;
	}
	int t=0;
	for(int i=0;i<9;i++){
		if( v&(1<<i) ){
			if(t>0)printf(" ");
			printf("%d",i+1);
			t++;
		}
	}
	printf("\n");

	return 0;
}