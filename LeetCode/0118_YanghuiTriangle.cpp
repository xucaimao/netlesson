// LeetCode
// 118.杨辉三角形
// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
// write by xucaimao 2018-11-28

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > ans;
    //cout<<"ans size is : "<<ans.size()<<endl;
    for(int r=0;r<numRows;r++){
        ans.push_back(vector<int>());
        for(int c=0;c<=r;c++){
            if(c==0 || c==r)
                ans[r].push_back(1);
            else
                ans[r].push_back(ans[r-1][c-1]+ans[r-1][c]);
        }
    }
    return ans;
}

int mymain() {
    int N=5;
    vector<vector<int> > a=generate(N);
    for(int r=0;r<a.size();r++){
        for(int c=0;c<a[r].size();c++)
            cout<<a[r][c]<<" ";
        cout<<endl;
    }
    return 0;

}