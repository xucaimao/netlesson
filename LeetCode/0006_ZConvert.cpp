// LeetCode
// 6.Z字形变换
// write by xucaimao 2018-11-08

#include <iostream>
#include <string>
using namespace std;

string convert(string s, int numRows) {
    if(numRows==1)return s;
    int len=s.size();
    char * arr=new char[len*numRows]{' '};//numRows行，len列
    int i=0,r=0,c=0;
    int dir=1;
    while(i<len){           //i控制总的字符数
        arr[r*len+c]=s[i];
        r+=dir;
        if(r<0){
            dir*=-1;        //控制行号加或减
            r=1;
        }
        else if(r==numRows){
            dir*=-1;
            r=numRows-2;
        }
        if(dir==-1)c++;
        i++;
    }
    string ans;
    for(r=0;r<numRows;r++){
        for(c=0;c<len;c++){
            if(arr[r*len+c]!='\0') ans.push_back(arr[r*len+c]);
            cout<<arr[r*len+c]<<" ";
        }
        cout<<endl;
    }
    delete []arr;
    return ans;
}

int mymain() {
    string s="PAYPALISHIRING";
    string ans=convert(s,4);
    cout<<ans;
    return 0;

}