/*
POJ2978:Help Jimmy 网上程序
本题是动态规划题，找出最优路径（最少时间），这题的题目意思也不难懂，子问题就是一条杠的左端点和右端点的最优解，
中间有一个问题是不是每条杆都需要一步步走（而是当高度不大于Max的时候，且X的位置处于下一条两端点之间），我是用
递归且保存每个端点的最优解，最后返回到初始状态，得到结果。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Node{
	int left;
	int right;
	int H;
};
int Left[1005],Right[1005];

int DP_Recur(int X,int Y,int Max,int i,int N,Node P[]){
	if(P[i].H==0) return Y;
	while(i<=N){
		if(P[i].left<=X && X<=P[i].right){
			//找到下一块板子i
		    if(Y-P[i].H>Max) return 20000;
		    if(P[i].H==0) return Y;
			if(Left[i]>20000)
				Left[i]=DP_Recur(P[i].left,P[i].H,Max,i+1,N,P);
			if(Right[i]>20000)
				Right[i]=DP_Recur(P[i].right,P[i].H,Max,i+1,N,P);
		    int min=((X-P[i].left)+Left[i])<((P[i].right-X)+Right[i])?((X-P[i].left)+Left[i]):((P[i].right-X)+Right[i]);
		    return (Y-P[i].H)+min;
		}
		i++;
	}
	return 20000;
}

int main(){
	freopen("in.txt","r",stdin);
	int T=0;
	cin>>T;
	while(T--){
		int N=0,X=0,Y=0,Max=0;
		cin>>N>>X>>Y>>Max;
		Node P[1005];
		int i=0;
		while( i < N ) {
			cin>>P[i].left>>P[i].right>>P[i].H;
			i++;
		}
		P[i].left=-20000;
		P[i].right=20000;
		P[i].H=0;
		for(i=0;i<N-1;i++){
			int j=i+1;
			while(j<N){
				if(P[i].H<P[j].H){
					Node temp;
					temp=P[j];
					P[j]=P[i];
					P[i]=temp;
				}
				j++;
			}
		}
		memset(Left,1,sizeof(Left));
		memset(Right,1,sizeof(Right));
		cout<<DP_Recur(X,Y,Max,0,N,P)<<endl;
	}
	return 0;
}