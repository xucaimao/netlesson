#include<stdio.h>
#include<stdlib.h>

int main(){
	void *p;
	int cnt=0;
	while( (p=malloc(100*1024*1024)) ){
		cnt++;
	}
	printf("malloc %d00MB area!\n",cnt);
	return 0;
}