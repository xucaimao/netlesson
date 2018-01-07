/*
《算法基础与在线实践》练习题5-5 矩形分割 POJ4136
write by xucaimao,2017-12-14 23:30开始编程，AC 
1.小矩形只有一个而且宽为1时，答案是R而不是小矩形的右边x坐标
2.面积要用long long
*/
#include<cstdio>
#include <algorithm>

struct Rect{
	int left,top,width,height;
	bool operator <(const Rect & b)const{
		return left<b.left;
	}
};

const int maxn=10000+10;
Rect data[maxn];
int R,N;
long long int areaSum=0;

long long int areadiff(int n){
	//计算小矩形在直线x=n左边的面积之和,与右边面积的差值
	long long int areaLeftSum=0;
	for(int i=0;i<N;i++){
		if(data[i].left+data[i].width <= n)//全部在直线左边
			areaLeftSum+=data[i].width*data[i].height;
		else if(data[i].left+data[i].width > n && data[i].left<n)//被直线分割
			areaLeftSum+=(n-data[i].left)*data[i].height;
	}
	return 2*areaLeftSum-areaSum;
}

int search(int l,int r){
	//在[l...r)范围内查找,最后一个使得ad=0的元素,如果存在,则返回它出现的最后一个位置的后一个位置
	if(N==1 && data[0].width==1)return R;
	while(l<r){//终止条件是l>=r
		int mid=l+(r-l)/2;
		long long int ad=areadiff(mid);
		printf("l=%d mid=%d r= %d ",l,mid,r);
		printf("areadiff = %lld \n",ad);
		if(ad<=0){
			l=mid+1;//加大
		}
		else//减小
			r=mid;
			
	}
	long long int ad1=areadiff(r-1);
	long long int ad=areadiff(l);
	printf("End: l=%d r= %d ",l,r);
	printf("areadiff(r-1) = %lld areadiff(l) = %lld \n",ad1,ad);
	while(r<R && areadiff(r+1)==areadiff(r)) r++;
	if(areadiff(r-1)==0)
		return r-1;
	else return r;
}

int main(){
	freopen("e0505.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		areaSum=0;

		scanf("%d",&R);
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%d%d%d%d",&data[i].left,&data[i].top,&data[i].width,&data[i].height);
			areaSum+=data[i].width*data[i].height;
		}
		std::sort(data,data+N);
		//printf("Total area is: %lld \n",areaSum);
		int n=search(0,R);
		printf("%d\n",n );
	}
	
	return 0;
}