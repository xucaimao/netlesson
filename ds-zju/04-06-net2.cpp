#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int arr[1005], rearr[1005];
int compare( const void* a, const void* b ){
    return *(int*)a - *(int*)b;
}
int getLeftLength(int n){    //利用二叉树的性质：满二叉树第i层有 2^(i-1) 个结点， 高为h的满二叉树有 2^h - 1 个结点（从1开始）
    double h, x, L, t;
    h = (double)(int)( log((double)n+1) / log(2.0) );
    //h = floor( log((double)n+1) / log(2.0) );
    x = n - pow(2.0, h) + 1 ;
    t = pow(2.0, h - 1.0);
    x = x < t ? x : t;
    L = t - 1 + x;
    return (int)L;
}
void solve( int left, int right, int root ){
    //初始调用： solve(0, n-1, 0);
    int n, L, leftRoot, rightRoot;
    n = right - left + 1;			//数组中的总个数
    if(n == 0) return ;				//递归退出的条件
    L = getLeftLength(n);			//计算出左子树的结点
    rearr[root] = arr[left + L];	//将新的根结点放入新的数组
    leftRoot = root * 2 + 1;		//左孩子
    rightRoot = leftRoot + 1;		//右孩子
    solve(left, left + L - 1, leftRoot);
    solve(left + L + 1, right, rightRoot);
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    solve(0, n-1, 0);
    for(int i = 0; i < n; i++){
        if( i != 0 ) printf(" ");
        printf("%d", rearr[i]);
    }
    system("pause");
    return 0;
}
