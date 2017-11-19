/*
程序设计与算法（二）算法基础 第一周 枚举 例题3 称硬币 POJ2692
次程序有问题，样例通过，但是提交错误
分析可能是有两组数据都是不平衡数据，不能记录全部11个真币，导致计算错误
*/

#include<cstdio>
#include<cstring>

char left[3][7];
char right[3][7];
char stat[3][7];
int coin[12];//用于储存硬币的重量

int main() {
	freopen("POJ1013.in","r",stdin);
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
		for(int i=0;i<3;i++){
			scanf("%s%s%s",left[i],right[i],stat[i]);
		}
		memset(coin,0,sizeof(coin));
		for(int i=0;i<3;i++)//记录所有真币
			if(stat[i][0]=='e'){
				int len=strlen(left[i]);
				for(int j=0;j<len;j++){
					coin[left[i][j]-'A']=1;
					coin[right[i][j]-'A']=1;
				}
			}

		char result;
		for(int i=0;i<12;i++)//找到假币
			if(coin[i]==0){result='A'+i;break;}

		for(int i=0;i<3;i++){
			if(stat[i][0]=='u'){
				int len=strlen(left[i]);
				for(int j=0;j<len;j++){
					if(left[i][j]==result){
						printf("%c is the counterfeit coin and it is heavy.\n",result);
						break;
					}
					if(right[i][j]==result){
						printf("%c is the counterfeit coin and it is light.\n",result);
						break;
					}
				}
			}
			else if(stat[i][0]=='d'){
				int len=strlen(left[i]);
				for(int j=0;j<len;j++){
					if(left[i][j]==result){
						printf("%c is the counterfeit coin and it is light.\n",result);
						break;
					}
					if(right[i][j]==result){
						printf("%c is the counterfeit coin and it is heavy.\n",result);
						break;
					}
				}
			}
		}
			
	}
	return 0;
	
}
