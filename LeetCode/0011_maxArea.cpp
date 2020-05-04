//
// Created by xucaimao on 2020/4/19.
//
/*
 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，
 垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器
 可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */
#include <vector>
using namespace std;
//暴力方法，会超时
int maxArea1(vector<int>& height) {
    int area=0;
    int len=height.size();
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            int t=min(height[i],height[j]) * (j-i);
            if( t >area ) area=t;
        }
    }
    return area;
}

int maxArea(vector<int>& height) {
    int left=0;
    int right=height.size()-1;
    int area=0;
    while(left<right){
        int t=min(height[left],height[right]) * (right-left);
        if(t>area) area=t;
        if(height[left]<height[right]) ++left;
        else --right;
    }
    return area;
}

int mymain(){
    vector<int> a={1,8,6,2,5,4,8,3,7};
    int ans=maxArea(a);
    cout<<ans<<endl;
    return 0;
}