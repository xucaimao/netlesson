/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 10-排序5 PAT Judge
 * wirte by xucaimao,2018-11-04
 * 回溯法
 * */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int maxN=10000+10;
int maxScore[6];

class PAT{
private:
    char id[6]={'9','9','9','9','9','\0'};
    //用于存放每道题的最高得分，下标从1开始，初始值应当比-1（编译未通过）小
    int score[6];
    int totalScore;
    int perfectlySolved;    //满分题目的数量
public:
    PAT(){
        totalScore=0;
        for(int i=1;i<6;i++){
            score[i]=-2;
            totalScore+=score[i];
        }
        perfectlySolved=0;
    }
    bool operator<(const PAT & b){
        //总分大的排名靠前
        //总分相等，看哪一个perfectlySolve大
        //perfectlySolve相等，看哪一个id小
        if(totalScore>b.totalScore)return true;
        else if(totalScore==b.totalScore){
            if(perfectlySolved>b.perfectlySolved) return true;
            else if(perfectlySolved==b.perfectlySolved)
                return strcmp(id,b.id)<0;
            else return false;
        }
        else return false;
    }
    void setId(char s[]){
        for(int i=0;s[i]!='\0';i++)
            id[i]=s[i];
    }
    void setScore(char s[],int pId,int sc){
        setId(s);
        if(score[pId]<sc)
            score[pId]=sc;
        perfectlySolved=0;
        for(int i=1;i<6;i++)
            if(score[i]==maxScore[i]) perfectlySolved++;
    }

};

PAT data[maxN];

int str2int(char s[]){
    int ans=0;
    for(int i=0;s[i]!='\0';i++)
        ans=ans*10+s[i]-'0';
    return ans;
}

int main(){
    int N,K,M;
    char userId[6];
    int  problemId,score;

    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    scanf("%d %d %d",&N,&K,&M);
    for(int k=1;k<=K;k++)
        scanf("%d",&maxScore[k]);    //读入最高分
    for(int i=1;i<=M;i++){
        scanf("%s %d %d",userId,&problemId,&score);
        data[str2int(userId)].setScore(userId,problemId,score);
    }
    sort(data+1,data+N+1);
    for(int i=1;i<=N;i++){

    }
    return 0;
}