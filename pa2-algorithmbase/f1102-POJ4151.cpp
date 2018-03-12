/*
程序设计与算法（二）算法基础 第十一周 贪心算法 例题2 POJ4151 电影节
write by xucaimao,2018-01-25 21:30,AC at 2018-01-25 22:07:20

*/
#include <cstdio>
#include <algorithm>
using namespace std;

struct Film{
	int start,end;//起始时间
	bool operator < (const Film & b)const{//按结束时间从小到大排序
		return end<b.end;
	}
};
Film film[110];

int main(){
	freopen("in.txt","r",stdin);
	int N;
	while(1){
		scanf("%d",&N);
		if(N==0)break;
		for(int i=0;i<N;i++){
			scanf("%d%d",&film[i].start,&film[i].end);
		}
		sort(film,film+N);
		
		int num=1;//当前所看的电影的总数
		int endtime=film[0].end;//先看结束时间最早的那一场电影,并记下结束时间
		for(int i=1;i<N;i++){
			if(film[i].start>=endtime){//选择看第i场电影
				endtime=film[i].end;//记下新的结束时间
				num++;
			}
		}
		printf("%d\n",num);
	}
	
	return 0;
}