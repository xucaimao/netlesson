/*
程序设计实习MOOC / 程序设计与算法（一）第五周测验(2017冬季)  
5:计算鞍点
//本题其实应该明确不存在重复元素
write by xucaimao,2017-12-05-20:00
*/

#include<cstdio>
#include <cstring>
const int maxn=5;
int d[maxn+2][maxn+2];
int colOfRowMax[maxn+2];//记录所在行最大值所在的列号
int rowOfColMin[maxn+2];//记录所在列最小值所在的行号

int main(){
	freopen("in.txt","r",stdin);
	for(int r=0;r<maxn;r++){
		for(int c=0;c<maxn;c++){
			//读取数据的时候同时记录行最大值和列最小值
			//这里其实隐含了两句
			//rowOfColMin[c]=0;
			//colOfRowMax[r]=0;
			scanf("%d",&d[r][c]);
			if(d[r][c]>d[r][colOfRowMax[r]])
				colOfRowMax[r]=c;
			if(d[r][c]<d[rowOfColMin[c]][c])
				rowOfColMin[c]=r;
		}
	}
	bool haveans=0;
	for(int r=0;r<maxn;r++)
		for(int c=0;c<maxn;c++){
			if(colOfRowMax[r]==c && r==rowOfColMin[c]){
				//输出是行列号从1开始
				printf("%d %d %d\n",r+1,c+1,d[r][c]);
				haveans=1;
			}
		}
	if(!haveans)printf("not found\n");
	return 0;
}

