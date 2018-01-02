/*
《算法基础与在线实践》练习题5-5 矩形分割 POJ4136
write by xucaimao,2017-12-14 23:30开始编程，AC 2017-12-14 23:42:13
1.小矩形只有一个而且宽为1时，答案是R而不是小矩形的右边x坐标
2.面积要用long long
*/
#include<cstdio>
#include <algorithm>

struct Rect{
	int left,top,width,height;
	friend bool operator <(const Rect & a,const Rect & b){
		return a.left<b.left;
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
		else//在直线右边
			break;
	}
	return 2*areaLeftSum-areaSum;
}

int search(int l,int r){
	//在[l...r)范围内查找
	if(N==1 && data[0].width==1)return R;
	//下面过程是求lower_bound的标准过程
	while(l<r){//终止条件是l>=r
		int mid=0;
		mid=l+(r-l)/2;
		// printf("l=%d mid=%d r= %d ",l,mid,r);
		// printf("areadiff = %lld \n",ad);
		if(areadiff(mid)>=0){
			r=mid;//减小
		}
		else
			l=mid+1;//加大
	}
	// long long int ad1=areadiff(l-1);
	// long long int ad=areadiff(l);
	// printf("End: l=%d r= %d ",l,r);
	// printf("areadiff(l-1) = %lld areadiff(l) = %lld \n",ad1,ad);
	while(l+1<=R && areadiff(l)==areadiff(l+1)) l++;
	return l;
}

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&R);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",&data[i].left,&data[i].top,&data[i].width,&data[i].height);
		areaSum+=data[i].width*data[i].height;
	}
	std::sort(data,data+N);
	
	//printf("Total area is: %lld \n",areaSum);
	int l=data[0].left;
	int r=data[N-1].left+data[N-1].width;
	int n=search(l,r);
	printf("%d\n",n );

	return 0;
}