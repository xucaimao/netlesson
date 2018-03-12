/*
中国大学MOOC-陈越、何钦铭-数据结构-2018春 
第一周 练习3 二分查找
write by xucaimao,2018-03-09 20:30
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};
typedef struct LNode * List;/*List是指针变量*/

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
List ReadInput(){
	int i,n,a;
	static struct LNode La;
	/*List La=(List)malloc(sizeof(LNode));*/
	scanf("%d", &n);
	for(i=1;i<=n;i++)
		scanf("%d", &La.Data[i]);
	La.Last=n;
	return &La;
}

Position BinarySearch( List L, ElementType X ){
	int l=1,r=L->Last,mid;
 
 	while(l<=r){
    	mid=l+(r-l)/2;
    	if(L->Data[mid]>X)
      		r=mid-1;
    	else if(L->Data[mid]<X)
      		l=mid+1;
    	else
      		return mid;
  	}
  	return NotFound;
}
