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
	friend bool operator <(const Rect & a,const Rect & b){
		return a.left<b.left;
	}
};

const int maxn=10000+10;
Rect data[maxn];
int R,N;
long long int areaSum=0;

long long int areaLeft(int n){
	//计算小矩形在直线x=n左边的面积之和
	long long int sum=0;
	for(int i=0;i<N;i++){
		if(data[i].left+data[i].width <= n)//全部在直线左边
			sum+=data[i].width*data[i].height;
		else if(data[i].left+data[i].width > n && data[i].left<n)//被直线分割
			sum+=(n-data[i].left)*data[i].height;
		else//在直线右边
			break;
	}
	return sum;
}

int search(int l,int r){
	if(N==1 && data[0].width==1)return R;
	int ans=0;
	bool haveEqual=0;
	while(l<=r){
		int mid=0;
		mid=l+(r-l)/2;
		long long int arealeft=areaLeft(mid);//计算小矩形左半面积和
		printf("l=%d r=%d mid= %d areaLeft = %lld arearight = %lld \n",l,r,mid,arealeft,areaSum-arealeft);
		if(arealeft>areaSum-arealeft){
			if(!haveEqual)
				ans=mid;
			r=mid-1;//减小
		}
		else if(arealeft==areaSum-arealeft){
			haveEqual=1;
			ans=mid;
			l=mid+1;//往右逼近
		}
		else
			l=mid+1;//加大
	}
	return ans;
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
	int n=search(0,R-1);
	printf("%d\n",n );
	return 0;
}