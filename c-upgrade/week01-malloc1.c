#include<stdio.h>
#include<stdlib.h>

int main(){
	int *p1,*p2,*p3;
	int cnt=0;
	p1=malloc(4*sizeof(int));
	p2=malloc(4*sizeof(int));
	p3=malloc(0);
	printf("p1 point at %p!\n",p1);
	printf("p2 point at %p!\n",p2);
	printf("p3 point at %p!\n",p3);
	printf("p1+1 point at %p!\n",p1+1);
	printf("p3+1 point at %p!\n",p3+1);
	return 0;
}
