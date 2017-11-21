/*
程序设计与算法（二）第二周测验 全排列 POJ2748
write by xucaimao,20171121
此处的方法就是采用回溯法，只对不含重复元素的数据正确
程序简洁，运行速度更快
*/
#include<cstdio>
#include<cstring>
const int maxn=6+1;
char src[maxn];
char tar[maxn];
int vis[maxn];

void permutation(int len,char * src,char * tar,int pos){
	//生成原始字符串src的全排列，放在tar中
	//tar[0..pos)是全排列的前半部，后半部放在tar[pos..n-1)
	if(pos==len)
		printf("%s\n",tar );
	else{
		for(int ps=0;ps<len;ps++){
			//枚举src中的各个元素
			if(!vis[ps]){
				//src[ps]没有使用过
				vis[ps]=1;//设置访问标志
				tar[pos]=src[ps];
				permutation(len,src,tar,pos+1);
				vis[ps]=0;//清除访问标志
			}
		}
	}
	
}

int main(){
	scanf("%s",src);
	int len=strlen(src);
	permutation(len,src,tar,0);
	return 0;
}