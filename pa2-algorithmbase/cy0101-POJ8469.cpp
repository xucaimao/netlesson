/*
程序设计与算法（二）第一周测验 特殊密码锁 POJ8469
write by xucaimao,20171115,23:00测试通过
此程序正确，但是运行超时
*/
#include<cstdio>
#include<cstring>

int getBit(unsigned int v,int n){
	//取无符号数v的第n位
	return (v>>n)&1;
}

void setBit(unsigned int & s,int n,int v){
	//将无符号数s的第n位设置为v(0 or 1)
	if(v)
		s |= (1<<n);
	else
		s &= ~(1<<n);
}

void flipBit(unsigned int & s,int n){
	//将无符号数s的第n位取反,采用异或操作
	s ^= (1<<n);
}

unsigned int str2int(char s[],int len){
	//把01组成的长度为len的字符串s，映射到二进制位
	unsigned int t=0;
	for(int i=len-1,j=0;i>=0;i--,j++)
		setBit(t,j,s[i]-'0');
	return t;
}

int main(){
	char sr[32],tr[32];//储存密码锁的初始与目标状态
	freopen("in-2.txt","r",stdin);
	scanf("%s",sr);
	scanf("%s",tr);
	int len=strlen(sr);
	unsigned int source=str2int(sr,len);//密码锁的初始与目标状态映射到二进制位
	unsigned int target=str2int(tr,len);
	unsigned int maxn=(1<<len)-1;//
	for(unsigned int key=0;key<=maxn;key++){//开始枚举操作的所有状态
		unsigned int temp=source;//在临时值上进行操作
		for(int i=0;i<len;i++){//根据每一i位开关的状态，对密码锁进行操作
			if(getBit(key,i)){
				flipBit(temp,i);
				if(i>0)flipBit(temp,i-1);
				if(i<len-1)flipBit(temp,i+1);
			}
		}
		if(temp==target){
			int sum=0;
			//printf("The key is:\n");
			for(int i=0;i<len;i++){
				//printf("%d",getBit(key,i) );
				if(getBit(key,i))sum++;
			}
			printf("%d\n",sum );
			return 0;
		}
	}
	printf("impossible\n");
	return 0;
}