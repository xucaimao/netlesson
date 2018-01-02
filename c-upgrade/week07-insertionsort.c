/*中国大学MOOC《C语言程序设计进阶》第七周编程题 
write by xucaimao at 2017-12-14-22:40
采用插入排序
*/
#include <stdio.h>
const int maxn=100010;

int data[maxn];

void insertionSort(int arr[],int len){
	for(int i=1;i<len;i++){
		int j;
		int v=arr[i];
		for(j=i;j>0 && arr[j-1]>v;j--)
			arr[j]=arr[j-1];
		arr[j]=v;
	}
}

int main(){
	int n,t;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	insertionSort(data,n);
	for(int i=0;i<n;i++)
		printf("%d ",data[i] );
	printf("\n");
	return 0;
}