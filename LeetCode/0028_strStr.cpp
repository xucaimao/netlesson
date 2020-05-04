//
// Created by xucaimao on 2020/4/17.
//
#include <string>
using namespace std;

//暴力算法，对于有很多重复元素的样例，效率就比较低
int strStr(string haystack, string needle) {
    int lh=haystack.size();
    int ln=needle.size();
    if( ln==0 ) return 0;
    if( lh<ln ) return -1;
    for(int p=0; p+ln <=lh; ++p ){
        int i=0;            //point to needle
        for(;i<ln;++i){
            if(haystack[p+i] != needle[i])
                break;
        }
        if(i==ln) return p;
    }
    return -1;
}

int mymain(){
    string s1="hello";
    string s2="as";
    int ans=strStr(s1,s2);
    cout<<ans<<endl;
    return 0;
}