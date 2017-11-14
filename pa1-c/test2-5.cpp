#include<cstdio>
const double pi=3.14159;
const double v=20000;

int main(){
	int h,r;
	scanf("%d%d",&h,&r);
	double vh=pi*r*r*h;
	int sum=v/vh;
	double y=v-vh*sum;
	if(y>1e-6)sum++;
	printf("%d\n",sum);
	return 0;
}

