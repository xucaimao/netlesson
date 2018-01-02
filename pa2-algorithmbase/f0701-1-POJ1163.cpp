/*
程序设计与算法（二）算法基础 第六周 动态规划 例题1 The Triangle POJ1163
write by xucaimao,2017-12-20 15:50,
直接在二维数组内部进行运算，节省空间，但是会对原始数据造成破坏
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=110;
int data[maxn][maxn];


int main(){
	freopen("in.txt","r",stdin);
	int n=0;
	scanf("%d",&n);
	for(int r=1;r<=n;r++)
		for(int c=1;c<=r;c++)
			scanf("%d",&data[r][c]);

	for (int r = n-1; r>=1; r--){
		//从倒数第二行开始
		for(int c=1;c<=r;c++){
			int t=max( data[r+1][c],data[r+1][c+1] );
			data[r][c]+=t;
		}
	}

	printf("%d\n",data[1][1]);

	return 0;
}