/*
程序设计实习MOOC / 程序设计与算法（一）第十周测验(2017冬季)  
2:分数线划定
write by xucaimao,2018-01-10 13:00,AC 2018-01-10 13:16:57
*/

#include <cstdio>
#include <algorithm>
using namespace std;
struct Player{
	int number;
	int score;
	bool operator <(const Player &b)const{
		if(score==b.score)
			return number<b.number;
		else
			return score > b.score;
	}
};
Player player[5050];

int main(){
	freopen("in.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){//从1开始
		scanf("%d%d",&player[i].number,&player[i].score);
	}
	sort(player+1,player+n+1);
	int playerNum=int(m*1.5);
	int realScore=player[playerNum].score;
	int realM=0;
	for(int i=1;i<=n;i++)
		if(player[i].score>=realScore)realM++;
	printf("%d %d\n",realScore,realM );
	for(int i=1;i<=realM;i++)
		printf("%d %d\n",player[i].number,player[i].score );
	return 0;	
}