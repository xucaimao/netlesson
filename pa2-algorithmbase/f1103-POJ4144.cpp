/*
程序设计与算法（二）算法基础 第十一周 贪心算法 例题3 POJ4144
算法基础与在线实践》例题6.7 畜栏保留问题
write by xucaimao,2018-01-25 22:10,AC at 

*/
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct Cow{
	int start,end;//起始时间
	int id;//奶牛的编号
	bool operator < (const Cow & b)const{//按开始时间从小到大排序
		return start<b.start;
	}
};
struct Corral{
	int id;//畜栏的编号
	int end;
	bool operator < (const Corral & b)const{
		//按结束时间从大到小排序
		return end>b.end;
	}
	Corral(int idd,int et):id(idd),end(et){}//构造函数
};
Cow cow[50010];
int cowCorral[50010];//每头奶牛所使用的畜栏的编号
priority_queue<Corral> corral;//优先队列

int main(){
	freopen("in.txt","r",stdin);
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",&cow[i].start,&cow[i].end);
		cow[i].id=i;
	}
	sort(cow,cow+N);
	
	int corralNum=0;//畜栏总数，也可以看做是畜栏的编号
	for(int i=0;i<N;i++){//依次处理每一头奶牛
		if(corral.size()>0){
			printf("corral.top().end = %d\n", corral.top().end);
			printf("corral.top().id = %d\n", corral.top().id);
		}
		printf("cow[%d].start = %d\n",i,cow[i].start );

		if(corral.size()==0 || corral.top().end>=cow[i].start){
			//没有畜栏，或者没有可用的畜栏
			printf("add new corral\n");
			corralNum++;//增加一个畜栏
			corral.push( Corral(corralNum,cow[i].end) );
			cowCorral[cow[i].id]=corralNum;//记录所用的畜栏
		}
		else{//有畜栏可以被使用
			printf("use old corral\n");
			int conum=corral.top().id;
			corral.pop();
			corral.push( Corral(conum,cow[i].end) );
			cowCorral[cow[i].id]=conum;//记录所用的畜栏
		}
	}
	printf("%d\n",corralNum);
	for(int i=0;i<N;i++){
		printf("%d\n",cowCorral[i] );
	}
	
	return 0;
}