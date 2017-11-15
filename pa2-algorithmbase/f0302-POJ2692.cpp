/*
程序设计与算法（二）算法基础 第一周 枚举 例题3 称硬币 POJ2692
write by xucaimao,20171114-22:00,AC
*/
#include<cstdio>
#include<cstring>

char left[3][7];
char right[3][7];
char stat[3][7];

bool solve(char c,bool light){
	char *r,*l;
	for(int i=0;i<3;i++){
		if(light){
			r=right[i];
			l=left[i];
		}
		else{
			r=left[i];
			l=right[i];
		}
		switch(stat[i][0]){
			case 'u':
				if(strchr(r,c)==NULL)return false;
				break;
			case 'd':
				if(strchr(l,c)==NULL)return false;
				break;
			case 'e':
				if(strchr(r,c) || strchr(l,c))return false;
				break;
		}
	}
	return true;
}

int main() {
	freopen("POJ1013.in","r",stdin);
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
		for(int i=0;i<3;i++){
			scanf("%s%s%s",left[i],right[i],stat[i]);
		}
		
		for(char c='A';c<='L';c++){//开始枚举
			bool light=true;
			if(solve(c,light)){
				printf("%c is the counterfeit coin and it is light.\n",c);
				break;
			}
			light=false;
			if(solve(c,light)){
				printf("%c is the counterfeit coin and it is heavy.\n",c);
				break;
			}
		}
			
	}
	return 0;	
}
