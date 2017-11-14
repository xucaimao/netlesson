#include<cstdio>
#include<cstring>

char left[3][7];
char right[3][7];
char stat[3][7];
int coin[12];//用于储存硬币的重量

int main() {
	int case;
	scanf("%d",case);
	getchar();
	while(case--){
		for(int i=0;i<3;i++){
			scanf("%s%s%s",&left[i],&right[i],&stat[i]);
		}
		memset(coin,0,sizeof(coin));
		for(int i=0;i<3;i++)
			if(stat[i][0]=='e'){
				int len=strlen(left[i]);
				for(int j=0;j<len;j++){
					coin[left[i][j]-'A']=10;
					coin[right[i][j]-'A']=10;
				}
			}

		char result;
		for(int i=0;i<12;i++)
			if(coin[i]==0){result='A'+i;break;}

		for(int i=0;i<3;i++)
			if(stat[i][0]=='u'){
				int len=strlen(left[i]);
				for(int j=0;j<len;j++){
					if(left[j]==result){
						printf("%c is the counterfeit coin and it is heavy.");
						break;
					}
					if(right[j]==result){
						printf("%c is the counterfeit coin and it is light.");
						break;
					}
				}
			}
	}
	return 0;
	
}
