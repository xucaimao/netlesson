/*
程序设计与算法（二）算法基础 第十一周 贪心算法 例题1 POJ4110
《算法基础与在线实践》例题6.2 圣诞老人的礼物-Santa Clau’s Gifts
write by xucaimao,2018-01-25 21:00,AC at 2018-01-25 21:19:21
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const double eps=1e-6;

struct Candy{
	int value,weight;
	bool operator < (const Candy & b)const{//从大到小排序
		double r1=value*1.0/weight;
		double r2=b.value*1.0/b.weight;
		return r1-r2>eps;
	}
};

Candy candy[110];


int main(){
	freopen("in.txt","r",stdin);
	int N,W;
	scanf("%d%d",&N,&W);
	for(int i=0;i<N;i++){
		scanf("%d%d",&candy[i].value,&candy[i].weight);
	}
	sort(candy,candy+N);
	
	double curV=0;
	int curW=0;//当前价值与当前重量
	for(int i=0;i<N && curW<W;i++){
		if( curW+candy[i].weight <= W ){
			curW+=candy[i].weight;
			curV+=candy[i].value;
		}
		else{
			int addW = W-curW;//本次只能取的重量
			curW+=addW;
			curV += addW*1.0/candy[i].weight*candy[i].value;
		}
	}
	printf("%.1lf\n",curV );
	return 0;
}