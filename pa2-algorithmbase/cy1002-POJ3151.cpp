/*
程序设计与算法（二）第十周测验 2:Pots POJ3151
write by xucaimao,2018-01-20 20:18 AC at 2018-01-20 22:56:16
需要定义六种操作:
0-fill(1),1-fill(2),2-drop(1),3-drop(2),4-pour(1,2),5-pour(2,1)
重点是如何判重，不能回到父节点的状态
把va看做是一个十六位二进制数的高八位，vb看做低八位
*/

#include<cstdio>
#include<vector>
#include <cstring>
using namespace std;
struct Node{
	char va,vb;//范围[1..100]
	int f;//记录父节点在队列中的下标，-1说明结束
	int op;//记录从父节点到本节点所执行的操作，0~5，-1表示结束
	Node(int vva,int vvb,int ff,int oo):va(vva),vb(vvb),f(ff),op(oo){};
	Node(){};
};
char opstr[6][15]={"FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};
const int maxn=10000000;
bool vis[65536];
Node q[maxn];
int pfront=0,pend=0;//定义队头队尾,二者重合时队为空
int VA,VB,VC;

void bfs(){
	bool haveans=0;
	q[pend++]=Node(0,0,-1,-1);//两个杯子都是空,-1表示没有前驱节点了
	vis[0]=1;
	while( pfront!=pend ){
		Node e=q[pfront];//取队首元素
		//printf("va= %d vb= %d\n",e.va,e.vb);
		if(e.va==VC || e.vb==VC){
			//printf("have answer!!!\n");
			haveans=1;
			break;
		}

		for(int fi=0;fi<6;fi++){//枚举六种操作
			int ok=0;
			int nexta=e.va;
			int nextb=e.vb;
			switch(fi){
				case 0://A倒满
					if(nexta==VA)break;
					nexta=VA;
					ok=1;
					break;
				case 1://B倒满
					if(nextb==VB)break;
					nextb=VB;
					ok=1;
					break;
				case 2://A倒空
					nexta=0;ok=1;
					break;
				case 3://B倒空
					nextb=0;ok=1;
					break;
				case 4://A->B
					if(nexta==0)break;
					if(nexta>= VB-nextb ){
						nexta-=(VB-nextb);//开始时这两步的顺序颠倒了，调试了好久，晕死
						nextb=VB;
					}
					else{
						nextb+=nexta;
						nexta=0;
					}
					ok=1;
					break;
				case 5://B->A
					if(nextb==0)break;
					if(nextb>= VA-nexta){//B倒不空
						nextb-=(VA-nexta);//开始时这两步的顺序颠倒了，调试了好久，晕死
						nexta=VA;	
					}
					else{//B倒空
						nexta+=nextb;
						nextb=0;
					}
					ok=1;
			}
			if(ok){
				int stat= ((int)nexta << 8) + nextb;
				if( !vis[stat]){
					//printf("add level %3d: va= %d vb= %d func= %s\n",pfront,nexta,nextb,opstr[fi]);
					q[pend++]=Node(nexta,nextb,pfront,fi);
					vis[stat]=1;
				}
			}
			
		}
		pfront++;//出队
	}

	if(!haveans)
		printf("impossible\n");
	else{
		vector<int> ans;//保存各个节点在队列中的下标
		int p=pfront;
		while(p!=-1){
			ans.push_back(p);
			//printf("add: %d\n",p);
			p=q[p].f;//找到父节点
		}
		int len=ans.size();
		printf("%d\n",len-1 );//减去初始节点(0,0,-1,-1)
		for(int i=len-2;i>=0;i--)
			printf("%s\n",opstr[ q[ ans[i] ].op ] );
	}
}

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&VA,&VB,&VC);
	bfs();
	return 0;
}
	