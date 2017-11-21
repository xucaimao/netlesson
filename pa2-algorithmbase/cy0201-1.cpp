/*
程序设计与算法（二）第二周测验 全排列 POJ2748
write by xucaimao,20171121
书本上的方法,只对不含重复元素的数据正确
*/
#include<cstdio>
#include<cstring>
const int maxn=6+1;
char src[maxn];
char tar[maxn];

void permutation(int len,char * src,char * tar,int pos){
	//生成原始字符串src的全排列，放在tar中
	//tar[0..pos)是全排列的前半部，后半部放在tar[pos..n-1)
	if(pos==len){
		printf("%s\n",tar );
	}
	else{
		for(int ps=0;ps<len;ps++){
			//枚举src中的各个元素
			int ok=1;
			for(int pt=0;pt<pos;pt++)//src[ps]是否在tar[0..p)中出现过
				if(src[ps]==tar[pt]){ok=0;break;}
			if(ok){
				//src[ps]没有使用过
				tar[pos]=src[ps];
				permutation(len,src,tar,pos+1);
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