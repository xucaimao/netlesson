/*
程序设计与算法（二）第四周测验 3:月度开销
write by xucaimao,2017-12-14
*/
#include<cstdio>

const int maxn=100000+10;
int data[maxn];
int n,m;

bool check(int pay){
	//根据月度最小开销，计算月数
	int fajoPay=0;//统计一个fajo月的开销
	int fajoNum=1;//统计fajo月的数量。
	//初始值为1是因为月份累加的条件是>pay,最后条件不能满足>pay的月份也需要加上
	for(int i=0;i<n;i++){
		//每次都把尽量多的天合并到一个fajo月中
		//这样统计出来的fajo月的数量，只要<=m，就可以满足条件
		//比m小，意味着可以把其中的某一个fajo月再进行分拆
		if(fajoPay+data[i] > pay){
			fajoPay=data[i];
			fajoNum++;
		}
		else
			fajoPay+=data[i];
	}
	//printf("fajoNum = %d\n",fajoNum );
	if(fajoNum<=m)return 1;
	else return 0;
}

void solve(int l,int r){
	int minpay=0;
	while(l<=r){
		int mid=(r-l)/2+l;
		if(check(mid)){//不断减小minpay
			minpay=mid;
			//printf("minpay = %d\n",minpay );
			r=mid-1;
		}
		else
			l=mid+1;
	}
	printf("%d\n",minpay );
}

int main(){
	freopen("cy0403.in","r",stdin);
	int tot=0,maxn=0;//总和及最大值
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&data[i]);
		tot+=data[i];
		if(data[i]>maxn)
			maxn=data[i];
	}
	solve(maxn,tot);
	return 0;
}