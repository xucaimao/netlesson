/*
程序设计实习MOOC / 程序设计与算法（一）第七周测验(2017冬季)  
4:最长最短单词
由于空格、逗号都是单词间隔，标准输入不能识别逗号，需要自编程序
采用滚动指针,行尾的处理是容易疏忽的地方,导致WA一次
write by xucaimao,2017-12-18 17:10,AC 
*/

#include<cstdio>
const int maxn=200*100+10;
char str[maxn];

int main(){
	freopen("in.txt","r",stdin);
	char ch;
	int lenMax=0,lenMin=200;//最长与最短的初始值
	int pMax=0,pMin=0;//指向最长与最短单词的首字母在整个句子中的位置
	int phead=-1,len=0;//指向当前单词的首字母，以及当前字符在当前单词中的位置
	int n=0;//当前字母在整个句子中的位置

	while( 1 ){
		//读入的时候同时统计最长与最短单词
		ch=getchar();
		str[n]=ch;
		if(ch==' ' || ch=='\n' || ch==','){
			//遇到空格
			if(phead>=0){
				//一个单词结束
				if(len>lenMax){pMax=phead;lenMax=len;}
				if(len<lenMin){pMin=phead;lenMin=len;}
				phead=-1;
				len=0;
			}
			//影藏有遇到连续空格，什么都不做
		}
		else{
			//遇到字母
			if(phead==-1){
				//遇到一个单词的首字母
				phead=n;
				len++;
			}
			else len++;
		}
		n++;
		if(ch=='\n')break;	
	}
	str[n]='\0';

	for(int i=pMax;i<pMax+lenMax;i++)
		printf("%c",str[i] );
	printf("\n");
	for(int i=pMin;i<pMin+lenMin;i++)
		printf("%c",str[i] );
	printf("\n");
	return 0;
}