/*
程序设计与算法（二）算法基础 第六周 动态规划 例题2 POJ1724
《算法基础与在线实践》例题8.3 ROADS
write by xucaimao,2018-01-08 21:20,AC at 2018-01-08 23:20:32
求最优路径，关键是几种剪枝方法的运用

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Road{
	int end,length,cost;
};
const int maxn=110;
vector<Road>  G[maxn];//领接表形式的图
int vis[maxn]={0};
int minL[105][10010];//minL[i][j]表示从城市1到i,花费为j时的最短路程的长度
int K,N,R;//总的钱数,城市数,道路数
int BIG=10000*100+100;//定义极大值
int minLength=BIG;
int curLen=0,curCost=0;//定义当前路程及花费

void dfs(int cityId){
	if(cityId==N)//到达目的地
		minLength=min( minLength,curLen );
	else{
		//遍历与cityId相邻的各个城市
		for(int i=0;i<G[cityId].size();i++){
			Road r=G[cityId][i];//这种写法学习了
			int nCity=r.end;
			int nCost=curCost+r.cost;//到达下一城市所需要的费用
			int nLen=curLen+r.length;//到达下一城市所需要的路程
			if(!vis[nCity]){
				if(nCost > K)//钱不够,可行性剪枝
					continue;
				if(nLen>=minLength)//路程超过已有值,最优化剪枝
					continue;
				if(nLen>=minL[nCity][nCost])
					continue;
				curCost+=r.cost;
				curLen+=r.length;
				vis[nCity]=1;
				minL[nCity][nCost]=curLen;//保存数据
				dfs(nCity);
				vis[nCity]=0;
				curCost-=r.cost;
				curLen-=r.length;
			}
		}
	}
}

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&K,&N,&R);
	Road r;
	int s;
	for(int i=0;i<R;i++){
		scanf("%d%d%d%d",&s,&r.end,&r.length,&r.cost);
		G[s].push_back(r);
	}
	//数组初始化
	for(int i=0;i<105;i++)
		for(int j=0;j<10010;j++)
			minL[i][j]=BIG;

	vis[1]=1;
	dfs(1);//从第一个城市开始遍历
	printf("%d\n", minLength < BIG ? minLength : -1 );
	return 0;
}