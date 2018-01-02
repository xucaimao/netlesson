/*
关于二分查找的floor与ceil,
write by xucaimao,2017-12-17 14:30开始编程，
*/
#include<cstdio>
#include<ctime>
#include<iostream>
using namespace std;

int* generateRandomArray(int len,int l,int r){
	//生成一个长度为len的整型数组，元素在[l...r)内随机排列 
	int *arr=new int[len];
	for(int i=0;i<len;i++)
		arr[i]=rand()%(r-l+1)+l;
	return arr;
}

int* copyArray(int arr[],int len){
	//拷贝数组arr
	int *arr1=new int[len];
	for(int i=0;i<len;i++)
		arr1[i]=arr[i];
	return arr1; 
}

void printArray(int arr[],int len){
	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
} 

int floor_xcm(int arr[],int len,int target){
	//在长度为len的数组arr中，查找元素target。若target<arr[0]返回-1;
	//找到，返回第一个位置，找不到，返回比target小的最后一个元素的位置
	if(target<arr[0])return -1;
	else if(target>arr[len-1]) return len-1;
	//在arr[l...r]前闭后闭的区间,确保l<=target<=r
	int l=0,r=len-1;
	while(l<r){//终止条件是l>=r
		int mid=l+(r-l)/2;
		printf("l=%d mid=%d r=%d arr[mid]=%d\n",l,mid,r,arr[mid] );
		if(target<=arr[mid])//等于的时候也在左边查找
			r=mid;
		else//在右边查找
			l=mid+1;
	}
	printf("Floor end: l=%d r=%d arr[%d]=%d\n",l,r,l,arr[l] );
	//此时r=l指向第一个大于等于target的元素
	if(arr[l]==target)return l;
	else return l-1;
}

template<typename T>
int floor_lrj(T arr[],int n,T target){
    int l=0,r=n;
    int mid;
    while(l<r){
        mid=l+(r-l)/2;
        printf("l=%d mid=%d r=%d arr[mid]=%d\n",l,mid,r,arr[mid] );
        if(arr[mid]>=target)
            //小于在左边找,等于也在左边找
            r=mid;
        else
            l=mid+1;
    }
    printf("Floor end: l=%d r=%d arr[%d]=%d\n",l,r,l,arr[l] );
    return l;
}

template<typename T>
int floor_lyb(T arr[], int n, T target){

    // 寻找比target小的最大索引
    //再arr(l...r]内查找
    int l = -1, r = n-1;
    while( l < r ){
        // 使用向上取整避免死循环
        int mid = l + (r-l+1)/2;
        printf("l=%d mid=%d r=%d arr[mid]=%d\n",l,mid,r,arr[mid] );
        if( arr[mid] >= target )
            r = mid - 1;
        else
            l = mid;
    }

    // 如果该索引+1就是target本身, 该索引+1即为返回值
    if( l + 1 < n && arr[l+1] == target )
        return l + 1;
    printf("Floor end: l=%d r=%d arr[%d]=%d\n",l,r,l,arr[l] );
    // 否则, 该索引即为返回值
    return l;
}


int ceil(int arr[],int len,int target){
	//在长度为len的数组arr中，查找元素target。若target>arr[len-1]返回-1;
	//找到，返回最后一个位置，找不到，返回比target大的第一个元素的位置
	if(target<arr[0]) return 0;
	else if(target>arr[len-1]) return -1;
	//在arr[l...r]前闭后闭的区间
	int l=0,r=len-1;
	while(l<r){//终止条件是l>=r
		int mid=l+(r-l)/2;
		printf("l=%d mid=%d r=%d arr[mid]=%d\n",l,mid,r,arr[mid] );
		if(target<arr[mid])//在左边查找
			r=mid-1;//此时等于在arr[l...mid)内查找
		else//等于也在右边查
			l=mid+1;//此时等于在arr[mid+1...r)内查找
	}
	//此时l=r指向第一个大于target的数
	printf("Ceil end: l=%d r=%d arr[%d]=%d\n",l,r,l,arr[l] );
	if(arr[l-1]==target)return l-1;
	else return l;
}

int main(){
	int len=20;
	srand(time(NULL));
	int * arr1=generateRandomArray(len,1,10);
	sort(arr1,arr1+len);
	printArray(arr1,len);
	int n;
	char c;
	while(1){
		printf("Please enter number you want to find(-1 to exit):");
		scanf("%d",&n);
		getchar();
		if(n==-1)break;
		
		int ans=floor_xcm(arr1,len,n);
		printf("XCM floor of %d is: %d\n\n",n,ans );
		ans=floor_lyb(arr1,len,n);
		printf("LYB floor of %d is: %d\n\n",n,ans );
		ans=floor_lrj(arr1,len,n);
		printf("LRJ floor of %d is: %d\n\n",n,ans );
	}
	return 0;
}