/*
程序设计与算法（二）额外练习 画家问题 POJ2813
write by xucaimao,20171119,23:00测试通过
落笔会使本身及其上下左右四块颜色发生反转
*/
#include<cstdio>
#include<cstring>
const int maxn=20;
int wal[maxn][maxn];
int tmp[maxn][maxn];
int cmd[maxn][maxn];


int main(){
	freopen("POJ2813.in","r",stdin);
	int n;
	scanf("%d",&n);
	getchar();
	for(int r=1;r<=n;r++){
		for(int c=1;c<=n;c++){
			char ch;
			scanf("%c",&ch);
			if(ch=='w')//w=1,y=0
				wal[r][c]=1;
			else wal[r][c]=0;
		}
		getchar();//这是个坑，开始没有这行，导致输入错误，
		//但样本的结果却是正确的，提交就WA。debug才发现错误
	}
		
		
	int maxv=(1<<n);
	int ans=n*n+1;//涂的最多次
	bool haveans=false;//有成功
	for(int command=0;command<maxv;command++){//枚举第一行的各种状态
		memcpy(tmp,wal,sizeof(wal));
		memset(cmd,0,sizeof(cmd));
		int t=command;
		for(int i=1;i<=n;i++){//命令变二进制
			cmd[1][i]=t%2;
			t/=2;
		}
		int count=0;//统计本次涂画的次数
		for(int r=1;r<=n;r++){//处理n行
			for(int c=1;c<=n;c++){//处理一行内的n列
				if(cmd[r][c]){//进行涂画
					tmp[r][c]^=1;
					tmp[r][c-1]^=1;
					tmp[r][c+1]^=1;
					tmp[r-1][c]^=1;
					tmp[r+1][c]^=1;
					count++;
				}
			}
			//本行处理完毕后，若还有白色没有改过来，则需要通过下一行进行命令进行修改
			for(int c=1;c<=n;c++)
				if(tmp[r][c])cmd[r+1][c]=1;
		}
		int ok=1;
		for(int r=1;ok && r<=n;r++)
		for(int c=1;ok && c<=n;c++)
			if(tmp[r][c]==1)//还有白色方块
				{ok=0;break;}
		if(ok && count<ans) {ans=count;haveans=1;}
	}
	if(haveans)printf("%d\n", ans);	
	else printf("inf\n");
	return 0;
}