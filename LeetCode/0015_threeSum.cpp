//
// Created by xucaimao on 2020/4/16.
//
using namespace std;
#include <vector>
#include <algorithm>

vector<vector<int>> threeSum(vector<int>& nums) {
    vector< vector<int> > ansVec;
    int len=nums.size();
    if(len<3)return ansVec;
    sort(nums.begin(),nums.end());
    for(int i=0;i<len;++i){
        if(i>0 && nums[i]==nums[i-1])
            continue;                                   //忽略重复元素
        int targ=-nums[i];
        int j=i+1;
        int k=len-1;
        while(j<k){
            if(nums[j]+nums[k] == targ){
                vector<int> ans;
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                ans.push_back(nums[k]);
                ansVec.push_back(ans);
                ++j;
                --k;
                while( j<len && nums[j]==nums[j-1] ) ++j; //忽略重复元素
                while( k>j && nums[k]==nums[k+1] ) --k;
            }
            else if(nums[j]+nums[k] < targ) ++j;
            else --k;
        }
    }
    return ansVec;
}

