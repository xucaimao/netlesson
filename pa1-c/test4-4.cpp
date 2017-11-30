/*
程序设计实习MOOC / 程序设计与算法（一）第四周测验(2017冬季)  
4:求特殊自然数
write by xucaimao,2017-11-28-20:15

最小的三位7进制数是100(7)=7^2*1+7^1*0+7^0*0=49;
最大的三围9进制数是888(9)=9^2*8+9^1*8+9^0*8==728;
*/
char digit[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void i2dig(char s[],int n,int dig){
	//自然数n转dig进制，低位放在s[0]
	//最大35进制
	int i=0;
	while(n>0){
		s[i]=digit[n%dig];
		n/=dig;
		i++;
	}
}

#include<cstdio>
#include <cstring>
int main(){
	char d7[5],d9[5];
	for(int n=49;n<=728;n++){
		memset(d7,0,sizeof(d7));
		memset(d9,0,sizeof(d9));
		i2dig(d7,n,7);
		i2dig(d9,n,9);
		if(d7[0]==d9[2] && d7[2]==d9[0] && d7[1]==d9[1]){
			printf("%d\n",n);
			for(int i=2;i>=0;i--) printf("%c", d7[i]);
			printf("\n");
			for(int i=2;i>=0;i--) printf("%c", d9[i]);
			printf("\n");
		}
	}
	return 0;
}

