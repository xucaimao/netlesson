/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 01-复杂度3 二分查找
 * write by xucaimao,2018-03-12
 *
 * */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last;
};
typedef struct LNode * List;

List ReadInput();
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

List ReadInput(){
	int i,n,a;
	static struct LNode La; //这里采用静态变量，否则此函数结束后变量就会失效
	scanf("%d", &n);
	for(i=1;i<=n;i++)
		scanf("%d", &La.Data[i]);
	La.Last=n;
	return &La;	//返回指针
}

Position BinarySearch( List L, ElementType X ){
	int l=1,r=L->Last,mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(L->Data[mid]==X)
			return mid;
		else if(L->Data[mid]<X)
			l=mid+1;
		else
			r=mid-1;
	}
	return NotFound;
}
