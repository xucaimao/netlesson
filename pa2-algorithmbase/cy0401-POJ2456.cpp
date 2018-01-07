/*
程序设计与算法（二）第四周测验 1:Aggressive cows POJ2456
write by xucaimao,2017-12-14
*/
#include<cstdio>
#include <algorithm>

const int maxn=100000+10;
int stall[maxn];
int numOfStall,numOfCow;

bool check(int dist){
	int ok=0;
	int count=1,pre=stall[0];//把第一头牛放在编号为stall[0]的栏里面
	for(int i=1;i<numOfStall;i++){
		if(stall[i]-pre >= dist){
			//判断当前围栏与前一个放了牛的围栏之间的距离，
			//>=dist时，说明可以放牛
			count++;
			pre=stall[i];
			if(count>=numOfCow){//可以提前结束循环，加快速度
				ok=1;break;
			}
		}
	}
	return ok;
}

void solve(int l,int r){
	int ans=0;
	while(l<=r){
		int mid=(r-l)/2+l;
		if(check(mid)){
			//当前距离满足条件
			ans=mid;//迭代记录满足条件的最小距离(越来越大)
			l=mid+1;//加大距离
		}
		else
			r=mid-1;//减小距离
	}
	printf("%d\n",ans );
}

int main(){
	freopen("cy0401.in","r",stdin);
	scanf("%d%d",&numOfStall,&numOfCow);
	for(int i=0;i<numOfStall;i++)
		scanf("%d",&stall[i]);
	std::sort(stall,stall+numOfStall);

	solve(0,stall[numOfStall-1]-stall[0]);

	return 0;
}