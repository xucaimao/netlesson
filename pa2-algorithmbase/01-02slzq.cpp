#include<cstdio>
const int maxn=21252;

int main() {
	int p,e,i,d;
	int case=0;
	while(1){
		scanf("%d%d%d%d",&p,&e,&i,&d);
		if(p==-1)break;
		case++;
		int k=d+1;
		for(;(k-p)%23 && k<=maxn;k++);
		for(;(k-e)%28 && k<=maxn;k+=23);
		for(;(k-i)%33 && k<=maxn;K+=23*28);
		printf("");
	}
	
}
