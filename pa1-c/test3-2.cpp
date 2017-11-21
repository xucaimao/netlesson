/*
程序设计实习MOOC / 程序设计与算法（一）第三周测验(2017冬季)  
2:求一元二次方程的根 POJ2707
判断的顺序很关键
题目看的不仔细，这么简单的题居然提交六次才通过，无语...
*/

#include<cstdio>
#include<cmath>
using namespace std;//abs()需要

int main(){
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	double dt=b*b-4*a*c;
	if(abs(dt)<1e-6)//==0
		printf("x1=x2=%.5lf\n",-b/(2*a) );
	else if(dt>1e-6)//>0
		printf("x1=%.5lf;x2=%.5lf\n",(b*(-1)+sqrt(dt) )/(2*a),(b*(-1)-sqrt(dt) )/(2*a) );
	else{//<0
		//-0.0不能正确显示
		double sg=-b/(2*a);
		if( abs(sg)<1e-6) sg=0;
		double xg=sqrt(4*a*c-b*b)/(2*a);

		printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n",sg,xg,sg,xg);
	}
			
	return 0;
}

