/*
程序设计与算法（二）算法基础 第二周 递归 例题2
《算法基础与在线实践》第四章 例题5
 n皇后问题 
write by xucaimao,20171125,20171126 20:30AC
和lrj紫书中的讲解进行了对照，对变量名称进行了修改
采用vis数组加快判定速度,减少了一个循环
*/

#include <cstdio>
const int qNum=8;
int cOfQueen[10];
int vis[3][20];//列、r+c、r-c对角线
char ans[95][10];//以字符串形式存储92组解，便于后期打印
int ansnum=0;//解的序号


void nqueen(int r){
	if(r==qNum){
		ansnum++;
		for(int i=0;i<qNum;i++)
			ans[ansnum][i]=cOfQueen[i]+'0';
	}
	else
		for(int c=1;c<=qNum;c++){//尝试把第r个皇后放在列c
			if(!vis[0][c] && !vis[1][r+c] && !vis[2][r-c+8]){
				cOfQueen[r]=c;
				vis[0][c]=vis[1][r+c]=vis[2][r-c+8]=1;
				nqueen(r+1);
				vis[0][c]=vis[1][r+c]=vis[2][r-c+8]=0;
			}
		}	
}

int main(){
	int T,n;
	scanf("%d",&T);
	nqueen(0);//从0开始
	printf("Total answer number is : %d\n",ansnum );
	while(T--){
		scanf("%d",&n);
		printf("%s\n",ans[n] );
	}
	return 0;
}