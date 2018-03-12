/*
�й���ѧMOOC-��Խ��������-���ݽṹ-2018�� 
��һ�� ��ϰ3 ���ֲ���
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
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};
typedef struct LNode * List;/*List��ָ�����*/

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
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

/* ��Ĵ��뽫��Ƕ������ */
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
