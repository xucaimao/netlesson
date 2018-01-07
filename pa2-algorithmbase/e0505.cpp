/*
《算法基础与在线实践》练习题5-5 矩形分割 POJ4136
write by xucaimao,2017-12-14 23:30开始编程，AC 
1.小矩形只有一个而且宽为1时，答案是R而不是小矩形的右边x坐标
2.面积要用long long
*/
#include<cstdio>
#include <algorithm>
using namespace std;

struct Rect{
	int left,top,width,height;
};

const int maxn=10000+10;
Rect data[maxn];
long long int R,N;
long long int MAXx=-1;//小正方形最右边
long long int areaAll=0;

long long int areadiff(int n){
	//计算小矩形在直线x=n左边的面积之和,与右边面积的差值
	long long int areaLeft=0;
	for(int i=0;i<N;i++){
		if(data[i].left+data[i].width <= n)//全部在直线左边
			areaLeft+=data[i].width*data[i].height;
		else if(data[i].left+data[i].width > n && data[i].left<n)//被直线分割
			areaLeft+=(n-data[i].left)*data[i].height;
	}
	return areaLeft-(areaAll-areaLeft);
}

long long int search(long long int l,long long int r){
	//在[l...r]范围内查找,最后一个使得ad=0的元素,如果存在,则返回它出现的最后一个位置的后一个位置
	while(l<r-1){
		long long int mid=l+(r-l)/2;
		long long int dif=areadiff(mid);
		if(dif<=0){
			l=mid;//加大
		}
		else//减小
			r=mid;		
	}
	long long int difL=areadiff(l);
	long long int difR=areadiff(r);
	long long int ans=0;
	if(difL<difR){
		if(difL>=0)ans=l;
		else ans=r;
	}
	else if(difL>difR){
		if(difR>=0)ans=r;
		else ans=l;
	}
	else ans=r;
	if(ans==MAXx)ans=R;
	return ans;
}

int main(){
	freopen("in.txt","r",stdin);
	int T;
	scanf("%lld",&R);
	scanf("%lld",&N);
	for(long long int i=0;i<N;i++){
		scanf("%d%d%d%d",&data[i].left,&data[i].top,&data[i].width,&data[i].height);
		areaAll+=data[i].width*data[i].height;
		if(data[i].left+data[i].width > MAXx)
			MAXx=data[i].left+data[i].width;
	}
	printf("%lld\n",search(0,R) );
	return 0;
}