#include <cstdio>

template<typename T>
void insert_sort(T arr[],int size){
	for(int i=1;i<size;i++){
		T t=arr[i];
		int j;
		for(j=i;j>0 && arr[j-1]>t;j--)
				arr[j]=arr[j-1];
		arr[j]=t;
	}	
}

int main(){
	int d[]={10,8,9,5,3,1,2,4,6,7};
	insert_sort(d,10);
	for(int i=0;i<10;i++)
		printf("%d ",d[i]);
	printf("\n");
	return 0;
}