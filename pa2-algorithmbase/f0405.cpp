/*
程序设计与算法（二）算法基础 第二周 递归 例题2
《算法基础与在线实践》第四章 例题5
 n皇后问题 
write by xucaimao,20171121
和lrj紫书中的讲解进行了对照，对变量名称进行了修改
*/

#include <cstdio>
#include <cmath>
//using namespace std;
const int maxn=5;
int cOfQueen[maxn];//皇后的列坐标，行坐标就是数组的下标
int N;

void nqueen(int row){
	//0~row-1皇后都已经排列好，再找第row个皇后的位置(列号)
	//第i个皇后就放在第i行，所以用r和row表示皇后的序号
	if(row==N){
		for(int r=0;r<N;r++)
			printf("%d ", cOfQueen[r]);
		printf("\n");
	}
	for(int c=0;c<N;c++){//尝试所有能否满足条件的列
		cOfQueen[row]=c;//尝试放在c列
		int ok=1;
		for(int r=0;r<row;r++){
			//和已经放好的前0~row-1个皇后的位置进行比较，看当前位置是否合法
			//列相同 或者 行-行=列-列，在45度对角线上
			if( (cOfQueen[r]==c) || r-cOfQueen[r]==row-cOfQueen[row] 
				|| r+cOfQueen[r]==row+cOfQueen[row]){
				ok=0;
				break;
			}
		}
		if(ok)nqueen(row+1);
	}
}

int main(){
	scanf("%d",&N);
	if(N>=maxn)return 0;
	nqueen(0);
	return 0;
}