/*
程序设计与算法（二）算法基础 第十一周 贪心算法 例题4 POJ1328
《算法基础与在线实践》例题6.4 Radar Installation
write by xucaimao,2018-02-01 20:30,AC at 

*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct LineSegment{
	double start,end;
	bool operator <(const LineSegment & b)const{
		return start<b.start;
	}
};
LineSegment lseg[1010];
int N;

int solve(){
	sort(lseg,lseg+N);//线段排序
	int ans=1;
	double now=lseg[0].end;
	for(int i=1;i<N;i++){
		if(lseg[i].start<=now)
			now=min(now,lseg[i].end);
		else{
			ans++;
			now=lseg[i].end;
		}
	}
	return ans;
}

int main(){
	freopen("in.txt","r",stdin);
	int R;
	int x,y;
	int T=0;
	while(1){
		scanf("%d%d",&N,&R);
		if(N==0)break;
		bool haveans=1;
		T++;
		for(int i=0;i<N;i++){
			scanf("%d%d",&x,&y);
			if(y>R)
				haveans=0;
			if(haveans){
				double dx=sqrt(R*R-y*y);
				lseg[i].start=(double)x-dx;
				lseg[i].end=(double)x+dx;
			}
		}
		if(haveans)
			printf("Case %d: %d\n",T,solve() );
		else
			printf("Case %d: -1\n",T);
	}
	
	return 0;
}