/*
关于二分查找的floor与ceil,
write by liurujia
*/
#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
int floor(T arr[],int n,T target){
    int l=0;r=n;
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

int main(){

    int a[] = {1, 1, 1, 2, 2, 2, 2, 2, 4, 4, 5, 5, 7, 7, 9,12};
    int n = sizeof(a)/sizeof(int);
    for( int i = 0 ; i <= 8 ; i ++ ){

        int floorIndex = floor(a, n, i);
        cout<<"the floor index of "<<i<<" is "<<floorIndex<<".";
        if( floorIndex >= 0 && floorIndex < n )
            cout<<"The value is "<<a[floorIndex]<<".";
        cout<<endl;

        // int ceilIndex = ceil(a, sizeof(a)/sizeof(int), i);
        // cout<<"the ceil index of "<<i<<" is "<<ceilIndex<<".";
        // if( ceilIndex >= 0 && ceilIndex < n )
        //     cout<<"The value is "<<a[ceilIndex]<<".";
        // cout<<endl;

        cout<<endl;
    }

    return 0;
}