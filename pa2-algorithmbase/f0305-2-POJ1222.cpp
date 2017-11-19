/*
程序设计与算法（二）算法基础 第一周 枚举 例题2 熄灯问题 POJ1222
write by xucaimao,20171119,14:20测试通过
内存:200kB  时间:1ms
采用数组形式，自己写的程序，加深理解

*/
#include <cstdio>
#include <cstring>

int light[7][8];//数组开大，可以不用考虑越界的处理，简化程序
int tmp[7][8];//在零时数组上进行数据操作
int cmd[7][8];//储存命令

int main(){
	freopen("f0305.in","r",stdin);
	for(int r=1;r<=5;r++)
		for(int c=1;c<=6;c++)
			scanf("%d",&light[r][c]);
		
	for(int command=0;command<(1<<6);command++){//二进制法，枚举第一行按钮的各个可能性
		memcpy(tmp,light,sizeof(light));
		memset(cmd,0,sizeof(cmd));
		int t=command;
		for(int i=1;i<=6;i++){//按钮从数字转二进制
			cmd[1][i]=t%2;
			t/=2;
		}
		//数组开大，且有效下标从1开始，本循环内就不要进行越界检查
		for(int r=1;r<=5;r++){//开始处理所有五行，开始只处理了前4行，折腾了许久
			for(int c=1;c<=6;c++)
				if(cmd[r][c]){
					tmp[r][c-1]^=1;//左
					tmp[r][c]^=1;//本身
					tmp[r][c+1]^=1;//右
					tmp[r-1][c]^=1;//上，此行操作不要，也不影响结果
					//加上后，对于正确答案，程序运行结束后，tmp数组全零，与真实状况一致
					tmp[r+1][c]^=1;//下
				}
			//本行处理结束，如果此时本行还有灯没有灭，则需要通过下一行的开关来进行操作
			//本行还有灯亮，下一行相应位置应该就按开关，才能保证本行灯全灭
			//所以，本行灯的状态就是下行开关的状态
			for(int c=1;c<=6;c++)
				cmd[r+1][c]=tmp[r][c];
		}

		//如果此时第五行灯全灭，则说明满足条件
		int ok=1;
		for(int c=1;c<=6;c++)
			if(tmp[5][c]){ok=0;break;}
		if(ok){
			for(int i=1;i<=5;i++){
				for(int j=1;j<=6;j++)
					printf("%d ",cmd[i][j] );
				printf("\n");
			}
			break;
		}
	}
	return 0;
}
