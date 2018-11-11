// LeetCode
// 1.两数相加
// write by xucaimao 2018-11-08

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>ans(2);
    int len=nums.size();
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++)
            if(nums[i]+nums[j]==target){
                ans[0]=i;
                ans[1]=j;
                return ans;
            }
    }
    return ans;
}

int main() {
    freopen("/Users/xcm/xcmprogram/netlesson/LeetCode/in.txt","r",stdin);
    int n,tar;
    cin>>n>>tar;
    vector<int> data(n);
    for(int i=0;i<n;i++)
        cin>>data[i];
    vector<int> ans=twoSum(data,tar);
    cout<<"["<<ans[0]<<","<<ans[1]<<"]"<<endl;
    return 0;
}