//
// Created by xcm on 2020/5/7.
//

#ifndef DS_LYB_SORTTESTHELPER_H
#define DS_LYB_SORTTESTHELPER_H

#include <ctime>
using namespace std;

namespace SortTestHelper{
    int* generateRandomArray(int n,int left,int right){
        int* arr=new int[n];
        srand(time(NULL));
        for(int i=0;i<n;i++)
            arr[i]=rand()%(right-left+1) + left;
        return arr;
    }

    int* copyIntArray(int arr[],int n){
       int* newArr=new int[n];
       for(int i=0;i<n;i++)
           newArr[i]=arr[i];
        return newArr;
    }

    int* generateNearlyOrderArray(int n,int swapTime){
        int* arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=i;
        srand(time(NULL));
        for(int i=0;i<swapTime;i++){
            int posx=rand()%n;
            int posy=rand()%n;
            std::swap(arr[posx],arr[posy]);
        }
        return arr;
    }

    template <typename T>
    void printArray(T arr[],int n){
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }

    template <typename T>
    bool isSorted(T arr[],int n){
        for(int i=0;i<n-1;i++)
            if(arr[i]>arr[i+1]) return false;
        return true;
    }

    template <typename T>
    void testSort(string sortName, void(*sort)(T[],int),T arr[],int n ){
        clock_t startTime=clock();
        sort(arr,n);
        clock_t endTime=clock();
        assert(isSorted(arr,n));
        double runTime=double (endTime-startTime)/double (CLOCKS_PER_SEC);
        cout<< sortName <<" : "<<runTime<<" s"<<endl;
        return;
    }


}
#endif //DS_LYB_SORTTESTHELPER_H
