/*中国大学MOOC-陈越、何钦铭-数据结构-2017秋
 * 07-图4 哈利·波特的考试 （25 分）
 * wirte by xucaimao,2018-10-18
 * Floyd算法，又称插点法
 * */

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
//定义无穷大（动物总数不超过100，咒语长度不超过100，最大权值100*100=10000）
const int INFINITY=65535;
const int maxN=110;
int G[maxN][maxN];  //无向有权图
int D[maxN][maxN];
int NumOfAnimal;    //顶点数
int Edge;           //边的数量

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    //对于用邻接矩阵表示的有权图，两点之间没有边，权重设为无穷大
    for(int i=0;i<maxN;i++)
        for(int j=0;j<maxN;j++)
            G[i][j]=INFINITY;

    scanf("%d %d",&NumOfAnimal,&Edge);
    for(int i=0;i<Edge;i++){
        int u,v,weight;
        scanf("%d %d %d",&u,&v,&weight);
        G[u][v]=weight;
        G[v][u]=weight;
    }

    //Floyd
    for(int i=1;i<=NumOfAnimal;i++)
        for(int j=1; j<=NumOfAnimal;j++){
            //严格按照定义初始化，后面的程序可以简化
            if(i==j)D[i][j]=0;
            else D[i][j]=G[i][j];
        }

    for(int k=1;k<=NumOfAnimal;k++)
        for(int i=1;i<=NumOfAnimal;i++)
            for(int j=1; j<=NumOfAnimal;j++){
                //在点(i,j)之间插入一个点k
                //如果不定义D[i][i]=0,这里要增加判断,当i==j时不执行操作
                D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
            }

//    for(int i=1;i<=NumOfAnimal;i++){
//        for(int j=1;j<=NumOfAnimal;j++)
//            printf("%6d",D[i][j]);
//        printf("\n");
//    }

    //FindMinOfMax
    int animalNum=0;
    int minDist=INFINITY;
    for(int i=1;i<=NumOfAnimal;i++){
        //找出一个动物变为其它动物的咒语的最大长度
        int maxOfOne=0;
        for(int j=1;j<=NumOfAnimal;j++){
            //如果不定义D[i][i]=0,这里要改成(i!=j && D[i][j]>maxOfOne)
            if(D[i][j]>maxOfOne){
                maxOfOne=D[i][j];
            }
        }
        if(maxOfOne<minDist){
            minDist=maxOfOne;
            animalNum=i;
        }
    }

    if(minDist==INFINITY)
        printf("0\n");
    else printf("%d %d\n",animalNum,minDist);

    return 0;
}
