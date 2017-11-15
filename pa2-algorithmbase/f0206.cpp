/*
《算法基础与在线实践》例题2-6 显示器 POJ2745
write by xucaimao,20171115,23:00测试通过
程序测试要考虑极端情况
*/
#include<cstdio>

unsigned short digit[]={10794,2080,8866,10402,2216,10378,10890,2082,10922,10410};//0~9的字模
char digitarr[24][13];//单个数字字符的显示矩阵
//开始是定义digitarr[24][12]，导致s=10时数组越界，程序出错
char numarr[24][110];//整个数字的显示矩阵

int getBit(unsigned short v,int n){
	//取字模的第n位
	return (v>>n)&1;
}

void digitToMatrix(char txtdisp[24][13],int n,int s){
	//数字n,s控制字的大小,1<=s<=10,转化为二维字符矩阵
	for(int i=0;i<23;i++)
			for(int j=0;j<13;j++)
				txtdisp[i][j]=' ';

	unsigned short v=digit[n];
	int r;//行号
	//第一行
	r=0;
	if(getBit(v,1))
		for(int c=1;c<1+s;c++)
			txtdisp[r][c]='-';
	//第1～s行
	r++;
	for(int i=0;i<s;i++){
		int c=0;
		if(getBit(v,3))txtdisp[r][c]='|';
		c=c+s+1;
		if(getBit(v,5))txtdisp[r][c]='|';
		r++;
	}
	//第s+1行
	if(getBit(v,7))
		for(int c=1;c<1+s;c++)
			txtdisp[r][c]='-';
	//s+2 
	r++;
	for(int i=0;i<s;i++){
		int c=0;
		if(getBit(v,9))txtdisp[r][c]='|';
		c=c+s+1;
		if(getBit(v,11))txtdisp[r][c]='|';
		r++;
	}
	//最后一行
	//第s+1行
	if(getBit(v,13))
		for(int c=1;c<1+s;c++)
			txtdisp[r][c]='-';
}

void mymerge(char source[24][13],char tar[24][110] ,int ord,int s){
	//把第ord(>=1)个数字的显示矩阵合并到总的显示矩阵里面
	int cs=(ord-1)*(s+2+1);
	int ce=cs+(s+2);
	int maxr=2*s+3;
	for(int r=0;r<maxr;r++)
		for(int c=cs;c<=ce;c++)
			tar[r][c]=source[r][c-cs];
}

void printMatrix(char txtdisp[24][110],int n,int s){
	//打印有n位，字符大小为s的显示矩阵
	int maxr=2*s+3;
	int maxc=(s+2+1)*n-1;

	for(int r=0;r<maxr;r++){
		for(int c=0;c<maxc;c++)
			printf("%c",txtdisp[r][c]);
		printf("\n");
	}
}

int main(){
	int s;
	char n[10];//储存整数的各个位，从高位到低位
	freopen("f0206.in","r",stdin);
	while(1){
		for(int i=0;i<24;i++)
			for(int j=0;j<110;j++)
				numarr[i][j]=' ';

		scanf("%d",&s);
		scanf("%s",n);
		if(s==0)break;
		int i=0;//数字位数
		while(n[i]!='\0'){//从最高位为开始，按位转换
			digitToMatrix(digitarr,n[i]-'0',s);
			mymerge(digitarr,numarr,i+1,s);
			i++;
		}
		
		printMatrix(numarr,i,s);
		printf("\n");	
	}
	return 0;
}