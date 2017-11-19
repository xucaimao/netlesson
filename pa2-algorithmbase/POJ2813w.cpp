#include <iostream> 
#include <cstdio>
#include <cmath> 
#include <string.h>
 using namespace std; 
 int map[20][20]; 
 int line[20]; 
 char col[20]; 
 int n; 
 int min1; 
 int count=0; 
 void draw(int x, int y){ //绘制并增加绘制次数 
 	map[x][y] = !map[x][y]; 
 	map[x-1][y] = !map[x-1][y]; 
 	map[x+1][y] = !map[x+1][y]; 
 	map[x][y-1] = !map[x][y-1]; 
 	map[x][y+1] = !map[x][y+1]; 
 	count++; 
 }
 bool guess(){ //从第二行开始 判断每个点上边的点是否为黄色 如果不是黄色 则涂该点 
 	for(int i=2; i<=n; i++) 
 		for(int j=1; j<=n; j++) 
 			if(map[i-1][j] == 0) 
 				draw(i,j); 
 	//判断最后一行是否都为黄色 如果是则记录次数 否则提交失败 
 	for(int k=1; k<=n; k++) 
 		if(map[n][k] != 1) return false; 
 	if(count<min1) min1 = count; 
 	return true; 
 } 
void getLine(int k){ //通过二进制枚举第一行可能发生的所有情况 
 	int j = n; 
 	while(j>0){ 
 		line[j] = k % 2; 
 		k /= 2; j--; 
 	} 
 } 
 int main(){ 
 	int w; 
 	int copy[20][20]; 
 	cin>>w; 
 	while(w--) { 
 		cin>>n; 
 		min1 = n * n + 1; 
 		for(int i=1; i<=n; i++){ 
 			cin>>col; 
 			for(int j=1; j<=n; j++) 
 				if(col[j-1] == 'w') copy[i][j] = 0; 
 				else copy[i][j] = 1; 
 		} 
 		for(int k=0; k<pow(2.0, n); k++){ 
 			count = 0; 
 			memcpy(map, copy, sizeof(copy)); 
 			getLine(k); 
 			for(int i=1; i<=n; i++) 
 				if(line[i] == 1) 
 					draw(1,i); 
 			guess(); 
 		} 
 		if(min1 != n * n + 1) cout<<min1<<endl; 
 		else cout<<"inf"; 
 	} 
 	return 0; 
}