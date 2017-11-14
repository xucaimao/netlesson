/*第1周编程题 write by xucaimao at 20171107-12:00
题目说起来很简单，你会读到两个字符串，每个字符串占据一行，每个字符串的长度均小于10000字符，而且第一个字符串的长度小于第二个字符串的。
你的程序要找出第一个字符串在第二个字符串中出现的位置，输出这些位置，如果找不到，则输出-1。
注意，第一个字符的位置是0。
注意，第一个字符串在第二个字符串中的位置可能不止一处。
注意，字符串中可能含有空格。
注意，两个字符串的长度一定大于0。
*/

#include<stdio.h>
#include<string.h>
#define maxn 10010
char src[maxn];
char tag[maxn];

int main(){
	int ls=0,lt=0;
	int i=0,j=0,cnt=0;
	int pos;
	int ok=1;
	//input string and cacu the length
	while( ( src[ls]=getchar() ) !='\n' ){
		ls++;
	}
	src[ls]='\0';
	
	while( ( tag[lt]=getchar() ) !='\n' ){
		lt++;
	}
	tag[lt]='\0';

	while(1){
		while(src[i]!=tag[j] && j<lt){ //find first same char
			j++;
		}
		if(j>=lt) {ok=0;break;}
		pos=j;//record
		while(src[i]==tag[j] && i<ls && j<lt){
			i++;j++;
		}

		if(i>=ls){//find same string in tag
			printf("%d ",pos);
			cnt++;
			if(j<lt){j=pos+1;i=0;continue;} //not to end of tag
			else break;//to end of two string at the same time
		}
		else if(j>=lt){ok=0;break;}//to end of tag,but src not to end 

		else if(src[i]!=tag[j]){j=pos+1;i=0;continue;}
	}
	if(ok==0 && cnt==0) printf("-1\n");
	else printf("\n");
	return 0;
}