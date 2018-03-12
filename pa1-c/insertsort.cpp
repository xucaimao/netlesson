#include <cstdio>

void insertsort(int arr[],int size){
	int v;
	for(int i=1;i<size;i++){
		v=arr[i];
		int j;
		for(j=i;j>=0 && arr[j-1]>v;j--){
			arr[j]=arr[j-1];
		}
		arr[j]=v;
	}
}

int main(){
	int a[]={8,3,1,5,6,4,9,2,7,0};
	insertsort(a,10);
	for(int i=0;i<10;i++)
		printf("%d ",a[i] );
	printf("\n");
	return 0;
}