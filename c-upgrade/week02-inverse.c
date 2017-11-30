/*中国大学MOOC《C语言程序设计进阶》第四周编程题 
write by xucaimao at 2017-11-28-23:20
采用内存块的概念进行编程
一个数组，存放各个内存块的首指针，可以避免老师课上示例中，数据的拷贝过程
32000Kb=32768000=327.68万
*/

#include<stdio.h>
#include<stdlib.h>
#define blocksize 10000
#define maxblock 400
typedef struct
{
	int *array[maxblock];
	int size;//当前数组最大可以容纳的元素个数
	int currentp;//记录当前有效的内存块指针的位置
}Array;

Array array_creat(){
	//返回一个实例(传值)
	Array a;
	a.size=blocksize;
	a.array[0]=(int*)malloc(sizeof(int)*blocksize);
	a.currentp=0;
	return a;
}


void array_free(Array *a){
	while(a->currentp>=0){
		free(a->array[a->currentp]);
		a->array[a->currentp]=NULL;
		a->currentp--;
	}
}

int array_size(const Array *a){
	//返回数组的最大容量
	return a->size;
}

int* array_at(Array *a,int index){
	//返回index位置的指针，返回指针的目的是为了给此单元赋值
	if(index>=a->size){//超出数组容量，需要扩容
		//printf("array size incress!\n");
		a->array[++(a->currentp)]=(int*)malloc(sizeof(int)*blocksize);
		a->size+=blocksize;
	}
	return a->array[index/blocksize]+index%blocksize;
}

int main(){
	Array a=array_creat();
	int cnt=0,n;
	while(1){
		scanf("%d",&n);
		if(n==-1)break;
		*array_at(&a,cnt)=n;
		cnt++;
	}
	for(int i=cnt-1;i>=0;i--)
		printf("%d ",*array_at(&a,i) );
	printf("\n");
	array_free(&a);
	return 0;
}