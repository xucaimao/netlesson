#include<cstdio>

int main() {
	int n;
	scanf("%d",&n);
	for(int a=2;a<=n;a++)
		for(int b=1;b<=a-3;b++)
			for(int c=b+1;c<=a-2;c++)
				for(int d=c+1;d<=a-1;d++)
					if(a*a*a==b*b*b+c*c*c+d*d*d)
						printf("Cube=%d,Triple(%d,%d,%d)\n",a,b,c,d);
	return 0;
}
