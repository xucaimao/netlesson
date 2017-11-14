//中国大学MOOC-陈越、何钦铭-数据结构-起步能力自测题-5 Shuffling Machine
//write by xucaimao ;20171108-17:30
/*
移动方法很简单，主要是扑克牌数据结构的表示
采用unsigned int来表示扑克牌，后八个二进制位表示数字大小，
前八个二进制位表示花色字母的ascii码
需要用到二进制位运算
1111 1111 0000 0000=65280
0000 0000 1111 1111=255
*/
#include<cstdio>
#include<cstring>

unsigned int card[60]={0};
unsigned char color[4]={'S','H','C','D'};

void cardinit(){
	unsigned int clr,p;
	int sum=0;
	for(unsigned int j=0;j<4;j++)
		for(unsigned int i=1;i<=13;i++){
			clr=color[j];
			clr=clr<<8;
			p=clr | i;//开始用&运算，结果错误
			card[++sum]=p;	
		}
		clr=(unsigned int)'J';
		clr=clr<<8;
		p=clr | 1;
		card[53]=p;
		p=clr | 2;
		card[54]=p;
}
//打印一张牌
void printcard(unsigned int p){
	unsigned int n=p&255;//保留后八位，得到牌的大小
	unsigned int clr=(p>>8)&255;//保留前八位，得到牌的花色
	printf("%c%d",clr,n);
}

int main(){
  cardinit();
  for(int i=1;i<=54;i++){
  	printcard(card[i]);
  	printf(" ");
  	if(i%13==0) printf("\n");
  }
  return 0;
}