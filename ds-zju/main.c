#include <stdio.h>
#include <stdlib.h>
#define maxSize 10010
typedef int ElementType;
typedef int SetName;    //用根节点的下标作为集合的名字
ElementType Set[maxSize];//集合存储结构
void initSet(int n){ //电脑编号从1~n
    for(int i=1;i<=n;i++)
        Set[i]=-1;  //Set[i]<0表示i是数的根，其绝对值表示以i为根的树中的节点数
}

SetName Find(ElementType X){
    int root=X;
    for(;Set[root]>0;root=Set[root]);//找到根节点
    for(;Set[X]>0;X=Set[X])
        Set[X]=root;
    return root;
}

void Union(SetName root1,SetName root2){
    //root1和root2是不同集合的根节点
    if(Set[root1]<=Set[root2]){ //root1的数节点数大于或等于root2
        int n=Set[root2];//记录以root2为根的树的节点数量
        Set[root2]=root1;//root2接入root1为根的树
        Set[root1]+=n;
    }
    else{   //root1节点数小于root2
        int n=Set[root1];//记录以root1为根的树的节点数量
        Set[root1]=root2;//root1接入root2为根的树
        Set[root2]+=n;
    }

}
//下面的程序没有采用路径压缩，运行正确，但是会超时
//对以root1和root2为根的两棵树，执行合并操作
void Union1(SetName root1,SetName root2){
    int n=Set[root2];//记录以root2为根的树的节点数量
    Set[root2]=root1;//root2接入root1为根的树
    Set[root1]+=n;
}


int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    int N;
    scanf("%d",&N);
    getchar();
    initSet(N);
    char ch;
    while( scanf("%c",&ch) && (ch!='S') ){
        int a,b;
        scanf("%d %d",&a,&b);
        getchar();
        int roota=Find(a);  //找到两个节点所在树的根
        int rootb=Find(b);
//        printf("the root of %d is: %d\n",a,roota);
//        printf("the root of %d is: %d\n",b,rootb);
        switch(ch){
            case 'C':
                if( roota==rootb ) printf("yes\n");
                else printf("no\n");
                break;
            case 'I':
                if( roota!=rootb )//不是同一棵树才执行union操作
                    Union(roota,rootb);

                break;
        }
    }
    int setNum=0;
    for(int i=1;i<=N;i++){
        if(Set[i]<0)setNum++;
    }
    if(setNum==1)printf("The network is connected.\n");
    else printf("There are %d components.",setNum);
    return 0;
}
