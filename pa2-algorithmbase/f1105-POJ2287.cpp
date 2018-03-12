/*
程序设计与算法（二）算法基础 第十一周 贪心算法 例题5 POJ2287
《算法基础与在线实践》例题6.5 Tian Ji -- The Horse Racing
write by xucaimao,2018-02-01 20:00,AC at 2018-02-01 20:27:01

*/
#include <cstdio>
#include <algorithm>
using namespace std;

int tian[1010];//田忌马的数据
int qiwang[1010];//齐王马的数据
int main(){
	freopen("in.txt","r",stdin);
	int N;
	int lt,lq,rt,rq,money;
	while(1){
		scanf("%d",&N);
		if(N==0)break;
		for(int i=0;i<N;i++)
			scanf("%d",&tian[i]);
		for(int i=0;i<N;i++)
			scanf("%d",&qiwang[i]);
		sort(tian,tian+N);
		sort(qiwang,qiwang+N);
		lt=lq=0;//指向最慢马的指针
		rt=rq=N-1;//指向最快马的指针
		money=0;
		while(lt<=rt){
			if(tian[rt]>qiwang[rq]){//田忌最快的马比齐王最快的马快
				//用田忌最快的马与齐王最快的马去比,肯定赢
				money+=200;
				rt--;
				rq--;
			}
			else if(tian[rt]<qiwang[rq]){//田忌最快的马比齐王最快的马慢
				//用田忌最慢的马与齐王最快的马去比,肯定输
				money-=200;
				lt++;
				rq--;
			}
			else{//田忌最快的马,与齐王最快的马,速度一样快
				if(tian[lt]>qiwang[lq]){//田忌最慢的马比齐王最慢的马快
					//用田忌最慢的马与齐王最慢的马去比,肯定赢
					money+=200;
					lt++;
					lq++;
				}
				else{//田忌最慢的马,与齐王最慢的马,速度一样
					//用田忌最慢的马与齐王最快的马去比,肯定输
					if(tian[lt]<qiwang[rq])money-=200;
					lt++;
					rq--;
				}
			}
		}
		printf("%d\n",money );
	}
	return 0;
}