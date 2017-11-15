/*
《算法基础与在线实践》例题2-2 校门外的树 POJ2808
*/
#include<cstdio>
const int maxn=10010;
int tree[maxn]={0};

int main(){
	int L,M;
	while( scanf("%d%d",&L,&M)!=EOF ){
		for(int i=0;i<=L;i++)
			tree[i]=1;
		while(M--){
			int s,e;
			scanf("%d%d",&s,&e);
			for(int i=s;i<=e;i++)
				tree[i]=0;
		}
		int sum=0;
		for(int i=0;i<=L;i++)
			if(tree[i]==1)sum++;
		printf("%d\n",sum );
	}
	return 0;
}