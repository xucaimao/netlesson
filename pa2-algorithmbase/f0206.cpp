/*
《算法基础与在线实践》例题2-6 显示器 POJ2745

*/
#include<cstdio>

unsigned short digit[]={10794,2080,8866,10402,2216,10378,10890,2082,10922,10410};//0~9的字模
int num[10];//储存整数的各个位，从低位到高位
int dnum;//一个整数有几位数字
char digitarr[23][12];//一个字的显示矩阵
char numarr[23][110];//整个数字的显示矩阵

int getBit(unsigned short v,int n){
	//取字模的第n位
	return (v>>n)&1;
}

void digitToDisp(char txtdisp[23][12],int n,int s){
	//数字n,s控制字的大小,1<=s<=10,转化为二位字符数组
	for(int i=0;i<23;i++)
			for(int j=0;j<12;j++)
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

void mymerge(char source[23][12],char tar[23][110] ,int ord,int s){
	//把第ord(>=1)个数字的显示矩阵合并到总的显示矩阵里面
	int cs=(ord-1)*(s+2+1);
	int ce=cs+(s+2);
	int maxr=2*s+3;
	for(int r=0;r<maxr;r++)
		for(int c=cs;c<=ce;c++)
			tar[r][c]=source[r][c-cs];
}

void printDigit(char txtdisp[23][110],int n,int s){
	//打印有n位，字符大小为s的显示矩阵
	int maxr=2*s+3;
	int maxc=(s+2+1)*n-1;
	for(int r=0;r<maxr;r++){
		for(int c=0;c<maxc;c++)
			printf("%c",txtdisp[r][c]);
		printf("\n");
	}
}

int getnum(int n){
	//取得一个整数的位数，并把各位存放在数组num中
	int d=0;
	while(n>0){
		num[d]=n%10;
		n/=10;
		d++;
	}
	return d;
}

int main(){
	int s,n;
	int T=0;
	freopen("f0206.in","r",stdin);
	while(1){
		for(int i=0;i<23;i++)
			for(int j=0;j<110;j++)
				numarr[i][j]=' ';

		scanf("%d%d",&s,&n);
		if(s+n ==0)break;
		T++;
		int dn=getnum(n);
		int ord=1;//数字个数
		for(int i=dn-1;i>=0;i--){
			digitToDisp(digitarr,num[i],s);
			mymerge(digitarr,numarr,ord,s);
			ord++;
		}
		if(T>1)printf("\n");
		printDigit(numarr,dn,s);	
	}
	return 0;
}