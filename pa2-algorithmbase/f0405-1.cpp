/*
程序设计与算法（二）算法基础 第二周 递归 例题2
《算法基础与在线实践》第四章 例题5
 n皇后问题 
write by xucaimao,20171121,20171126 20:30AC
和lrj紫书中的讲解进行了对照，对变量名称进行了修改
数组下标一定要开大一些
*/

#include <cstdio>

const int N=8;
int ans[95];//以整数形式存储92组解，便于后期排序打印
int ansnum=0;//解的序号
int cOfQueen[10];//皇后的列坐标，行坐标就是数组的下标



template <typename T>
T myabs(T n){
	if(n<0) n*=-1;
	return n;
}


void nqueen(int row){
	//0~row-1皇后都已经排列好，再找第row个皇后的位置(列号)
	//第i个皇后就放在第i行，所以用r和row表示皇后的序号
	if(row==N){
		ansnum++;
		int t=0;
		for(int i=0;i<N;i++)
			t=t*10+cOfQueen[i];
		ans[ansnum]=t;
	}
	for(int c=1;c<=N;c++){//尝试所有能否满足条件的列
		cOfQueen[row]=c;//尝试放在c列
		int ok=1;
		for(int r=0;r<row;r++){
			//和已经放好的前0~row-1个皇后的位置进行比较，看当前位置是否合法
			//列相同 或者 |行-行|=|列-列|，在45度对角线上
			if( (cOfQueen[r]==c) || myabs(r-row)==myabs(cOfQueen[r]-c)){
				ok=0;
				break;
			}
		}
		if(ok)//找到第row个皇后的合适位置，开始找下一个皇后的位置
			nqueen(row+1);
	}
}

int main(){
	int T,n;
	scanf("%d",&T);
	nqueen(0);//从0开始
	while(T--){
		scanf("%d",&n);
		printf("%d\n",ans[n] );
	}
	return 0;
}