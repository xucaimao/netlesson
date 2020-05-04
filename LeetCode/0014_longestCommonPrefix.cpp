//
// Created by xucaimao on 2020/4/17.
//
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int len=strs.size();
    if(len==0) return "";
    //把第一个string作为prefix
    //是否可以优化取最短的string,即先把strs按元素的长短排序
    string prefix = strs[0];
    for(int i=1; i<len; ++i){
        string target=strs[i];
        //在target中查找prefix，如果找不到，就把prefix从后往前截短一个字符
        //只有返回值为0，才说明prefix是target的前缀
        while( target.find(prefix)!=0 && prefix.size()>0 )
            prefix.erase(prefix.size()-1);
    }
    return prefix;
}

int mymain() {
    vector<string> s={"flower","flow","flight"};
    string ans;
    ans=longestCommonPrefix(s);
    cout<<ans<<endl;
    return 0;
}
