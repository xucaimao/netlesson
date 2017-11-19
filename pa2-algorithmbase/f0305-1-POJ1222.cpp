/*
程序设计与算法（二）算法基础 第一周 枚举 例题5 熄灯问题 POJ1222
郭炜老师的程序，以位操作代替数组，程序简洁了许多
*/
#include<cstdio>
#include<cstring>

char in[5];
char light[5];
char result[5];

void setBit(char & c,int n,int v){
	//将c的第n位设为值v(0或1)
	if(v)
		c |= (1<<n);
	else
		c &= ~(1<<n);
}

int getBit(char c,int n){
	//取得c的第n位值
	return (c>>n)&1;
}

void flipBit(char &c,){
	//将c的第n位翻转
	//采用异或操作实现
	return c ^= (1<<n);
}

void printResult(int t,char res[]){
	printf("PUZZLE #%d\n",t);
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			printf(getBit(res[i],j));
			if(j<5)printf(" ");
		}
		printf("\n");
	}		
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<5;i++)//读入5行6列数据
			for(int j=0;j<6;j++){
				int s;
				scanf("%d",&s);
				setBit(in[i],j,s);
			}

		for(int n=0;n<64;n++){
			//枚举0行开关的64种状态,然后往后推导各行灯及开关的状态
			//本行灯的状态就是下一行开关的状态
			//下一行的开关不能再影响上一行灯的状态
			int switchs=n;
			memcpy(lights,in,sizeof(in));//初始状态复制到lights
			for(int i=0;i<5;i++){//处理全部五行
				result[i]=switchs;//保存本行的开关状态
				for(int j=0;j<6;j++){//处理本行
					//看第i行第j个开关的状态
					if(getBit(switchs,j)){
						//根据开关状态，改变本行灯的状态
						//如果第j位是开状态，
						//按下j位，同时改变行前后两位(如果存在)
						if(j>0)flipBit(lights[i],j-1);
						flipBit(lights[i],j);
						if(j<5)flipBit(lights[i],j+1);
					}
				}
				if(i<4)//处理对下一行灯(如果存在)的状态改变，此处的判断是为了防止越界
					lights[i+1]^=switchs;
				//本行开关处理后，若还有灯亮，需要下一行的开关来灭掉本行灯
				//本行灯的状态就是下一行开关的状态
				switchs=lights[i];
			}
			if(lights[4]==0){
			printResult(t,result);
			break;
			}
		}
	}
	return 0;
}
