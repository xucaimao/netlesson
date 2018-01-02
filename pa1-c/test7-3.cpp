/*
程序设计实习MOOC / 程序设计与算法（一）第七周测验(2017冬季)  
3:石头剪子布
write by xucaimao,2017-12-18 16:50,AC 
*/

#include<cstdio>

int main(){
	freopen("in.txt","r",stdin);
	char ch,p1[10],p2[10];
	char ansstr[3][10]={"Tie","Player1","Player2"};
	int n=0,ans=0;
	scanf("%d",&n);
	getchar();

	while(n--){
		//读入的时候同时统计每个字母出现的次数
		scanf("%s",p1);
		scanf("%s",p2);
		printf("%s VS %s\n",p1,p2 );
		switch(p1[0]){
			case 'R':
				if(p2[0]=='R')ans=0;
				else if(p2[0]=='S')ans=1;
				else ans=2;
				break;
			case 'S':
				if(p2[0]=='S')ans=0;
				else if(p2[0]=='P')ans=1;
				else ans=2;
				break;
			case 'P':
				if(p2[0]=='P')ans=0;
				else if(p2[0]=='R')ans=1;
				else ans=2;
				break;
		}
		printf("%s\n",ansstr[ans] );
	}
	return 0;
}