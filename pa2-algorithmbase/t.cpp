#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long f(long long x);
int a[10010][5];long long n;
int main()
{
	long long l=0,r,R;
	cin>>R>>n;r=R;
	cin>>a[1][1]>>a[1][2]>>a[1][3]>>a[1][4];
	int Max=a[1][1]+a[1][3],Min=a[1][1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=4;j++)scanf("%iid",&a[i][j]);
		Max=max(a[i][1]+a[i][3],Max);
		Min=min(Min,a[i][1]);
	}//读入

	r=Max;l=Min;
	long long ans;
	long long mid=(l+r)/2;
	while(1){
		if(l==r){ans=l;break;}
		mid=(l+r)/2;
		if(f(mid)>=0)
			r=mid;
		else l=mid+1;
	}//二分
	while(f(ans)==f(ans+1)&&ans<R)ans++;//使矩阵左边最大
	cout<<ans;
	return 0;
}

long long f(long long x)
//返回左右两边面积的差
{
	long long s=0;
	for(int i=1;i<=n;i++){
		if(a[i][1]+a[i][3]<=x)s+=a[i][3]*a[i][4];//在直线左边
		else if(a[i][1]>=x)s-=a[i][3]*a[i][4];//在直线右边
		else s+=a[i][4]*(2*x-2*a[i][1]-a[i][3]);//被直线分割
	}
	return s;
}